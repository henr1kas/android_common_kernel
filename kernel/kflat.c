#include <linux/atomic.h>
#include <linux/compiler.h>
#include <linux/errno.h>
#include <linux/export.h>
#include <linux/types.h>
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/preempt.h>
#include <linux/printk.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/vmalloc.h>
#include <linux/debugfs.h>
#include <linux/uaccess.h>
#include <linux/kflat.h>
#include <linux/interval_tree_generic.h>
#include <linux/random.h>

int kflat_ioctl_test(struct kflat *kflat, unsigned int cmd, unsigned long arg);

static void kflat_get(struct kflat *kflat)
{
	atomic_inc(&kflat->refcount);
}

static void kflat_put(struct kflat *kflat)
{
	if (atomic_dec_and_test(&kflat->refcount)) {
		vfree(kflat->area);
		kfree(kflat);
	}
}

static int kflat_open(struct inode *inode, struct file *filep)
{
	struct kflat *kflat;

	kflat = kzalloc(sizeof(*kflat), GFP_KERNEL);
	if (!kflat)
		return -ENOMEM;
	atomic_set(&kflat->refcount, 1);
	spin_lock_init(&kflat->lock);
	kflat->FLCTRL.fixup_set_root = RB_ROOT_CACHED;
	kflat->FLCTRL.imap_root = RB_ROOT_CACHED;
	filep->private_data = kflat;
	return nonseekable_open(inode, filep);
}

void kflat_task_init(struct task_struct *t)
{
	WRITE_ONCE(t->kflat_mode, KFLAT_MODE_ENABLED);
	barrier();
	t->kflat_size = 0;
	t->kflat_area = 0;
	t->kflat = 0;
}

void flatten_set_debug_flag(struct kflat* kflat, int flag);

void kflat_task_exit(struct task_struct *t)
{
	struct kflat *kflat;

	kflat = t->kflat;
	if (kflat == 0)
		return;
	spin_lock(&kflat->lock);
	if (WARN_ON(kflat->t != t)) {
		spin_unlock(&kflat->lock);
		return;
	}
	/* Just to not leave dangling references behind. */
	kflat_task_init(t);
	kflat->t = NULL;
	spin_unlock(&kflat->lock);
	kflat_put(kflat);
}

static int kflat_ioctl_locked(struct kflat *kflat, unsigned int cmd,
			     unsigned long arg)
{
	struct task_struct *t;
	unsigned long size, unused;
	long filter_pid;

	switch (cmd) {
	case KFLAT_GLOBAL_ENABLE:
		if (kflat_g.mode != KFLAT_MODE_DISABLED) {
			return -EBUSY;
		}
		if (kflat_g_p) {
			return -EBUSY;
		}
		kflat_g.size = arg;
		kflat_g.mode = KFLAT_MODE_ENABLED;
		kflat_g.filter_pid = 0;
		kflat_g_filter_pid_cache = 0;
		kflat_g_p = &kflat_g;
		return 0;
	case KFLAT_GLOBAL_DISABLE:
		memset(&kflat_g,0,sizeof(struct kflat));
		kflat_g_p = 0;
		return 0;
	case KFLAT_LINEAR_MEMORY_REALLOC:
#if LINEAR_MEMORY_ALLOCATOR>0
		if (kflat_g.mode != KFLAT_MODE_ENABLED) {
			return -EBUSY;
		}
		if (!kflat_g_p) {
			return -EBUSY;
		}
		return kflat_linear_memory_realloc(kflat_g_p,arg);
#endif
	case KFLAT_SET_FILTER_PID:
		if (kflat_g.mode != KFLAT_MODE_ENABLED) {
			return -EBUSY;
		}
		if (!kflat_g_p) {
			return -EBUSY;
		}
		filter_pid = (long)arg;
		kflat_g.filter_pid = filter_pid;
		kflat_g_filter_pid_cache = filter_pid;
		if (kflat_g.FLCTRL.debug_flag&1) {
			flat_infos("Filter PID was set to %d\n",kflat_g.filter_pid);
		}
		return 0;
	case KFLAT_INIT:
		if (kflat->mode != KFLAT_MODE_DISABLED)
			return -EBUSY;
		size = arg;
		if (size == 0)
			return -EINVAL;
		kflat->size = size;
		kflat->mode = KFLAT_MODE_ENABLED;
		return 0;
	case KFLAT_PROC_ENABLE:
		/*
		 * Enable coverage for the current task.
		 * At this point user must have been enabled trace mode,
		 * and mmapped the file. Coverage collection is disabled only
		 * at task exit or voluntary by KCOV_DISABLE. After that it can
		 * be enabled for another task.
		 */
		unused = arg;
		if (unused != 0 || kflat->mode == KFLAT_MODE_DISABLED ||
		    kflat->area == 0)
			return -EINVAL;
		t = current;
		if (kflat->t != 0 || t->kflat != 0)
			return -EBUSY;
		/* Cache in task struct for performance. */
		t->kflat_size = kflat->size;
		t->kflat_area = kflat->area;
		/* See comment in __sanitizer_cov_trace_pc(). */
		barrier();
		WRITE_ONCE(t->kflat_mode, kflat->mode);
		t->kflat = kflat;
		kflat->t = t;
		/* This is put either in kcov_task_exit() or in KCOV_DISABLE. */
		kflat_get(kflat);
		return 0;
	case KFLAT_PROC_DISABLE:
		/* Disable coverage for the current task. */
		unused = arg;
		if (unused != 0 || current->kflat != kflat)
			return -EINVAL;
		t = current;
		if (WARN_ON(kflat->t != t))
			return -EINVAL;
		kflat_task_init(t);
		kflat->t = 0;
		kflat_put(kflat);
		return 0;
	case KFLAT_TEST:
		if ((kflat_g.mode == KFLAT_MODE_ENABLED) && (kflat_g_p)) {
			kflat_ioctl_test(kflat_g_p,cmd,arg);
		}
		else {
			kflat_ioctl_test(kflat,cmd,arg);
		}
		return 0;
	case KFLAT_SET_FLAG:
		if ((kflat_g.mode == KFLAT_MODE_ENABLED) && (kflat_g_p)) {
			flatten_set_debug_flag(kflat,arg&0x01);
			return 0;
		}
		else {
			return -EINVAL;
		}
	default:
		return -ENOTTY;
	}
}

static long kflat_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
	struct kflat *kflat;
	int res;

	kflat = filep->private_data;
	if (cmd!=KFLAT_TEST) {
		spin_lock(&kflat->lock);
	}
	res = kflat_ioctl_locked(kflat, cmd, arg);
	if (cmd!=KFLAT_TEST) {
		spin_unlock(&kflat->lock);
	}
	return res;
}

static int kflat_mmap(struct file *filep, struct vm_area_struct *vma)
{
	int res = 0;
	void *area;
	struct kflat *kflat;
	unsigned long size, off;
	struct page *page;

	area = vmalloc_user(vma->vm_end - vma->vm_start);
	if (!area)
		return -ENOMEM;

	//flat_infos("kflat_mmap: %lx\n",area);

	if (kflat_g_p && kflat_g_p->mode == KFLAT_MODE_ENABLED) {
		spin_lock(&kflat_g_p->lock);
		size = kflat_g_p->size;
		//flat_infos("mmap size: %zu\n",size);
		if (!kflat_g_p->area) {
			kflat_g_p->area = area;
			vma->vm_flags |= VM_DONTEXPAND;
			spin_unlock(&kflat_g_p->lock);
			for (off = 0; off < size; off += PAGE_SIZE) {
				page = vmalloc_to_page(kflat_g_p->area + off);
				if (vm_insert_page(vma, vma->vm_start + off, page))
					WARN_ONCE(1, "vm_insert_page() failed");
			}
			//flat_infos("mmap return: %d\n",0);
			return 0;
		}
		spin_unlock(&kflat_g_p->lock);
		vfree(area);
		return -EINVAL;
	}

	kflat = vma->vm_file->private_data;
	spin_lock(&kflat->lock);
	size = kflat->size;
	if (kflat->mode == KFLAT_MODE_DISABLED	 || vma->vm_pgoff != 0 ||
	    vma->vm_end - vma->vm_start != size) {
		res = -EINVAL;
		goto exit;
	}
	if (!kflat->area) {
		kflat->area = area;
		vma->vm_flags |= VM_DONTEXPAND;
		spin_unlock(&kflat->lock);
		for (off = 0; off < size; off += PAGE_SIZE) {
			page = vmalloc_to_page(kflat->area + off);
			if (vm_insert_page(vma, vma->vm_start + off, page))
				WARN_ONCE(1, "vm_insert_page() failed");
		}
		return 0;
	}
exit:
	spin_unlock(&kflat->lock);
	vfree(area);
	return res;
}

static int kflat_close(struct inode *inode, struct file *filep)
{
	kflat_put(filep->private_data);
	return 0;
}

static const struct file_operations kflat_fops = {
	.open		= kflat_open,
	.unlocked_ioctl	= kflat_ioctl,
	.compat_ioctl	= kflat_ioctl,
	.mmap		= kflat_mmap,
	.release        = kflat_close,
};

static int __init kflat_init(void)
{
	if (!debugfs_create_file_unsafe("kflat", 0600, NULL, NULL, &kflat_fops)) {
		pr_err("failed to create kflat in debugfs\n");
		return -ENOMEM;
	}
	return 0;
}

device_initcall(kflat_init);

#ifndef AOT_AOT_H
#define AOT_AOT_H

#include "aot_replacements.h"

#include "aot_log.h"

void* malloc (size_t size);
void* calloc (size_t num, size_t size);
void free(void *ptr);

/* ------------------------------------------------ */
/* AOT generated this file                          */
/* Copyright Samsung Electronics                    */
/* ------------------------------------------------ */

/* Type decls */
struct list_head;
struct hlist_head;
struct file;
struct rb_root;
struct linux_binfmt;
struct ldt_struct;
struct task_struct;
struct kioctx_table;
struct user_namespace;
struct xol_area;
struct anon_vma;
struct vm_operations_struct;
struct vm_userfaultfd_ctx;
struct sock;
struct seq_file;
struct kernfs_elem_symlink;
struct poll_table_struct;
struct kernfs_open_node;
struct kernfs_iattrs;
struct module_param_attrs;
struct exception_table_entry;
struct mod_arch_specific;
struct module_sect_attrs;
struct module_notes_attrs;
struct workqueue_struct;
struct static_key_mod;
struct trace_event_call;
struct trace_eval_map;
struct pollfd;
struct address_space;
struct kmem_cache;
struct dev_pagemap;
struct mem_cgroup;
struct perf_event;
struct lock_class_key;
struct uprobe;
struct llist_node;
struct device;
struct device_node;
struct fs_context;
struct vfsmount;
struct posix_acl;
struct fs_parameter_description;
struct writeback_control;
struct kstatfs;
struct iov_iter;
struct sched_class;
struct task_group;
struct rcu_node;
struct proc_ns_operations;
struct key_user;
struct key_type;
struct assoc_array_ptr;
struct nameidata;
struct fs_struct;
struct files_struct;
struct uts_namespace;
struct ipc_namespace;
struct mnt_namespace;
struct net;
struct swap_info_struct;
struct u64_stats_sync;
struct bpf_prog;
struct bpf_cgroup_storage_map;
struct cgroup_taskset;
struct tty_struct;
struct tty_audit_buf;
struct audit_context;
struct seccomp_filter;
struct wake_q_node;
struct rt_mutex_waiter;
struct bio_list;
struct blk_plug;
struct reclaim_state;
struct backing_dev_info;
struct request_queue;
struct capture_control;
struct robust_list_head;
struct compat_robust_list_head;
struct futex_pi_state;
struct device_private;
struct of_device_id;
struct acpi_device_id;
struct driver_private;
struct iommu_ops;
struct subsys_private;
struct wake_irq;
struct irq_domain;
struct dma_map_ops;
struct cma;
struct dev_archdata;
struct iommu_group;
struct iommu_fwspec;
struct iommu_param;
struct ring_buffer;
struct trace_array;
struct tracer;
struct trace_buffer;
struct ring_buffer_iter;
struct event_filter;
struct pipe_inode_info;
struct kcov;
struct kflat;
struct nlm_lockowner;
struct nfs4_lock_state;
struct export_operations;
struct xattr_handler;
struct fscrypt_operations;
struct fsverity_operations;
struct unicode_map;
struct hlist_bl_head;
struct hd_struct;
struct gendisk;
struct mtd_info;
struct rcuwait;
struct fsnotify_mark_connector;
struct cdev;
struct fscrypt_info;
struct fsverity_info;
struct hlist_node;
enum module_state;
struct rb_node;
enum kobj_ns_type;
struct kernfs_elem_dir;
struct kernel_symbol;
struct bug_entry;
struct error_injection_entry;
struct pt_regs;
enum timespec_type;
struct math_emu_info;
struct rb_root_cached;
struct arch_uprobe_task;
enum uprobe_task_state;
struct fwnode_endpoint;
struct hlist_bl_node;
struct fiemap_extent_info;
enum hrtimer_restart;
struct uclamp_se;
struct sched_info;
struct plist_node;
struct upid;
enum migrate_mode;
enum probe_type;
enum dl_dev_state;
enum rpm_request;
enum rpm_status;
struct plist_head;
enum pm_qos_type;
enum dev_pm_qos_req_type;
enum freq_qos_req_type;
struct device_dma_parameters;
enum perf_event_state;
struct perf_addr_filter_range;
enum trace_reg;
enum print_line_t;
struct trace_entry;
enum kflat_mode;
enum rw_hint;
enum pid_type;
enum quota_type;
struct qc_info;
struct quota_format_type;
struct list_lru_one;
struct attribute;
struct optimistic_spin_queue;
struct vdso_image;
struct core_thread;
struct uprobes_state;
struct kparam_string;
struct kparam_array;
struct static_key;
struct tracepoint_func;
struct __kernel_timespec;
struct task_rss_stat;
struct page_frag;
struct return_instance;
struct ctl_node;
struct path;
struct timerqueue_head;
struct assoc_array;
struct nsproxy;
struct bpf_prog_array_item;
struct bpf_cgroup_storage_key;
struct cgroup_freezer_state;
struct rlimit;
struct seccomp;
struct freq_qos_request;
struct perf_event_attr;
struct perf_branch_entry;
union perf_mem_data_src;
struct perf_regs;
struct trace_event;
struct nfs4_lock_info;
struct shrink_control;
struct mem_dqinfo;
struct list_lru;
struct callback_head;
struct kobj_uevent_env;
struct kernfs_elem_attr;
union kernfs_node_id;
struct kref;
struct kernel_param;
struct latch_tree_node;
struct timer_list;
struct bpf_raw_event_map;
struct tracepoint;
struct jump_entry;
struct timespec64;
struct desc_struct;
struct thread_info;
struct arch_tlbflush_unmap_batch;
struct vmacache;
struct fwnode_handle;
struct qstr;
struct fiemap_extent;
struct kiocb;
struct load_weight;
struct sched_statistics;
struct util_est;
struct sched_rt_entity;
union rcu_special;
struct uid_gid_extent;
struct keyring_index_key;
union key_payload;
struct posix_cputimer_base;
struct task_cputime;
struct sigpending;
struct cpu_itimer;
struct task_io_accounting;
struct taskstats;
union __sifields;
struct dev_pm_ops;
struct dev_links_info;
struct pm_qos_constraints;
struct pm_qos_flags;
struct pm_qos_flags_request;
struct hw_perf_event_extra;
struct arch_hw_breakpoint;
struct irq_work;
struct perf_sample_data;
struct perf_callchain_entry;
struct trace_event_call;
struct perf_event_groups;
struct file_lock_operations;
struct nfs_lock_info;
struct file_ra_state;
struct mem_dqblk;
struct qc_dqblk;
struct quota_format_ops;
struct kobject;
struct kset_uevent_ops;
struct attribute_group;
struct kobj_ns_type_operations;
struct kernfs_node;
struct kernfs_syscall_ops;
struct kernel_param_ops;
struct mod_tree_node;
struct old_timespec32;
struct restart_block;
struct fregs_state;
struct fxregs_state;
struct swregs_state;
struct xstate_header;
struct tlbflush_unmap_batch;
struct uprobe_task;
struct fwnode_reference_args;
struct vm_struct;
struct ctl_table_header;
struct delayed_call;
struct iattr;
struct file_system_type;
struct sched_avg;
struct timerqueue_node;
struct key_tag;
struct ucounts;
struct cred;
struct css_set;
struct cgroup_file;
struct cgroup_base_stat;
struct kthread_work;
struct bpf_prog_array;
struct bpf_cgroup_storage;
struct bpf_storage_buffer;
struct task_cputime_atomic;
struct io_cq;
struct bus_type;
struct device_driver;
struct dev_pm_qos_request;
struct dev_pm_domain;
struct perf_branch_stack;
struct trace_event_class;
struct seq_buf;
struct kqid;
struct qc_type_state;
struct dentry_operations;
struct list_lru_memcg;
struct module_kobject;
struct vm_area_struct;
struct rw_semaphore;
struct work_struct;
struct module_layout;
struct mod_kallsyms;
struct rcu_segcblist;
struct notifier_block;
struct xregs_state;
struct kstat;
struct ctl_dir;
struct sched_entity;
struct hrtimer;
struct uid_gid_map;
struct ns_common;
struct key_restriction;
struct prev_cputime;
struct posix_cputimers;
struct ratelimit_state;
struct group_info;
struct percpu_ref;
struct cgroup_rstat_cpu;
struct psi_group_cpu;
struct kthread_worker;
struct kthread_delayed_work;
struct thread_group_cputimer;
struct sigaction;
struct pmu;
struct perf_addr_filters_head;
struct perf_raw_frag;
struct trace_event_functions;
struct trace_seq;
struct lock_manager_operations;
struct kset;
struct sysfs_ops;
struct bin_attribute;
struct mm_rss_stat;
struct mutex;
struct wait_queue_head;
struct xarray;
struct kernfs_ops;
struct module_attribute;
struct srcu_node;
struct srcu_data;
struct delayed_work;
struct page;
union fpregs_state;
struct rcu_work;
struct blocking_notifier_head;
struct fwnode_operations;
struct ctl_table_set;
struct seq_operations;
struct file_operations;
struct dir_context;
struct sched_dl_entity;
struct hrtimer_clock_base;
struct key;
struct user_struct;
struct cgroup_namespace;
struct cgroup_bpf;
struct cftype;
struct k_sigaction;
struct wakeup_source;
struct pm_subsys_data;
struct fasync_struct;
struct perf_raw_record;
struct fown_struct;
struct super_operations;
struct qc_state;
struct quota_info;
struct lockref;
struct file_lock_context;
struct shrinker;
struct list_lru_node;
struct module;
struct kobj_type;
struct idr;
struct kernfs_open_file;
struct fpu;
struct ctl_table_root;
struct file;
struct inode_operations;
struct seq_file;
struct user_namespace;
struct cgroup_subsys_state;
struct address_space;
struct address_space_operations;
struct psi_group;
struct io_context;
struct perf_event_context;
struct device_type;
struct freq_constraints;
struct class;
struct hw_perf_event;
struct trace_iterator;
struct dquot;
struct dquot_operations;
struct quotactl_ops;
struct block_device;
struct mm_struct;
struct completion;
struct kernfs_root;
struct ctl_table;
struct ctl_table_poll;
struct thread_struct;
struct inode;
struct hrtimer_cpu_base;
struct pid;
struct pid_namespace;
struct cgroup;
struct cgroup_subsys;
struct signal_struct;
struct sighand_struct;
struct dev_pm_qos;
struct perf_cpu_context;
struct perf_event;
struct file_lock;
struct rcu_sync;
struct core_state;
struct srcu_struct;
struct dentry;
struct task_struct;
struct cgroup_root;
struct dev_pm_info;
struct percpu_rw_semaphore;
struct device;
struct sb_writers;
struct super_block;
struct poll_table_struct;

/* Global type defs */
struct list_head {
    struct list_head *next;
    struct list_head *prev;
};
struct hlist_head {
    struct hlist_node;
    struct hlist_node *first;
};
struct file;
struct rb_root {
    struct rb_node *rb_node;
};
struct linux_binfmt;
struct ldt_struct;
struct task_struct;
struct kioctx_table;
struct user_namespace;
struct xol_area;
struct anon_vma;
struct vm_operations_struct;
struct vm_userfaultfd_ctx {
};
struct sock;
struct seq_file;
struct kernfs_elem_symlink {
    struct kernfs_node;
    struct kernfs_node *target_kn;
};
struct poll_table_struct;
struct kernfs_open_node;
struct kernfs_iattrs;
struct module_param_attrs;
struct exception_table_entry;
struct mod_arch_specific {
};
struct module_sect_attrs;
struct module_notes_attrs;
struct workqueue_struct;
struct static_key_mod;
struct trace_event_call;
struct trace_eval_map;
struct pollfd;
struct address_space;
struct kmem_cache;
typedef struct page *pgtable_t;
struct dev_pagemap;
struct mem_cgroup;
struct perf_event;
struct lock_class_key {
};
struct uprobe;
struct llist_node {
    struct llist_node *next;
};
struct device;
struct device_node;
struct fs_context;
struct vfsmount;
struct posix_acl;
struct fs_parameter_description;
struct writeback_control;
struct kstatfs;
struct iov_iter;
struct sched_class;
struct task_group;
struct rcu_node;
struct proc_ns_operations;
struct key_user;
struct key_type;
struct assoc_array_ptr;
struct nameidata;
struct fs_struct;
struct files_struct;
struct uts_namespace;
struct ipc_namespace;
struct mnt_namespace;
struct net;
struct swap_info_struct;
struct u64_stats_sync {
};
struct bpf_prog;
struct bpf_cgroup_storage_map;
struct cgroup_taskset;
struct tty_struct;
struct tty_audit_buf;
struct audit_context;
struct seccomp_filter;
struct wake_q_node {
    struct wake_q_node *next;
};
struct rt_mutex_waiter;
struct bio_list;
struct blk_plug;
struct reclaim_state;
struct backing_dev_info;
struct request_queue;
struct capture_control;
struct robust_list_head;
struct compat_robust_list_head;
struct futex_pi_state;
struct device_private;
struct of_device_id;
struct acpi_device_id;
struct driver_private;
struct iommu_ops;
struct subsys_private;
struct wake_irq;
struct irq_domain;
struct dma_map_ops;
struct cma;
struct dev_archdata {
};
struct iommu_group;
struct iommu_fwspec;
struct iommu_param;
struct ring_buffer;
struct trace_array;
struct tracer;
struct trace_buffer;
struct ring_buffer_iter;
struct event_filter;
struct pipe_inode_info;
struct kcov;
struct kflat;
struct nlm_lockowner;
struct nfs4_lock_state;
struct export_operations;
struct xattr_handler;
struct fscrypt_operations;
struct fsverity_operations;
struct unicode_map;
struct hlist_bl_head {
    struct hlist_bl_node;
    struct hlist_bl_node *first;
};
struct hd_struct;
struct gendisk;
struct mtd_info;
struct rcuwait {
    struct task_struct *task;
};
struct fsnotify_mark_connector;
struct cdev;
struct fscrypt_info;
struct fsverity_info;
typedef signed char __s8;
typedef unsigned char __u8;
typedef short __s16;
typedef unsigned short __u16;
typedef int __s32;
typedef unsigned int __u32;
typedef long long __s64;
typedef unsigned long long __u64;
typedef long __kernel_long_t;
typedef unsigned long __kernel_ulong_t;
typedef int __kernel_pid_t;
typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;
typedef long long __kernel_loff_t;
typedef long long __kernel_time64_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef unsigned int __poll_t;
typedef unsigned short umode_t;
typedef _Bool bool;
typedef unsigned int gfp_t;
typedef unsigned int fmode_t;
typedef struct {
    int counter;
} atomic_t;
struct hlist_node {
    struct hlist_node *next;
    struct hlist_node **pprev;
};
enum module_state {
    MODULE_STATE_LIVE,
    MODULE_STATE_COMING,
    MODULE_STATE_GOING,
    MODULE_STATE_UNFORMED
};
struct __attribute__((aligned(sizeof(long)))) rb_node {
    unsigned long __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};
typedef unsigned long pgdval_t;
typedef unsigned long pgprotval_t;
enum kobj_ns_type {
    KOBJ_NS_TYPE_NONE = 0,
    KOBJ_NS_TYPE_NET,
    KOBJ_NS_TYPES
};
struct kernfs_elem_dir {
    unsigned long subdirs;
    struct rb_root children;
    struct kernfs_root;
    struct kernfs_root *root;
};
struct kernel_symbol {
    int value_offset;
    int name_offset;
    int namespace_offset;
};
struct bug_entry {
    int bug_addr_disp;
    int file_disp;
    unsigned short line;
    unsigned short flags;
};
typedef const int tracepoint_ptr_t;
struct error_injection_entry {
    unsigned long addr;
    int etype;
};
struct pt_regs {
    unsigned long r15;
    unsigned long r14;
    unsigned long r13;
    unsigned long r12;
    unsigned long bp;
    unsigned long bx;
    unsigned long r11;
    unsigned long r10;
    unsigned long r9;
    unsigned long r8;
    unsigned long ax;
    unsigned long cx;
    unsigned long dx;
    unsigned long si;
    unsigned long di;
    unsigned long orig_ax;
    unsigned long ip;
    unsigned long cs;
    unsigned long flags;
    unsigned long sp;
    unsigned long ss;
};
enum timespec_type {
    TT_NONE = 0,
    TT_NATIVE = 1,
    TT_COMPAT = 2
};
typedef struct {
    unsigned long seg;
} mm_segment_t;
struct math_emu_info {
    long ___orig_eip;
    struct pt_regs *regs;
};
typedef struct seqcount {
    unsigned int sequence;
} seqcount_t;
struct rb_root_cached {
    struct rb_root rb_root;
    struct rb_node *rb_leftmost;
};
struct arch_uprobe_task {
    unsigned long saved_scratch_register;
    unsigned int saved_trap_nr;
    unsigned int saved_tf;
};
enum uprobe_task_state {
    UTASK_RUNNING,
    UTASK_SSTEP,
    UTASK_SSTEP_ACK,
    UTASK_SSTEP_TRAPPED
};
typedef unsigned int isolate_mode_t;
struct fwnode_endpoint {
    unsigned int port;
    unsigned int id;
    const struct fwnode_handle *local_fwnode;
};
struct hlist_bl_node {
    struct hlist_bl_node *next;
    struct hlist_bl_node **pprev;
};
struct fiemap_extent_info {
    unsigned int fi_flags;
    unsigned int fi_extents_mapped;
    unsigned int fi_extents_max;
    struct fiemap_extent *fi_extents_start;
};
enum hrtimer_restart {
    HRTIMER_NORESTART,
    HRTIMER_RESTART
};



typedef __u32 u32;
typedef __u64 u64;


static inline int __bits_per(unsigned long n) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((const));

static inline int __ilog2_u64(u64 n) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((const));

static inline int __ilog2_u32(u32 n) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((const));


struct uclamp_se {
    unsigned int value : (__builtin_constant_p((1L << 10)) ? ((((1L << 10)) == 0 || ((1L << 10)) == 1) ? 1 : (__builtin_constant_p((1L << 10)) ? (__builtin_constant_p((1L << 10)) ? (((1L << 10)) < 2 ? 0 : ((1L << 10)) & (1ULL << 63) ? 63 : ((1L << 10)) & (1ULL << 62) ? 62 : ((1L << 10)) & (1ULL << 61) ? 61 : ((1L << 10)) & (1ULL << 60) ? 60 : ((1L << 10)) & (1ULL << 59) ? 59 : ((1L << 10)) & (1ULL << 58) ? 58 : ((1L << 10)) & (1ULL << 57) ? 57 : ((1L << 10)) & (1ULL << 56) ? 56 : ((1L << 10)) & (1ULL << 55) ? 55 : ((1L << 10)) & (1ULL << 54) ? 54 : ((1L << 10)) & (1ULL << 53) ? 53 : ((1L << 10)) & (1ULL << 52) ? 52 : ((1L << 10)) & (1ULL << 51) ? 51 : ((1L << 10)) & (1ULL << 50) ? 50 : ((1L << 10)) & (1ULL << 49) ? 49 : ((1L << 10)) & (1ULL << 48) ? 48 : ((1L << 10)) & (1ULL << 47) ? 47 : ((1L << 10)) & (1ULL << 46) ? 46 : ((1L << 10)) & (1ULL << 45) ? 45 : ((1L << 10)) & (1ULL << 44) ? 44 : ((1L << 10)) & (1ULL << 43) ? 43 : ((1L << 10)) & (1ULL << 42) ? 42 : ((1L << 10)) & (1ULL << 41) ? 41 : ((1L << 10)) & (1ULL << 40) ? 40 : ((1L << 10)) & (1ULL << 39) ? 39 : ((1L << 10)) & (1ULL << 38) ? 38 : ((1L << 10)) & (1ULL << 37) ? 37 : ((1L << 10)) & (1ULL << 36) ? 36 : ((1L << 10)) & (1ULL << 35) ? 35 : ((1L << 10)) & (1ULL << 34) ? 34 : ((1L << 10)) & (1ULL << 33) ? 33 : ((1L << 10)) & (1ULL << 32) ? 32 : ((1L << 10)) & (1ULL << 31) ? 31 : ((1L << 10)) & (1ULL << 30) ? 30 : ((1L << 10)) & (1ULL << 29) ? 29 : ((1L << 10)) & (1ULL << 28) ? 28 : ((1L << 10)) & (1ULL << 27) ? 27 : ((1L << 10)) & (1ULL << 26) ? 26 : ((1L << 10)) & (1ULL << 25) ? 25 : ((1L << 10)) & (1ULL << 24) ? 24 : ((1L << 10)) & (1ULL << 23) ? 23 : ((1L << 10)) & (1ULL << 22) ? 22 : ((1L << 10)) & (1ULL << 21) ? 21 : ((1L << 10)) & (1ULL << 20) ? 20 : ((1L << 10)) & (1ULL << 19) ? 19 : ((1L << 10)) & (1ULL << 18) ? 18 : ((1L << 10)) & (1ULL << 17) ? 17 : ((1L << 10)) & (1ULL << 16) ? 16 : ((1L << 10)) & (1ULL << 15) ? 15 : ((1L << 10)) & (1ULL << 14) ? 14 : ((1L << 10)) & (1ULL << 13) ? 13 : ((1L << 10)) & (1ULL << 12) ? 12 : ((1L << 10)) & (1ULL << 11) ? 11 : ((1L << 10)) & (1ULL << 10) ? 10 : ((1L << 10)) & (1ULL << 9) ? 9 : ((1L << 10)) & (1ULL << 8) ? 8 : ((1L << 10)) & (1ULL << 7) ? 7 : ((1L << 10)) & (1ULL << 6) ? 6 : ((1L << 10)) & (1ULL << 5) ? 5 : ((1L << 10)) & (1ULL << 4) ? 4 : ((1L << 10)) & (1ULL << 3) ? 3 : ((1L << 10)) & (1ULL << 2) ? 2 : 1) : -1) : (sizeof ((1L << 10)) <= 4) ? __ilog2_u32((1L << 10)) : __ilog2_u64((1L << 10))) + 1) : __bits_per((1L << 10)));
    unsigned int bucket_id : (__builtin_constant_p(5) ? (((5) == 0 || (5) == 1) ? 1 : (__builtin_constant_p(5) ? (__builtin_constant_p(5) ? ((5) < 2 ? 0 : (5) & (1ULL << 63) ? 63 : (5) & (1ULL << 62) ? 62 : (5) & (1ULL << 61) ? 61 : (5) & (1ULL << 60) ? 60 : (5) & (1ULL << 59) ? 59 : (5) & (1ULL << 58) ? 58 : (5) & (1ULL << 57) ? 57 : (5) & (1ULL << 56) ? 56 : (5) & (1ULL << 55) ? 55 : (5) & (1ULL << 54) ? 54 : (5) & (1ULL << 53) ? 53 : (5) & (1ULL << 52) ? 52 : (5) & (1ULL << 51) ? 51 : (5) & (1ULL << 50) ? 50 : (5) & (1ULL << 49) ? 49 : (5) & (1ULL << 48) ? 48 : (5) & (1ULL << 47) ? 47 : (5) & (1ULL << 46) ? 46 : (5) & (1ULL << 45) ? 45 : (5) & (1ULL << 44) ? 44 : (5) & (1ULL << 43) ? 43 : (5) & (1ULL << 42) ? 42 : (5) & (1ULL << 41) ? 41 : (5) & (1ULL << 40) ? 40 : (5) & (1ULL << 39) ? 39 : (5) & (1ULL << 38) ? 38 : (5) & (1ULL << 37) ? 37 : (5) & (1ULL << 36) ? 36 : (5) & (1ULL << 35) ? 35 : (5) & (1ULL << 34) ? 34 : (5) & (1ULL << 33) ? 33 : (5) & (1ULL << 32) ? 32 : (5) & (1ULL << 31) ? 31 : (5) & (1ULL << 30) ? 30 : (5) & (1ULL << 29) ? 29 : (5) & (1ULL << 28) ? 28 : (5) & (1ULL << 27) ? 27 : (5) & (1ULL << 26) ? 26 : (5) & (1ULL << 25) ? 25 : (5) & (1ULL << 24) ? 24 : (5) & (1ULL << 23) ? 23 : (5) & (1ULL << 22) ? 22 : (5) & (1ULL << 21) ? 21 : (5) & (1ULL << 20) ? 20 : (5) & (1ULL << 19) ? 19 : (5) & (1ULL << 18) ? 18 : (5) & (1ULL << 17) ? 17 : (5) & (1ULL << 16) ? 16 : (5) & (1ULL << 15) ? 15 : (5) & (1ULL << 14) ? 14 : (5) & (1ULL << 13) ? 13 : (5) & (1ULL << 12) ? 12 : (5) & (1ULL << 11) ? 11 : (5) & (1ULL << 10) ? 10 : (5) & (1ULL << 9) ? 9 : (5) & (1ULL << 8) ? 8 : (5) & (1ULL << 7) ? 7 : (5) & (1ULL << 6) ? 6 : (5) & (1ULL << 5) ? 5 : (5) & (1ULL << 4) ? 4 : (5) & (1ULL << 3) ? 3 : (5) & (1ULL << 2) ? 2 : 1) : -1) : (sizeof (5) <= 4) ? __ilog2_u32(5) : __ilog2_u64(5)) + 1) : __bits_per(5));
    unsigned int active : 1;
    unsigned int user_defined : 1;
};
struct sched_info {
    unsigned long pcount;
    unsigned long long run_delay;
    unsigned long long last_arrival;
    unsigned long long last_queued;
};
struct plist_node {
    int prio;
    struct list_head prio_list;
    struct list_head node_list;
};
struct upid {
    int nr;
    struct pid_namespace;
    struct pid_namespace *ns;
};
enum migrate_mode {
    MIGRATE_ASYNC,
    MIGRATE_SYNC_LIGHT,
    MIGRATE_SYNC,
    MIGRATE_SYNC_NO_COPY
};
enum probe_type {
    PROBE_DEFAULT_STRATEGY,
    PROBE_PREFER_ASYNCHRONOUS,
    PROBE_FORCE_SYNCHRONOUS
};
typedef struct pm_message {
    int event;
} pm_message_t;
enum dl_dev_state {
    DL_DEV_NO_DRIVER = 0,
    DL_DEV_PROBING,
    DL_DEV_DRIVER_BOUND,
    DL_DEV_UNBINDING
};
enum rpm_request {
    RPM_REQ_NONE = 0,
    RPM_REQ_IDLE,
    RPM_REQ_SUSPEND,
    RPM_REQ_AUTOSUSPEND,
    RPM_REQ_RESUME
};
enum rpm_status {
    RPM_ACTIVE = 0,
    RPM_RESUMING,
    RPM_SUSPENDED,
    RPM_SUSPENDING
};
struct plist_head {
    struct list_head node_list;
};
enum pm_qos_type {
    PM_QOS_UNITIALIZED,
    PM_QOS_MAX,
    PM_QOS_MIN,
    PM_QOS_SUM
};
enum dev_pm_qos_req_type {
    DEV_PM_QOS_RESUME_LATENCY = 1,
    DEV_PM_QOS_LATENCY_TOLERANCE,
    DEV_PM_QOS_MIN_FREQUENCY,
    DEV_PM_QOS_MAX_FREQUENCY,
    DEV_PM_QOS_FLAGS
};
enum freq_qos_req_type {
    FREQ_QOS_MIN = 1,
    FREQ_QOS_MAX
};
struct device_dma_parameters {
    unsigned int max_segment_size;
    unsigned long segment_boundary_mask;
};
enum perf_event_state {
    PERF_EVENT_STATE_DEAD = -4,
    PERF_EVENT_STATE_EXIT = -3,
    PERF_EVENT_STATE_ERROR = -2,
    PERF_EVENT_STATE_OFF = -1,
    PERF_EVENT_STATE_INACTIVE = 0,
    PERF_EVENT_STATE_ACTIVE = 1
};
struct perf_addr_filter_range {
    unsigned long start;
    unsigned long size;
};
enum trace_reg {
    TRACE_REG_REGISTER,
    TRACE_REG_UNREGISTER,
    TRACE_REG_PERF_REGISTER,
    TRACE_REG_PERF_UNREGISTER,
    TRACE_REG_PERF_OPEN,
    TRACE_REG_PERF_CLOSE,
    TRACE_REG_PERF_ADD,
    TRACE_REG_PERF_DEL
};
enum print_line_t {
    TRACE_TYPE_PARTIAL_LINE = 0,
    TRACE_TYPE_HANDLED = 1,
    TRACE_TYPE_UNHANDLED = 2,
    TRACE_TYPE_NO_CONSUME = 3
};
struct trace_entry {
    unsigned short type;
    unsigned char flags;
    unsigned char preempt_count;
    int pid;
};
enum kflat_mode {
    KFLAT_MODE_DISABLED = 0,
    KFLAT_MODE_ENABLED = 1
};
enum rw_hint {
    WRITE_LIFE_NOT_SET = 0,
    WRITE_LIFE_NONE = 1,
    WRITE_LIFE_SHORT = 2,
    WRITE_LIFE_MEDIUM = 3,
    WRITE_LIFE_LONG = 4,
    WRITE_LIFE_EXTREME = 5
};
enum pid_type {
    PIDTYPE_PID,
    PIDTYPE_TGID,
    PIDTYPE_PGID,
    PIDTYPE_SID,
    PIDTYPE_MAX
};
enum quota_type {
    USRQUOTA = 0,
    GRPQUOTA = 1,
    PRJQUOTA = 2
};
typedef long long qsize_t;
struct qc_info {
    int i_fieldmask;
    unsigned int i_flags;
    unsigned int i_spc_timelimit;
    unsigned int i_ino_timelimit;
    unsigned int i_rt_spc_timelimit;
    unsigned int i_spc_warnlimit;
    unsigned int i_ino_warnlimit;
    unsigned int i_rt_spc_warnlimit;
};
struct quota_format_type {
    int qf_fmt_id;
    const struct quota_format_ops *qf_ops;
    struct module *qf_owner;
    struct quota_format_type *qf_next;
};
struct list_lru_one {
    struct list_head list;
    long nr_items;
};
typedef __s8 s8;
typedef __u8 u8;
typedef __s16 s16;
typedef __u16 u16;
typedef __s32 s32;
typedef __u32 u32;
typedef __s64 s64;
typedef __u64 u64;
typedef __kernel_ulong_t __kernel_size_t;
typedef __kernel_long_t __kernel_ssize_t;
typedef __kernel_long_t __kernel_clock_t;
typedef __kernel_pid_t pid_t;
typedef __kernel_clockid_t clockid_t;
typedef __kernel_uid32_t uid_t;
typedef __kernel_gid32_t gid_t;
typedef __kernel_loff_t loff_t;
struct attribute {
    const char *name;
    umode_t mode;
};
typedef struct {
    pgdval_t pgd;
} pgd_t;
struct optimistic_spin_queue {
    atomic_t tail;
};
struct vdso_image {
    void *data;
    unsigned long size;
    unsigned long alt;
    unsigned long alt_len;
    long sym_vvar_start;
    long sym_vvar_page;
    long sym_pvclock_page;
    long sym_hvclock_page;
    long sym_VDSO32_NOTE_MASK;
    long sym___kernel_sigreturn;
    long sym___kernel_rt_sigreturn;
    long sym___kernel_vsyscall;
    long sym_int80_landing_pad;
};
struct core_thread {
    struct task_struct *task;
    struct core_thread *next;
};
struct uprobes_state {
    struct xol_area *xol_area;
};
typedef struct pgprot {
    pgprotval_t pgprot;
} pgprot_t;
typedef struct refcount_struct {
    atomic_t refs;
} refcount_t;
struct kparam_string {
    unsigned int maxlen;
    char *string;
};
struct kparam_array {
    unsigned int max;
    unsigned int elemsize;
    unsigned int *num;
    const struct kernel_param_ops *ops;
    void *elem;
};
typedef __u32 Elf64_Word;
typedef __u16 Elf64_Half;
typedef __u64 Elf64_Addr;
typedef __u64 Elf64_Xword;
struct static_key {
    atomic_t enabled;
    union {
        unsigned long type;
        struct jump_entry;
        struct jump_entry *entries;
        struct static_key_mod;
        struct static_key_mod *next;
    };
};
struct tracepoint_func {
    void *func;
    void *data;
    int prio;
};
typedef __s64 time64_t;
struct __kernel_timespec {
    __kernel_time64_t tv_sec;
    long long tv_nsec;
};
typedef struct cpumask {
    unsigned long bits[1];
} cpumask_t;
typedef struct {
    unsigned long bits[1];
} nodemask_t;
struct task_rss_stat {
    int events;
    int count[4];
};
struct page_frag {
    struct page *page;
    __u32 offset;
    __u32 size;
};
struct return_instance {
    struct uprobe *uprobe;
    unsigned long func;
    unsigned long stack;
    unsigned long orig_ret_vaddr;
    bool chained;
    struct return_instance *next;
};
struct ctl_node {
    struct rb_node node;
    struct ctl_table_header *header;
};
struct path {
    struct vfsmount *mnt;
    struct dentry *dentry;
};
struct timerqueue_head {
    struct rb_root_cached rb_root;
};
struct assoc_array {
    struct assoc_array_ptr;
    struct assoc_array_ptr *root;
    unsigned long nr_leaves_on_tree;
};
struct nsproxy {
    atomic_t count;
    struct uts_namespace *uts_ns;
    struct ipc_namespace *ipc_ns;
    struct mnt_namespace *mnt_ns;
    struct pid_namespace *pid_ns_for_children;
    struct net *net_ns;
    struct cgroup_namespace *cgroup_ns;
};
typedef void (percpu_ref_func_t)(struct percpu_ref *);
struct bpf_prog_array_item {
    struct bpf_prog *prog;
    struct bpf_cgroup_storage;
    struct bpf_cgroup_storage *cgroup_storage[2];
};
struct bpf_cgroup_storage_key {
    __u64 cgroup_inode_id;
    __u32 attach_type;
};
struct cgroup_freezer_state {
    bool freeze;
    int e_freeze;
    int nr_frozen_descendants;
    int nr_frozen_tasks;
};
/*typedef struct {
    unsigned long sig[1];
} sigset_t;*/ /* AOT */
struct rlimit {
    __kernel_ulong_t rlim_cur;
    __kernel_ulong_t rlim_max;
};
typedef void (__signalfn_t)(int);
typedef void (__restorefn_t)(void);
struct seccomp {
    int mode;
    struct seccomp_filter *filter;
};
typedef union sigval {
    int sival_int;
    void *sival_ptr;
} sigval_t;
struct freq_qos_request {
    enum freq_qos_req_type type;
    struct plist_node pnode;
    struct freq_constraints *qos;
};
struct perf_event_attr {
    __u32 type;
    __u32 size;
    __u64 config;
    union {
        __u64 sample_period;
        __u64 sample_freq;
    };
    __u64 sample_type;
    __u64 read_format;
    __u64 disabled : 1;
    __u64 inherit : 1;
    __u64 pinned : 1;
    __u64 exclusive : 1;
    __u64 exclude_user : 1;
    __u64 exclude_kernel : 1;
    __u64 exclude_hv : 1;
    __u64 exclude_idle : 1;
    __u64 mmap : 1;
    __u64 comm : 1;
    __u64 freq : 1;
    __u64 inherit_stat : 1;
    __u64 enable_on_exec : 1;
    __u64 task : 1;
    __u64 watermark : 1;
    __u64 precise_ip : 2;
    __u64 mmap_data : 1;
    __u64 sample_id_all : 1;
    __u64 exclude_host : 1;
    __u64 exclude_guest : 1;
    __u64 exclude_callchain_kernel : 1;
    __u64 exclude_callchain_user : 1;
    __u64 mmap2 : 1;
    __u64 comm_exec : 1;
    __u64 use_clockid : 1;
    __u64 context_switch : 1;
    __u64 write_backward : 1;
    __u64 namespaces : 1;
    __u64 ksymbol : 1;
    __u64 bpf_event : 1;
    __u64 aux_output : 1;
    __u64 __reserved_1 : 32;
    union {
        __u32 wakeup_events;
        __u32 wakeup_watermark;
    };
    __u32 bp_type;
    union {
        __u64 bp_addr;
        __u64 kprobe_func;
        __u64 uprobe_path;
        __u64 config1;
    };
    union {
        __u64 bp_len;
        __u64 kprobe_addr;
        __u64 probe_offset;
        __u64 config2;
    };
    __u64 branch_sample_type;
    __u64 sample_regs_user;
    __u32 sample_stack_user;
    __s32 clockid;
    __u64 sample_regs_intr;
    __u32 aux_watermark;
    __u16 sample_max_stack;
    __u16 __reserved_2;
};
struct perf_branch_entry {
    __u64 from;
    __u64 to;
    __u64 mispred : 1;
    __u64 predicted : 1;
    __u64 in_tx : 1;
    __u64 abort : 1;
    __u64 cycles : 16;
    __u64 type : 4;
    __u64 reserved : 40;
};
union perf_mem_data_src {
    __u64 val;
    struct {
        __u64 mem_op : 5;
        __u64 mem_lvl : 14;
        __u64 mem_snoop : 5;
        __u64 mem_lock : 2;
        __u64 mem_dtlb : 7;
        __u64 mem_lvl_num : 4;
        __u64 mem_remote : 1;
        __u64 mem_snoopx : 2;
        __u64 mem_rsvd : 24;
    };
};
struct perf_regs {
    __u64 abi;
    struct pt_regs *regs;
};
struct trace_event {
    struct hlist_node node;
    struct list_head list;
    int type;
    struct trace_event_functions *funcs;
};
typedef void *fl_owner_t;
struct nfs4_lock_info {
    struct nfs4_lock_state *owner;
};
typedef __kernel_uid32_t projid_t;
struct shrink_control {
    gfp_t gfp_mask;
    int nid;
    unsigned long nr_to_scan;
    unsigned long nr_scanned;
    struct mem_cgroup *memcg;
};
struct mem_dqinfo {
    struct quota_format_type *dqi_format;
    int dqi_fmt_id;
    struct list_head dqi_dirty_list;
    unsigned long dqi_flags;
    unsigned int dqi_bgrace;
    unsigned int dqi_igrace;
    qsize_t dqi_max_spc_limit;
    qsize_t dqi_max_ino_limit;
    void *dqi_priv;
};
struct list_lru {
    struct list_lru_node *node;
    struct list_head list;
    int shrinker_id;
    bool memcg_aware;
};
typedef u32 __kernel_dev_t;
typedef __kernel_size_t size_t;
typedef __kernel_ssize_t ssize_t;
typedef s32 int32_t;
typedef u32 uint32_t;
typedef u64 sector_t;
typedef u64 blkcnt_t;
typedef u64 dma_addr_t;
typedef u64 phys_addr_t;
typedef struct {
    s64 counter;
} atomic64_t;
struct __attribute__((aligned(sizeof(void *)))) callback_head {
    struct callback_head *next;
    void (*func)(struct callback_head *);
};
typedef struct qspinlock {
    union {
        atomic_t val;
        struct {
            u8 locked;
            u8 pending;
        };
        struct {
            u16 locked_pending;
            u16 tail;
        };
    };
} arch_spinlock_t;
struct kobj_uevent_env {
    char *argv[3];
    char *envp[32];
    int envp_idx;
    char buf[2048];
    int buflen;
};
typedef void (*work_func_t)(struct work_struct *);
typedef struct {
    uid_t val;
} kuid_t;
typedef struct {
    gid_t val;
} kgid_t;
struct kernfs_elem_attr {
    struct kernfs_ops;
    const struct kernfs_ops *ops;
    struct kernfs_open_node *open;
    loff_t size;
    struct kernfs_node *notify_next;
};
union kernfs_node_id {
    struct {
        u32 ino;
        u32 generation;
    };
    u64 id;
};
struct kref {
    refcount_t refcount;
};
struct kernel_param {
    const char *name;
    struct module *mod;
    const struct kernel_param_ops *ops;
    const u16 perm;
    s8 level;
    u8 flags;
    union {
        void *arg;
        struct kparam_string;
        const struct kparam_string *str;
        struct kparam_array;
        const struct kparam_array *arr;
    };
};
struct latch_tree_node {
    struct rb_node node[2];
};
typedef struct elf64_sym {
    Elf64_Word st_name;
    unsigned char st_info;
    unsigned char st_other;
    Elf64_Half st_shndx;
    Elf64_Addr st_value;
    Elf64_Xword st_size;
} Elf64_Sym;
struct timer_list {
    struct hlist_node entry;
    unsigned long expires;
    void (*function)(struct timer_list *);
    u32 flags;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
struct __attribute__((aligned(32))) bpf_raw_event_map {
    struct tracepoint *tp;
    void *bpf_func;
    u32 num_args;
    u32 writable_size;
};
struct tracepoint {
    const char *name;
    struct static_key key;
    int (*regfunc)(void);
    void (*unregfunc)(void);
    struct tracepoint_func *funcs;
};
struct jump_entry {
    s32 code;
    s32 target;
    long key;
};
struct timespec64 {
    time64_t tv_sec;
    long tv_nsec;
};
typedef s32 old_time32_t;
struct __attribute__((packed)) desc_struct {
    u16 limit0;
    u16 base0;
    u16 base1 : 8;
    u16 type : 4;
    u16 s : 1;
    u16 dpl : 2;
    u16 p : 1;
    u16 limit1 : 4;
    u16 avl : 1;
    u16 l : 1;
    u16 d : 1;
    u16 g : 1;
    u16 base2 : 8;
};
struct thread_info {
    unsigned long flags;
    u32 status;
};
struct arch_tlbflush_unmap_batch {
    struct cpumask cpumask;
};
struct vmacache {
    u64 seqnum;
    struct vm_area_struct *vmas[4];
};
typedef s64 ktime_t;
struct fwnode_handle {
    struct fwnode_handle *secondary;
    const struct fwnode_operations *ops;
    struct device *dev;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct qstr {
    union {
        struct {
            u32 hash;
            u32 len;
        };
        u64 hash_len;
    };
    const unsigned char *name;
};
struct fiemap_extent {
    __u64 fe_logical;
    __u64 fe_physical;
    __u64 fe_length;
    __u64 fe_reserved64[2];
    __u32 fe_flags;
    __u32 fe_reserved[3];
};
struct kiocb {
    struct file *ki_filp;
    loff_t ki_pos;
    void (*ki_complete)(struct kiocb *, long, long);
    void *private;
    int ki_flags;
    u16 ki_hint;
    u16 ki_ioprio;
    unsigned int ki_cookie;
};
struct load_weight {
    unsigned long weight;
    u32 inv_weight;
};
struct sched_statistics {
    u64 wait_start;
    u64 wait_max;
    u64 wait_count;
    u64 wait_sum;
    u64 iowait_count;
    u64 iowait_sum;
    u64 sleep_start;
    u64 sleep_max;
    s64 sum_sleep_runtime;
    u64 block_start;
    u64 block_max;
    u64 exec_max;
    u64 slice_max;
    u64 nr_migrations_cold;
    u64 nr_failed_migrations_affine;
    u64 nr_failed_migrations_running;
    u64 nr_failed_migrations_hot;
    u64 nr_forced_migrations;
    u64 nr_wakeups;
    u64 nr_wakeups_sync;
    u64 nr_wakeups_migrate;
    u64 nr_wakeups_local;
    u64 nr_wakeups_remote;
    u64 nr_wakeups_affine;
    u64 nr_wakeups_affine_attempts;
    u64 nr_wakeups_passive;
    u64 nr_wakeups_idle;
};
struct __attribute__((aligned(sizeof(u64)))) util_est {
    unsigned int enqueued;
    unsigned int ewma;
};
struct sched_rt_entity {
    struct list_head run_list;
    unsigned long timeout;
    unsigned long watchdog_stamp;
    unsigned int time_slice;
    unsigned short on_rq;
    unsigned short on_list;
    struct sched_rt_entity *back;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
union rcu_special {
    struct {
        u8 blocked;
        u8 need_qs;
        u8 exp_hint;
        u8 deferred_qs;
    } b;
    u32 s;
};
struct uid_gid_extent {
    u32 first;
    u32 lower_first;
    u32 count;
};
struct keyring_index_key {
    unsigned long hash;
    union {
        struct {
            u16 desc_len;
            char desc[6];
        };
        unsigned long x;
    };
    struct key_type *type;
    struct key_tag *domain_tag;
    const char *description;
};
union key_payload {
    void *rcu_data0;
    void *data[4];
};
struct posix_cputimer_base {
    u64 nextevt;
    struct timerqueue_head tqhead;
};
typedef struct kernel_cap_struct {
    __u32 cap[2];
} kernel_cap_t;
typedef u32 errseq_t;
struct task_cputime {
    u64 stime;
    u64 utime;
    unsigned long long sum_exec_runtime;
};
typedef void (*kthread_work_func_t)(struct kthread_work *);
struct sigpending {
    struct list_head list;
    sigset_t signal;
};
struct cpu_itimer {
    u64 expires;
    u64 incr;
};
struct task_io_accounting {
    u64 rchar;
    u64 wchar;
    u64 syscr;
    u64 syscw;
    u64 syscfs;
    u64 read_bytes;
    u64 write_bytes;
    u64 cancelled_write_bytes;
};
struct taskstats {
    __u16 version;
    __u32 ac_exitcode;
    __u8 ac_flag;
    __u8 ac_nice;
    __u64 cpu_count __attribute__((aligned(8)));
    __u64 cpu_delay_total;
    __u64 blkio_count;
    __u64 blkio_delay_total;
    __u64 swapin_count;
    __u64 swapin_delay_total;
    __u64 cpu_run_real_total;
    __u64 cpu_run_virtual_total;
    char ac_comm[32];
    __u8 ac_sched __attribute__((aligned(8)));
    __u8 ac_pad[3];
    __u32 ac_uid __attribute__((aligned(8)));
    __u32 ac_gid;
    __u32 ac_pid;
    __u32 ac_ppid;
    __u32 ac_btime;
    __u64 ac_etime __attribute__((aligned(8)));
    __u64 ac_utime;
    __u64 ac_stime;
    __u64 ac_minflt;
    __u64 ac_majflt;
    __u64 coremem;
    __u64 virtmem;
    __u64 hiwater_rss;
    __u64 hiwater_vm;
    __u64 read_char;
    __u64 write_char;
    __u64 read_syscalls;
    __u64 write_syscalls;
    __u64 read_bytes;
    __u64 write_bytes;
    __u64 cancelled_write_bytes;
    __u64 nvcsw;
    __u64 nivcsw;
    __u64 ac_utimescaled;
    __u64 ac_stimescaled;
    __u64 cpu_scaled_run_real_total;
    __u64 freepages_count;
    __u64 freepages_delay_total;
    __u64 thrashing_count;
    __u64 thrashing_delay_total;
};
union __sifields {
    struct {
        __kernel_pid_t _pid;
        __kernel_uid32_t _uid;
    } _kill;
    struct {
        __kernel_timer_t _tid;
        int _overrun;
        sigval_t _sigval;
        int _sys_private;
    } _timer;
    struct {
        __kernel_pid_t _pid;
        __kernel_uid32_t _uid;
        sigval_t _sigval;
    } _rt;
    struct {
        __kernel_pid_t _pid;
        __kernel_uid32_t _uid;
        int _status;
        __kernel_clock_t _utime;
        __kernel_clock_t _stime;
    } _sigchld;
    struct {
        void *_addr;
        union {
            short _addr_lsb;
            struct {
                char _dummy_bnd[8];
                void *_lower;
                void *_upper;
            } _addr_bnd;
            struct {
                char _dummy_pkey[8];
                __u32 _pkey;
            } _addr_pkey;
        };
    } _sigfault;
    struct {
        long _band;
        int _fd;
    } _sigpoll;
    struct {
        void *_call_addr;
        int _syscall;
        unsigned int _arch;
    } _sigsys;
};
struct dev_pm_ops {
    int (*prepare)(struct device *);
    void (*complete)(struct device *);
    int (*suspend)(struct device *);
    int (*resume)(struct device *);
    int (*freeze)(struct device *);
    int (*thaw)(struct device *);
    int (*poweroff)(struct device *);
    int (*restore)(struct device *);
    int (*suspend_late)(struct device *);
    int (*resume_early)(struct device *);
    int (*freeze_late)(struct device *);
    int (*thaw_early)(struct device *);
    int (*poweroff_late)(struct device *);
    int (*restore_early)(struct device *);
    int (*suspend_noirq)(struct device *);
    int (*resume_noirq)(struct device *);
    int (*freeze_noirq)(struct device *);
    int (*thaw_noirq)(struct device *);
    int (*poweroff_noirq)(struct device *);
    int (*restore_noirq)(struct device *);
    int (*runtime_suspend)(struct device *);
    int (*runtime_resume)(struct device *);
    int (*runtime_idle)(struct device *);
};
struct dev_links_info {
    struct list_head suppliers;
    struct list_head consumers;
    struct list_head needs_suppliers;
    struct list_head defer_hook;
    bool need_for_probe;
    enum dl_dev_state status;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct pm_qos_constraints {
    struct plist_head list;
    s32 target_value;
    s32 default_value;
    s32 no_constraint_value;
    enum pm_qos_type type;
    struct blocking_notifier_head *notifiers;
};
struct pm_qos_flags {
    struct list_head list;
    s32 effective_flags;
};
struct pm_qos_flags_request {
    struct list_head node;
    s32 flags;
};
struct hw_perf_event_extra {
    u64 config;
    unsigned int reg;
    int alloc;
    int idx;
};
struct arch_hw_breakpoint {
    unsigned long address;
    unsigned long mask;
    u8 len;
    u8 type;
};
struct irq_work {
    unsigned long flags;
    struct llist_node llnode;
    void (*func)(struct irq_work *);
};
struct __attribute__((aligned((1 << (6))))) perf_sample_data {
    u64 addr;
    struct perf_raw_record *raw;
    struct perf_branch_stack *br_stack;
    u64 period;
    u64 weight;
    u64 txn;
    union perf_mem_data_src data_src;
    u64 type;
    u64 ip;
    struct {
        u32 pid;
        u32 tid;
    } tid_entry;
    u64 time;
    u64 id;
    u64 stream_id;
    struct {
        u32 cpu;
        u32 reserved;
    } cpu_entry;
    struct perf_callchain_entry *callchain;
    struct perf_regs regs_user;
    struct pt_regs regs_user_copy;
    struct perf_regs regs_intr;
    u64 stack_user_size;
    u64 phys_addr;
};
struct perf_callchain_entry {
    __u64 nr;
    __u64 ip[0];
};
typedef void (*perf_overflow_handler_t)(struct perf_event *, struct perf_sample_data *, struct pt_regs *);
struct trace_event_call {
    struct list_head list;
    struct trace_event_class *class;
    union {
        char *name;
        struct tracepoint *tp;
    };
    struct trace_event event;
    char *print_fmt;
    struct event_filter *filter;
    void *mod;
    void *data;
    int flags;
    int perf_refcount;
    struct hlist_head *perf_events;
    struct bpf_prog_array *prog_array;
    int (*perf_perm)(struct trace_event_call *, struct perf_event *);
};
struct perf_event_groups {
    struct rb_root tree;
    u64 index;
};
struct file_lock_operations {
    void (*fl_copy_lock)(struct file_lock *, struct file_lock *);
    void (*fl_release_private)(struct file_lock *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
struct nfs_lock_info {
    u32 state;
    struct nlm_lockowner *owner;
    struct list_head list;
};
struct file_ra_state {
    unsigned long start;
    unsigned int size;
    unsigned int async_size;
    unsigned int ra_pages;
    unsigned int mmap_miss;
    loff_t prev_pos;
};
typedef struct {
    projid_t val;
} kprojid_t;
struct mem_dqblk {
    qsize_t dqb_bhardlimit;
    qsize_t dqb_bsoftlimit;
    qsize_t dqb_curspace;
    qsize_t dqb_rsvspace;
    qsize_t dqb_ihardlimit;
    qsize_t dqb_isoftlimit;
    qsize_t dqb_curinodes;
    time64_t dqb_btime;
    time64_t dqb_itime;
};
struct qc_dqblk {
    int d_fieldmask;
    u64 d_spc_hardlimit;
    u64 d_spc_softlimit;
    u64 d_ino_hardlimit;
    u64 d_ino_softlimit;
    u64 d_space;
    u64 d_ino_count;
    s64 d_ino_timer;
    s64 d_spc_timer;
    int d_ino_warns;
    int d_spc_warns;
    u64 d_rt_spc_hardlimit;
    u64 d_rt_spc_softlimit;
    u64 d_rt_space;
    s64 d_rt_spc_timer;
    int d_rt_spc_warns;
};
struct quota_format_ops {
    int (*check_quota_file)(struct super_block *, int);
    int (*read_file_info)(struct super_block *, int);
    int (*write_file_info)(struct super_block *, int);
    int (*free_file_info)(struct super_block *, int);
    int (*read_dqblk)(struct dquot *);
    int (*commit_dqblk)(struct dquot *);
    int (*release_dqblk)(struct dquot *);
    int (*get_next_id)(struct super_block *, struct kqid *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
typedef struct {
    __u8 b[16];
} uuid_t;
typedef __kernel_dev_t dev_t;
struct kobject {
    const char *name;
    struct list_head entry;
    struct kobject *parent;
    struct kset;
    struct kset *kset;
    struct kobj_type;
    struct kobj_type *ktype;
    struct kernfs_node *sd;
    struct kref kref;
    unsigned int state_initialized : 1;
    unsigned int state_in_sysfs : 1;
    unsigned int state_add_uevent_sent : 1;
    unsigned int state_remove_uevent_sent : 1;
    unsigned int uevent_suppress : 1;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct kset_uevent_ops {
    int (*const filter)(struct kset *, struct kobject *);
    const char *(*const name)(struct kset *, struct kobject *);
    int (*const uevent)(struct kset *, struct kobject *, struct kobj_uevent_env *);
};
struct attribute_group {
    const char *name;
    umode_t (*is_visible)(struct kobject *, struct attribute *, int);
    umode_t (*is_bin_visible)(struct kobject *, struct bin_attribute *, int);
    struct attribute **attrs;
    struct bin_attribute **bin_attrs;
};
typedef atomic64_t atomic_long_t;
typedef struct raw_spinlock {
    arch_spinlock_t raw_lock;
} raw_spinlock_t;
struct kobj_ns_type_operations {
    enum kobj_ns_type type;
    bool (*current_may_mount)(void);
    void *(*grab_current_ns)(void);
    const void *(*netlink_ns)(struct sock *);
    const void *(*initial_ns)(void);
    void (*drop_ns)(void *);
};
struct kernfs_node {
    atomic_t count;
    atomic_t active;
    struct kernfs_node *parent;
    const char *name;
    struct rb_node rb;
    const void *ns;
    unsigned int hash;
    union {
        struct kernfs_elem_dir dir;
        struct kernfs_elem_symlink symlink;
        struct kernfs_elem_attr attr;
    };
    void *priv;
    union kernfs_node_id id;
    unsigned short flags;
    umode_t mode;
    struct kernfs_iattrs *iattr;
};
struct kernfs_syscall_ops {
    int (*show_options)(struct seq_file *, struct kernfs_root *);
    int (*mkdir)(struct kernfs_node *, const char *, umode_t);
    int (*rmdir)(struct kernfs_node *);
    int (*rename)(struct kernfs_node *, struct kernfs_node *, const char *);
    int (*show_path)(struct seq_file *, struct kernfs_node *, struct kernfs_root *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct kernel_param_ops {
    unsigned int flags;
    int (*set)(const char *, const struct kernel_param *);
    int (*get)(char *, const struct kernel_param *);
    void (*free)(void *);
};
struct mod_tree_node {
    struct module *mod;
    struct latch_tree_node node;
};
typedef int (*notifier_fn_t)(struct notifier_block *, unsigned long, void *);
struct old_timespec32 {
    old_time32_t tv_sec;
    s32 tv_nsec;
};
struct restart_block {
    long (*fn)(struct restart_block *);
    union {
        struct {
            u32 *uaddr;
            u32 val;
            u32 flags;
            u32 bitset;
            u64 time;
            u32 *uaddr2;
        } futex;
        struct {
            clockid_t clockid;
            enum timespec_type type;
            union {
                struct __kernel_timespec *rmtp;
                struct old_timespec32 *compat_rmtp;
            };
            u64 expires;
        } nanosleep;
        struct {
            struct pollfd *ufds;
            int nfds;
            int has_timeout;
            unsigned long tv_sec;
            unsigned long tv_nsec;
        } poll;
    };
};
struct fregs_state {
    u32 cwd;
    u32 swd;
    u32 twd;
    u32 fip;
    u32 fcs;
    u32 foo;
    u32 fos;
    u32 st_space[20];
    u32 status;
};
struct __attribute__((aligned(16))) fxregs_state {
    u16 cwd;
    u16 swd;
    u16 twd;
    u16 fop;
    union {
        struct {
            u64 rip;
            u64 rdp;
        };
        struct {
            u32 fip;
            u32 fcs;
            u32 foo;
            u32 fos;
        };
    };
    u32 mxcsr;
    u32 mxcsr_mask;
    u32 st_space[32];
    u32 xmm_space[64];
    u32 padding[12];
    union {
        u32 padding1[12];
        u32 sw_reserved[12];
    };
};
struct swregs_state {
    u32 cwd;
    u32 swd;
    u32 twd;
    u32 fip;
    u32 fcs;
    u32 foo;
    u32 fos;
    u32 st_space[20];
    u8 ftop;
    u8 changed;
    u8 lookahead;
    u8 no_update;
    u8 rm;
    u8 alimit;
    struct math_emu_info *info;
    u32 entry_eip;
};
struct __attribute__((packed)) xstate_header {
    u64 xfeatures;
    u64 xcomp_bv;
    u64 reserved[6];
};
typedef struct qrwlock {
    union {
        atomic_t cnts;
        struct {
            u8 wlocked;
            u8 __lstate[3];
        };
    };
    arch_spinlock_t wait_lock;
} arch_rwlock_t;
typedef struct cpumask cpumask_var_t[1];
struct tlbflush_unmap_batch {
    struct arch_tlbflush_unmap_batch arch;
    bool flush_required;
    bool writable;
};
struct uprobe_task {
    enum uprobe_task_state state;
    union {
        struct {
            struct arch_uprobe_task autask;
            unsigned long vaddr;
        };
        struct {
            struct callback_head dup_xol_work;
            unsigned long dup_xol_addr;
        };
    };
    struct uprobe;
    struct uprobe *active_uprobe;
    unsigned long xol_vaddr;
    struct return_instance;
    struct return_instance *return_instances;
    unsigned int depth;
};
struct fwnode_reference_args {
    struct fwnode_handle *fwnode;
    unsigned int nargs;
    u64 args[8];
};
struct vm_struct {
    struct vm_struct *next;
    void *addr;
    unsigned long size;
    unsigned long flags;
    struct page **pages;
    unsigned int nr_pages;
    phys_addr_t phys_addr;
    const void *caller;
};
struct ctl_table_header {
    union {
        struct {
            struct ctl_table *ctl_table;
            int used;
            int count;
            int nreg;
        };
        struct callback_head rcu;
    };
    struct completion *unregistering;
    struct ctl_table *ctl_table_arg;
    struct ctl_table_root *root;
    struct ctl_table_set;
    struct ctl_table_set *set;
    struct ctl_dir *parent;
    struct ctl_node *node;
    struct hlist_head inodes;
};
struct delayed_call {
    void (*fn)(void *);
    void *arg;
};
struct iattr {
    unsigned int ia_valid;
    umode_t ia_mode;
    kuid_t ia_uid;
    kgid_t ia_gid;
    loff_t ia_size;
    struct timespec64 ia_atime;
    struct timespec64 ia_mtime;
    struct timespec64 ia_ctime;
    struct file *ia_file;
};
struct file_system_type {
    const char *name;
    int fs_flags;
    int (*init_fs_context)(struct fs_context *);
    const struct fs_parameter_description *parameters;
    struct dentry *(*mount)(struct file_system_type *, int, const char *, void *);
    void *(*alloc_mnt_data)(void);
    void (*kill_sb)(struct super_block *);
    struct module *owner;
    struct file_system_type *next;
    struct hlist_head fs_supers;
    struct lock_class_key s_lock_key;
    struct lock_class_key s_umount_key;
    struct lock_class_key s_vfs_rename_key;
    struct lock_class_key s_writers_key[3];
    struct lock_class_key i_lock_key;
    struct lock_class_key i_mutex_key;
    struct lock_class_key i_mutex_dir_key;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct __attribute__((aligned((1 << (6))))) sched_avg {
    u64 last_update_time;
    u64 load_sum;
    u64 runnable_load_sum;
    u32 util_sum;
    u32 period_contrib;
    unsigned long load_avg;
    unsigned long runnable_load_avg;
    unsigned long util_avg;
    struct util_est util_est;
};
struct timerqueue_node {
    struct rb_node node;
    ktime_t expires;
};
typedef int32_t key_serial_t;
typedef uint32_t key_perm_t;
struct key_tag {
    struct callback_head rcu;
    refcount_t usage;
    bool removed;
};
typedef int (*key_restrict_link_func_t)(struct key *, const struct key_type *, const union key_payload *, struct key *);
struct ucounts {
    struct hlist_node node;
    struct user_namespace *ns;
    kuid_t uid;
    int count;
    atomic_t ucount[9];
};
struct cred {
    atomic_t usage;
    kuid_t uid;
    kgid_t gid;
    kuid_t suid;
    kgid_t sgid;
    kuid_t euid;
    kgid_t egid;
    kuid_t fsuid;
    kgid_t fsgid;
    unsigned int securebits;
    kernel_cap_t cap_inheritable;
    kernel_cap_t cap_permitted;
    kernel_cap_t cap_effective;
    kernel_cap_t cap_bset;
    kernel_cap_t cap_ambient;
    unsigned char jit_keyring;
    struct key *session_keyring;
    struct key *process_keyring;
    struct key *thread_keyring;
    struct key *request_key_auth;
    void *security;
    struct user_struct *user;
    struct user_namespace *user_ns;
    struct group_info *group_info;
    union {
        int non_rcu;
        struct callback_head rcu;
    };
};
struct css_set {
    struct cgroup_subsys_state *subsys[5];
    refcount_t refcount;
    struct css_set *dom_cset;
    struct cgroup *dfl_cgrp;
    int nr_tasks;
    struct list_head tasks;
    struct list_head mg_tasks;
    struct list_head dying_tasks;
    struct list_head task_iters;
    struct list_head e_cset_node[5];
    struct list_head threaded_csets;
    struct list_head threaded_csets_node;
    struct hlist_node hlist;
    struct list_head cgrp_links;
    struct list_head mg_preload_node;
    struct list_head mg_node;
    struct cgroup *mg_src_cgrp;
    struct cgroup *mg_dst_cgrp;
    struct css_set *mg_dst_cset;
    bool dead;
    struct callback_head callback_head;
};
struct cgroup_file {
    struct kernfs_node *kn;
    unsigned long notified_at;
    struct timer_list notify_timer;
};
struct cgroup_base_stat {
    struct task_cputime cputime;
};
struct kthread_work {
    struct list_head node;
    kthread_work_func_t func;
    struct kthread_worker *worker;
    int canceling;
};
struct bpf_prog_array {
    struct callback_head rcu;
    struct bpf_prog_array_item items[0];
};
struct bpf_cgroup_storage {
    union {
        struct bpf_storage_buffer *buf;
        void *percpu_buf;
    };
    struct bpf_cgroup_storage_map *map;
    struct bpf_cgroup_storage_key key;
    struct list_head list;
    struct rb_node node;
    struct callback_head rcu;
};
struct bpf_storage_buffer {
    struct callback_head rcu;
    char data[0];
};
struct task_cputime_atomic {
    atomic64_t utime;
    atomic64_t stime;
    atomic64_t sum_exec_runtime;
};
typedef __signalfn_t *__sighandler_t;
typedef __restorefn_t *__sigrestore_t;
struct io_cq {
    struct request_queue;
    struct request_queue *q;
    struct io_context *ioc;
    union {
        struct list_head q_node;
        struct kmem_cache *__rcu_icq_cache;
    };
    union {
        struct hlist_node ioc_node;
        struct callback_head __rcu_head;
    };
    unsigned int flags;
};
typedef struct kernel_siginfo {
    struct {
        int si_signo;
        int si_errno;
        int si_code;
        union __sifields _sifields;
    };
} kernel_siginfo_t;
struct bus_type {
    const char *name;
    const char *dev_name;
    struct device *dev_root;
    const struct attribute_group **bus_groups;
    const struct attribute_group **dev_groups;
    const struct attribute_group **drv_groups;
    int (*match)(struct device *, struct device_driver *);
    int (*uevent)(struct device *, struct kobj_uevent_env *);
    int (*probe)(struct device *);
    void (*sync_state)(struct device *);
    int (*remove)(struct device *);
    void (*shutdown)(struct device *);
    int (*online)(struct device *);
    int (*offline)(struct device *);
    int (*suspend)(struct device *, pm_message_t);
    int (*resume)(struct device *);
    int (*num_vf)(struct device *);
    int (*dma_configure)(struct device *);
    const struct dev_pm_ops *pm;
    const struct iommu_ops *iommu_ops;
    struct subsys_private *p;
    struct lock_class_key lock_key;
    bool need_parent_lock;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct device_driver {
    const char *name;
    struct bus_type *bus;
    struct module *owner;
    const char *mod_name;
    bool suppress_bind_attrs;
    enum probe_type probe_type;
    struct of_device_id;
    const struct of_device_id *of_match_table;
    struct acpi_device_id;
    const struct acpi_device_id *acpi_match_table;
    int (*probe)(struct device *);
    void (*sync_state)(struct device *);
    int (*remove)(struct device *);
    void (*shutdown)(struct device *);
    int (*suspend)(struct device *, pm_message_t);
    int (*resume)(struct device *);
    const struct attribute_group **groups;
    const struct attribute_group **dev_groups;
    const struct dev_pm_ops *pm;
    void (*coredump)(struct device *);
    struct driver_private *p;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct dev_pm_qos_request {
    enum dev_pm_qos_req_type type;
    union {
        struct plist_node pnode;
        struct pm_qos_flags_request flr;
        struct freq_qos_request freq;
    } data;
    struct device *dev;
};
struct dev_pm_domain {
    struct dev_pm_ops ops;
    void (*detach)(struct device *, bool);
    int (*activate)(struct device *);
    void (*sync)(struct device *);
    void (*dismiss)(struct device *);
};
typedef unsigned long (*perf_copy_f)(void *, const void *, unsigned long, unsigned long);
struct perf_branch_stack {
    __u64 nr;
    struct perf_branch_entry entries[0];
};
struct trace_event_class {
    const char *system;
    void *probe;
    void *perf_probe;
    int (*reg)(struct trace_event_call *, enum trace_reg, void *);
    int (*define_fields)(struct trace_event_call *);
    struct list_head *(*get_fields)(struct trace_event_call *);
    struct list_head fields;
    int (*raw_init)(struct trace_event_call *);
};
struct seq_buf {
    char *buffer;
    size_t size;
    size_t len;
    loff_t readpos;
};
typedef enum print_line_t (*trace_print_func)(struct trace_iterator *, int, struct trace_event *);
struct kqid {
    union {
        kuid_t uid;
        kgid_t gid;
        kprojid_t projid;
    };
    enum quota_type type;
};
struct qc_type_state {
    unsigned int flags;
    unsigned int spc_timelimit;
    unsigned int ino_timelimit;
    unsigned int rt_spc_timelimit;
    unsigned int spc_warnlimit;
    unsigned int ino_warnlimit;
    unsigned int rt_spc_warnlimit;
    unsigned long long ino;
    blkcnt_t blocks;
    blkcnt_t nextents;
};
struct __attribute__((aligned((1 << (6))))) dentry_operations {
    int (*d_revalidate)(struct dentry *, unsigned int);
    int (*d_weak_revalidate)(struct dentry *, unsigned int);
    int (*d_hash)(const struct dentry *, struct qstr *);
    int (*d_compare)(const struct dentry *, unsigned int, const char *, const struct qstr *);
    int (*d_delete)(const struct dentry *);
    int (*d_init)(struct dentry *);
    void (*d_release)(struct dentry *);
    void (*d_prune)(struct dentry *);
    void (*d_iput)(struct dentry *, struct inode *);
    char *(*d_dname)(struct dentry *, char *, int);
    struct vfsmount *(*d_automount)(struct path *);
    int (*d_manage)(const struct path *, bool);
    struct dentry *(*d_real)(struct dentry *, const struct inode *);
    void (*d_canonical_path)(const struct path *, struct path *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct list_lru_memcg {
    struct callback_head rcu;
    struct list_lru_one *lru[0];
};
struct module_kobject {
    struct kobject kobj;
    struct module *mod;
    struct kobject *drivers_dir;
    struct module_param_attrs;
    struct module_param_attrs *mp;
    struct completion *kobj_completion;
};
typedef struct spinlock {
    union {
        struct raw_spinlock rlock;
    };
} spinlock_t;
struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    struct vm_area_struct *vm_next;
    struct vm_area_struct *vm_prev;
    struct rb_node vm_rb;
    unsigned long rb_subtree_gap;
    struct mm_struct *vm_mm;
    pgprot_t vm_page_prot;
    unsigned long vm_flags;
    union {
        struct {
            struct rb_node rb;
            unsigned long rb_subtree_last;
        } shared;
        const char *anon_name;
    };
    struct list_head anon_vma_chain;
    struct anon_vma;
    struct anon_vma *anon_vma;
    struct vm_operations_struct;
    const struct vm_operations_struct *vm_ops;
    unsigned long vm_pgoff;
    struct file *vm_file;
    void *vm_private_data;
    atomic_long_t swap_readahead_info;
    struct vm_userfaultfd_ctx vm_userfaultfd_ctx;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
    u64 android_vendor_data1;
};
struct rw_semaphore {
    atomic_long_t count;
    atomic_long_t owner;
    struct optimistic_spin_queue osq;
    raw_spinlock_t wait_lock;
    struct list_head wait_list;
    u64 android_vendor_data1;
};
struct work_struct {
    atomic_long_t data;
    struct list_head entry;
    work_func_t func;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
struct module_layout {
    void *base;
    unsigned int size;
    unsigned int text_size;
    unsigned int ro_size;
    unsigned int ro_after_init_size;
    struct mod_tree_node mtn;
};
struct mod_kallsyms {
    Elf64_Sym *symtab;
    unsigned int num_symtab;
    char *strtab;
    char *typetab;
};
struct rcu_segcblist {
    struct callback_head *head;
    struct callback_head **tails[4];
    unsigned long gp_seq[4];
    atomic_long_t len;
    long len_lazy;
    u8 enabled;
    u8 offloaded;
};
struct notifier_block {
    notifier_fn_t notifier_call;
    struct notifier_block *next;
    int priority;
};
struct __attribute__((packed)) __attribute__((aligned(64))) xregs_state {
    struct fxregs_state i387;
    struct xstate_header header;
    u8 extended_state_area[0];
};
typedef struct {
    arch_rwlock_t raw_lock;
} rwlock_t;
struct kstat {
    u32 result_mask;
    umode_t mode;
    unsigned int nlink;
    uint32_t blksize;
    u64 attributes;
    u64 attributes_mask;
    u64 ino;
    dev_t dev;
    dev_t rdev;
    kuid_t uid;
    kgid_t gid;
    loff_t size;
    struct timespec64 atime;
    struct timespec64 mtime;
    struct timespec64 ctime;
    struct timespec64 btime;
    u64 blocks;
};
struct ctl_dir {
    struct ctl_table_header header;
    struct rb_root root;
};
typedef int (*filldir_t)(struct dir_context *, const char *, int, loff_t, u64, unsigned int);
struct sched_entity {
    struct load_weight load;
    unsigned long runnable_weight;
    struct rb_node run_node;
    struct list_head group_node;
    unsigned int on_rq;
    u64 exec_start;
    u64 sum_exec_runtime;
    u64 vruntime;
    u64 prev_sum_exec_runtime;
    u64 nr_migrations;
    struct sched_statistics statistics;
    struct sched_avg avg;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct hrtimer {
    struct timerqueue_node node;
    ktime_t _softexpires;
    enum hrtimer_restart (*function)(struct hrtimer *);
    struct hrtimer_clock_base *base;
    u8 state;
    u8 is_rel;
    u8 is_soft;
    u8 is_hard;
    u64 android_kabi_reserved1;
};
struct uid_gid_map {
    u32 nr_extents;
    union {
        struct uid_gid_extent extent[5];
        struct {
            struct uid_gid_extent *forward;
            struct uid_gid_extent *reverse;
        };
    };
};
struct ns_common {
    atomic_long_t stashed;
    const struct proc_ns_operations *ops;
    unsigned int inum;
};
struct key_restriction {
    key_restrict_link_func_t check;
    struct key *key;
    struct key_type *keytype;
};
struct prev_cputime {
    u64 utime;
    u64 stime;
    raw_spinlock_t lock;
};
struct posix_cputimers {
    struct posix_cputimer_base bases[3];
    unsigned int timers_active;
    unsigned int expiry_active;
};
struct ratelimit_state {
    raw_spinlock_t lock;
    int interval;
    int burst;
    int printed;
    int missed;
    unsigned long begin;
    unsigned long flags;
};
struct group_info {
    atomic_t usage;
    int ngroups;
    kgid_t gid[0];
};
struct percpu_ref {
    atomic_long_t count;
    unsigned long percpu_count_ptr;
    percpu_ref_func_t *release;
    percpu_ref_func_t *confirm_switch;
    bool force_atomic : 1;
    bool allow_reinit : 1;
    struct callback_head rcu;
};
struct cgroup_rstat_cpu {
    struct u64_stats_sync bsync;
    struct cgroup_base_stat bstat;
    struct cgroup_base_stat last_bstat;
    struct cgroup *updated_children;
    struct cgroup *updated_next;
};
struct psi_group_cpu {
    seqcount_t seq __attribute__((aligned((1 << (6)))));
    unsigned int tasks[3];
    u32 state_mask;
    u32 times[6];
    u64 state_start;
    u32 times_prev[2][6] __attribute__((aligned((1 << (6)))));
};
struct kthread_worker {
    unsigned int flags;
    raw_spinlock_t lock;
    struct list_head work_list;
    struct list_head delayed_work_list;
    struct task_struct *task;
    struct kthread_work *current_work;
};
struct kthread_delayed_work {
    struct kthread_work work;
    struct timer_list timer;
};
struct thread_group_cputimer {
    struct task_cputime_atomic cputime_atomic;
};
struct sigaction {
    __sighandler_t sa_handler;
    unsigned long sa_flags;
    __sigrestore_t sa_restorer;
    sigset_t sa_mask;
};
struct pmu {
    struct list_head entry;
    struct module *module;
    struct device *dev;
    const struct attribute_group **attr_groups;
    const struct attribute_group **attr_update;
    const char *name;
    int type;
    int capabilities;
    int *pmu_disable_count;
    struct perf_cpu_context;
    struct perf_cpu_context *pmu_cpu_context;
    atomic_t exclusive_cnt;
    int task_ctx_nr;
    int hrtimer_interval_ms;
    unsigned int nr_addr_filters;
    void (*pmu_enable)(struct pmu *);
    void (*pmu_disable)(struct pmu *);
    int (*event_init)(struct perf_event *);
    void (*event_mapped)(struct perf_event *, struct mm_struct *);
    void (*event_unmapped)(struct perf_event *, struct mm_struct *);
    int (*add)(struct perf_event *, int);
    void (*del)(struct perf_event *, int);
    void (*start)(struct perf_event *, int);
    void (*stop)(struct perf_event *, int);
    void (*read)(struct perf_event *);
    void (*start_txn)(struct pmu *, unsigned int);
    int (*commit_txn)(struct pmu *);
    void (*cancel_txn)(struct pmu *);
    int (*event_idx)(struct perf_event *);
    void (*sched_task)(struct perf_event_context *, bool);
    size_t task_ctx_size;
    void *(*setup_aux)(struct perf_event *, void **, int, bool);
    void (*free_aux)(void *);
    int (*addr_filters_validate)(struct list_head *);
    void (*addr_filters_sync)(struct perf_event *);
    int (*aux_output_match)(struct perf_event *);
    int (*filter_match)(struct perf_event *);
    int (*check_period)(struct perf_event *, u64);
};
typedef struct {
    atomic_long_t a;
} local_t;
struct perf_addr_filters_head {
    struct list_head list;
    raw_spinlock_t lock;
    unsigned int nr_file_filters;
};
struct __attribute__((packed)) perf_raw_frag {
    union {
        struct perf_raw_frag *next;
        unsigned long pad;
    };
    perf_copy_f copy;
    void *data;
    u32 size;
};
struct trace_event_functions {
    trace_print_func trace;
    trace_print_func raw;
    trace_print_func hex;
    trace_print_func binary;
};
struct trace_seq {
    unsigned char buffer[4096];
    struct seq_buf seq;
    int full;
};
struct lock_manager_operations {
    fl_owner_t (*lm_get_owner)(fl_owner_t);
    void (*lm_put_owner)(fl_owner_t);
    void (*lm_notify)(struct file_lock *);
    int (*lm_grant)(struct file_lock *, int);
    bool (*lm_break)(struct file_lock *);
    int (*lm_change)(struct file_lock *, int, struct list_head *);
    void (*lm_setup)(struct file_lock *, void **);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
struct kset {
    struct list_head list;
    spinlock_t list_lock;
    struct kobject kobj;
    const struct kset_uevent_ops *uevent_ops;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct sysfs_ops {
    ssize_t (*show)(struct kobject *, struct attribute *, char *);
    ssize_t (*store)(struct kobject *, struct attribute *, const char *, size_t);
};
struct bin_attribute {
    struct attribute attr;
    size_t size;
    void *private;
    ssize_t (*read)(struct file *, struct kobject *, struct bin_attribute *, char *, loff_t, size_t);
    ssize_t (*write)(struct file *, struct kobject *, struct bin_attribute *, char *, loff_t, size_t);
    int (*mmap)(struct file *, struct kobject *, struct bin_attribute *, struct vm_area_struct *);
};
struct mm_rss_stat {
    atomic_long_t count[4];
};
struct mutex {
    atomic_long_t owner;
    spinlock_t wait_lock;
    struct optimistic_spin_queue osq;
    struct list_head wait_list;
};
struct wait_queue_head {
    spinlock_t lock;
    struct list_head head;
};
struct xarray {
    spinlock_t xa_lock;
    gfp_t xa_flags;
    void *xa_head;
};
struct kernfs_ops {
    int (*open)(struct kernfs_open_file *);
    void (*release)(struct kernfs_open_file *);
    int (*seq_show)(struct seq_file *, void *);
    void *(*seq_start)(struct seq_file *, loff_t *);
    void *(*seq_next)(struct seq_file *, void *, loff_t *);
    void (*seq_stop)(struct seq_file *, void *);
    ssize_t (*read)(struct kernfs_open_file *, char *, size_t, loff_t);
    size_t atomic_write_len;
    bool prealloc;
    ssize_t (*write)(struct kernfs_open_file *, char *, size_t, loff_t);
    __poll_t (*poll)(struct kernfs_open_file *, struct poll_table_struct *);
    int (*mmap)(struct kernfs_open_file *, struct vm_area_struct *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
struct module_attribute {
    struct attribute attr;
    ssize_t (*show)(struct module_attribute *, struct module_kobject *, char *);
    ssize_t (*store)(struct module_attribute *, struct module_kobject *, const char *, size_t);
    void (*setup)(struct module *, const char *);
    int (*test)(struct module *);
    void (*free)(struct module *);
};
struct srcu_node {
    spinlock_t lock;
    unsigned long srcu_have_cbs[4];
    unsigned long srcu_data_have_cbs[4];
    unsigned long srcu_gp_seq_needed_exp;
    struct srcu_node *srcu_parent;
    int grplo;
    int grphi;
};
struct srcu_data {
    unsigned long srcu_lock_count[2];
    unsigned long srcu_unlock_count[2];
    spinlock_t lock __attribute__((aligned(1 << (6))));
    struct rcu_segcblist srcu_cblist;
    unsigned long srcu_gp_seq_needed;
    unsigned long srcu_gp_seq_needed_exp;
    bool srcu_cblist_invoking;
    struct timer_list delay_work;
    struct work_struct work;
    struct callback_head srcu_barrier_head;
    struct srcu_node *mynode;
    unsigned long grpmask;
    int cpu;
    struct srcu_struct *ssp;
};
struct delayed_work {
    struct work_struct work;
    struct timer_list timer;
    struct workqueue_struct *wq;
    int cpu;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
typedef int (proc_handler)(struct ctl_table *, int, void *, size_t *, loff_t *);
struct __attribute__((aligned(2 * sizeof(unsigned long)))) page {
    unsigned long flags;
    union {
        struct {
            struct list_head lru;
            struct address_space *mapping;
            unsigned long index;
            unsigned long private;
        };
        struct {
            dma_addr_t dma_addr;
        };
        struct {
            union {
                struct list_head slab_list;
                struct {
                    struct page *next;
                    int pages;
                    int pobjects;
                };
            };
            struct kmem_cache;
            struct kmem_cache *slab_cache;
            void *freelist;
            union {
                void *s_mem;
                unsigned long counters;
                struct {
                    unsigned int inuse : 16;
                    unsigned int objects : 15;
                    unsigned int frozen : 1;
                };
            };
        };
        struct {
            unsigned long compound_head;
            unsigned char compound_dtor;
            unsigned char compound_order;
            atomic_t compound_mapcount;
        };
        struct {
            unsigned long _compound_pad_1;
            unsigned long _compound_pad_2;
            struct list_head deferred_list;
        };
        struct {
            unsigned long _pt_pad_1;
            pgtable_t pmd_huge_pte;
            unsigned long _pt_pad_2;
            union {
                struct mm_struct *pt_mm;
                atomic_t pt_frag_refcount;
            };
            spinlock_t ptl;
        };
        struct {
            struct dev_pagemap;
            struct dev_pagemap *pgmap;
            void *zone_device_data;
        };
        struct callback_head callback_head;
    };
    union {
        atomic_t _mapcount;
        unsigned int page_type;
        unsigned int active;
        int units;
    };
    atomic_t _refcount;
    struct mem_cgroup *mem_cgroup;
};
union fpregs_state {
    struct fregs_state fsave;
    struct fxregs_state fxsave;
    struct swregs_state soft;
    struct xregs_state xsave;
    u8 __padding[4096];
};
typedef struct {
    struct seqcount seqcount;
    spinlock_t lock;
} seqlock_t;
struct rcu_work {
    struct work_struct work;
    struct callback_head rcu;
    struct workqueue_struct *wq;
};
struct blocking_notifier_head {
    struct rw_semaphore rwsem;
    struct notifier_block *head;
};
struct fwnode_operations {
    struct fwnode_handle *(*get)(struct fwnode_handle *);
    void (*put)(struct fwnode_handle *);
    bool (*device_is_available)(const struct fwnode_handle *);
    const void *(*device_get_match_data)(const struct fwnode_handle *, const struct device *);
    bool (*property_present)(const struct fwnode_handle *, const char *);
    int (*property_read_int_array)(const struct fwnode_handle *, const char *, unsigned int, void *, size_t);
    int (*property_read_string_array)(const struct fwnode_handle *, const char *, const char **, size_t);
    struct fwnode_handle *(*get_parent)(const struct fwnode_handle *);
    struct fwnode_handle *(*get_next_child_node)(const struct fwnode_handle *, struct fwnode_handle *);
    struct fwnode_handle *(*get_named_child_node)(const struct fwnode_handle *, const char *);
    int (*get_reference_args)(const struct fwnode_handle *, const char *, const char *, unsigned int, unsigned int, struct fwnode_reference_args *);
    struct fwnode_handle *(*graph_get_next_endpoint)(const struct fwnode_handle *, struct fwnode_handle *);
    struct fwnode_handle *(*graph_get_remote_endpoint)(const struct fwnode_handle *);
    struct fwnode_handle *(*graph_get_port_parent)(struct fwnode_handle *);
    int (*graph_parse_endpoint)(const struct fwnode_handle *, struct fwnode_endpoint *);
    int (*add_links)(const struct fwnode_handle *, struct device *);
};
struct ctl_table_set {
    int (*is_seen)(struct ctl_table_set *);
    struct ctl_dir dir;
};
struct seq_operations {
    void *(*start)(struct seq_file *, loff_t *);
    void (*stop)(struct seq_file *, void *);
    void *(*next)(struct seq_file *, void *, loff_t *);
    int (*show)(struct seq_file *, void *);
};
struct file_operations {
    struct module *owner;
    loff_t (*llseek)(struct file *, loff_t, int);
    ssize_t (*read)(struct file *, char *, size_t, loff_t *);
    ssize_t (*write)(struct file *, const char *, size_t, loff_t *);
    ssize_t (*read_iter)(struct kiocb *, struct iov_iter *);
    ssize_t (*write_iter)(struct kiocb *, struct iov_iter *);
    int (*iopoll)(struct kiocb *, bool);
    int (*iterate)(struct file *, struct dir_context *);
    int (*iterate_shared)(struct file *, struct dir_context *);
    __poll_t (*poll)(struct file *, struct poll_table_struct *);
    long (*unlocked_ioctl)(struct file *, unsigned int, unsigned long);
    long (*compat_ioctl)(struct file *, unsigned int, unsigned long);
    int (*mmap)(struct file *, struct vm_area_struct *);
    unsigned long mmap_supported_flags;
    int (*open)(struct inode *, struct file *);
    int (*flush)(struct file *, fl_owner_t);
    int (*release)(struct inode *, struct file *);
    int (*fsync)(struct file *, loff_t, loff_t, int);
    int (*fasync)(int, struct file *, int);
    int (*lock)(struct file *, int, struct file_lock *);
    ssize_t (*sendpage)(struct file *, struct page *, int, size_t, loff_t *, int);
    unsigned long (*get_unmapped_area)(struct file *, unsigned long, unsigned long, unsigned long, unsigned long);
    int (*check_flags)(int);
    int (*flock)(struct file *, int, struct file_lock *);
    ssize_t (*splice_write)(struct pipe_inode_info *, struct file *, loff_t *, size_t, unsigned int);
    ssize_t (*splice_read)(struct file *, loff_t *, struct pipe_inode_info *, size_t, unsigned int);
    int (*setlease)(struct file *, long, struct file_lock **, void **);
    long (*fallocate)(struct file *, int, loff_t, loff_t);
    void (*show_fdinfo)(struct seq_file *, struct file *);
    ssize_t (*copy_file_range)(struct file *, loff_t, struct file *, loff_t, size_t, unsigned int);
    loff_t (*remap_file_range)(struct file *, loff_t, struct file *, loff_t, loff_t, unsigned int);
    int (*fadvise)(struct file *, loff_t, loff_t, int);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct dir_context {
    filldir_t actor;
    loff_t pos;
};
struct sched_dl_entity {
    struct rb_node rb_node;
    u64 dl_runtime;
    u64 dl_deadline;
    u64 dl_period;
    u64 dl_bw;
    u64 dl_density;
    s64 runtime;
    u64 deadline;
    unsigned int flags;
    unsigned int dl_throttled : 1;
    unsigned int dl_boosted : 1;
    unsigned int dl_yielded : 1;
    unsigned int dl_non_contending : 1;
    unsigned int dl_overrun : 1;
    struct hrtimer dl_timer;
    struct hrtimer inactive_timer;
};
struct __attribute__((aligned((1 << (6))))) hrtimer_clock_base {
    struct hrtimer_cpu_base *cpu_base;
    unsigned int index;
    clockid_t clockid;
    seqcount_t seq;
    struct hrtimer *running;
    struct timerqueue_head active;
    ktime_t (*get_time)(void);
    ktime_t offset;
};
struct key {
    refcount_t usage;
    key_serial_t serial;
    union {
        struct list_head graveyard_link;
        struct rb_node serial_node;
    };
    struct rw_semaphore sem;
    struct key_user;
    struct key_user *user;
    void *security;
    union {
        time64_t expiry;
        time64_t revoked_at;
    };
    time64_t last_used_at;
    kuid_t uid;
    kgid_t gid;
    key_perm_t perm;
    unsigned short quotalen;
    unsigned short datalen;
    short state;
    unsigned long flags;
    union {
        struct keyring_index_key index_key;
        struct {
            unsigned long hash;
            unsigned long len_desc;
            struct key_type *type;
            struct key_tag *domain_tag;
            char *description;
        };
    };
    union {
        union key_payload payload;
        struct {
            struct list_head name_link;
            struct assoc_array keys;
        };
    };
    struct key_restriction *restrict_link;
};
struct user_struct {
    refcount_t __count;
    atomic_t processes;
    atomic_t sigpending;
    atomic_long_t epoll_watches;
    unsigned long locked_shm;
    unsigned long unix_inflight;
    atomic_long_t pipe_bufs;
    struct hlist_node uidhash_node;
    kuid_t uid;
    atomic_long_t locked_vm;
    struct ratelimit_state ratelimit;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
struct cgroup_namespace {
    refcount_t count;
    struct ns_common ns;
    struct user_namespace *user_ns;
    struct ucounts *ucounts;
    struct css_set *root_cset;
};
struct cgroup_bpf {
    struct bpf_prog_array *effective[23];
    struct list_head progs[23];
    u32 flags[23];
    struct bpf_prog_array *inactive;
    struct percpu_ref refcnt;
    struct work_struct release_work;
};
struct cftype {
    char name[64];
    unsigned long private;
    size_t max_write_len;
    unsigned int flags;
    unsigned int file_offset;
    struct cgroup_subsys *ss;
    struct list_head node;
    struct kernfs_ops *kf_ops;
    int (*open)(struct kernfs_open_file *);
    void (*release)(struct kernfs_open_file *);
    u64 (*read_u64)(struct cgroup_subsys_state *, struct cftype *);
    s64 (*read_s64)(struct cgroup_subsys_state *, struct cftype *);
    int (*seq_show)(struct seq_file *, void *);
    void *(*seq_start)(struct seq_file *, loff_t *);
    void *(*seq_next)(struct seq_file *, void *, loff_t *);
    void (*seq_stop)(struct seq_file *, void *);
    int (*write_u64)(struct cgroup_subsys_state *, struct cftype *, u64);
    int (*write_s64)(struct cgroup_subsys_state *, struct cftype *, s64);
    ssize_t (*write)(struct kernfs_open_file *, char *, size_t, loff_t);
    __poll_t (*poll)(struct kernfs_open_file *, struct poll_table_struct *);
};
struct k_sigaction {
    struct sigaction sa;
};
struct wakeup_source {
    const char *name;
    int id;
    struct list_head entry;
    spinlock_t lock;
    struct wake_irq *wakeirq;
    struct timer_list timer;
    unsigned long timer_expires;
    ktime_t total_time;
    ktime_t max_time;
    ktime_t last_time;
    ktime_t start_prevent_time;
    ktime_t prevent_sleep_time;
    unsigned long event_count;
    unsigned long active_count;
    unsigned long relax_count;
    unsigned long expire_count;
    unsigned long wakeup_count;
    struct device *dev;
    bool active : 1;
    bool autosleep_enabled : 1;
};
struct pm_subsys_data {
    spinlock_t lock;
    unsigned int refcount;
    struct list_head clock_list;
};
typedef struct {
    local_t a;
} local64_t;
struct fasync_struct {
    rwlock_t fa_lock;
    int magic;
    int fa_fd;
    struct fasync_struct *fa_next;
    struct file *fa_file;
    struct callback_head fa_rcu;
};
struct perf_raw_record {
    struct perf_raw_frag frag;
    u32 size;
};
struct fown_struct {
    rwlock_t lock;
    struct pid *pid;
    enum pid_type pid_type;
    kuid_t uid;
    kuid_t euid;
    int signum;
};
struct super_operations {
    struct inode *(*alloc_inode)(struct super_block *);
    void (*destroy_inode)(struct inode *);
    void (*free_inode)(struct inode *);
    void (*dirty_inode)(struct inode *, int);
    int (*write_inode)(struct inode *, struct writeback_control *);
    int (*drop_inode)(struct inode *);
    void (*evict_inode)(struct inode *);
    void (*put_super)(struct super_block *);
    int (*sync_fs)(struct super_block *, int);
    int (*freeze_super)(struct super_block *);
    int (*freeze_fs)(struct super_block *);
    int (*thaw_super)(struct super_block *);
    int (*unfreeze_fs)(struct super_block *);
    int (*statfs)(struct dentry *, struct kstatfs *);
    int (*remount_fs)(struct super_block *, int *, char *);
    void *(*clone_mnt_data)(void *);
    void (*copy_mnt_data)(void *, void *);
    void (*update_mnt_data)(void *, struct fs_context *);
    void (*umount_begin)(struct super_block *);
    int (*show_options)(struct seq_file *, struct dentry *);
    int (*show_options2)(struct vfsmount *, struct seq_file *, struct dentry *);
    int (*show_devname)(struct seq_file *, struct dentry *);
    int (*show_path)(struct seq_file *, struct dentry *);
    int (*show_stats)(struct seq_file *, struct dentry *);
    ssize_t (*quota_read)(struct super_block *, int, char *, size_t, loff_t);
    ssize_t (*quota_write)(struct super_block *, int, const char *, size_t, loff_t);
    struct dquot **(*get_dquots)(struct inode *);
    int (*bdev_try_to_free_page)(struct super_block *, struct page *, gfp_t);
    long (*nr_cached_objects)(struct super_block *, struct shrink_control *);
    long (*free_cached_objects)(struct super_block *, struct shrink_control *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct qc_state {
    unsigned int s_incoredqs;
    struct qc_type_state s_state[3];
};
struct quota_info {
    unsigned int flags;
    struct rw_semaphore dqio_sem;
    struct inode *files[3];
    struct mem_dqinfo info[3];
    const struct quota_format_ops *ops[3];
};
struct lockref {
    union {
        __u64 lock_count __attribute__((aligned(8)));
        struct {
            spinlock_t lock;
            int count;
        };
    };
};
struct file_lock_context {
    spinlock_t flc_lock;
    struct list_head flc_flock;
    struct list_head flc_posix;
    struct list_head flc_lease;
};
struct shrinker {
    unsigned long (*count_objects)(struct shrinker *, struct shrink_control *);
    unsigned long (*scan_objects)(struct shrinker *, struct shrink_control *);
    long batch;
    int seeks;
    unsigned int flags;
    struct list_head list;
    int id;
    atomic_long_t *nr_deferred;
};
struct __attribute__((aligned((1 << (6))))) list_lru_node {
    spinlock_t lock;
    struct list_lru_one lru;
    struct list_lru_memcg *memcg_lrus;
    long nr_items;
};
struct __attribute__((aligned((1 << (6))))) module {
    enum module_state state;
    struct list_head list;
    char name[56];
    struct module_kobject mkobj;
    struct module_attribute *modinfo_attrs;
    const char *version;
    const char *srcversion;
    struct kobject *holders_dir;
    const struct kernel_symbol *syms;
    const s32 *crcs;
    unsigned int num_syms;
    struct mutex param_lock;
    struct kernel_param *kp;
    unsigned int num_kp;
    unsigned int num_gpl_syms;
    const struct kernel_symbol *gpl_syms;
    const s32 *gpl_crcs;
    bool using_gplonly_symbols;
    const struct kernel_symbol *unused_syms;
    const s32 *unused_crcs;
    unsigned int num_unused_syms;
    unsigned int num_unused_gpl_syms;
    const struct kernel_symbol *unused_gpl_syms;
    const s32 *unused_gpl_crcs;
    bool sig_ok;
    bool async_probe_requested;
    const struct kernel_symbol *gpl_future_syms;
    const s32 *gpl_future_crcs;
    unsigned int num_gpl_future_syms;
    unsigned int num_exentries;
    struct exception_table_entry *extable;
    int (*init)(void);
    struct module_layout core_layout __attribute__((aligned((1 << (6)))));
    struct module_layout init_layout;
    struct mod_arch_specific arch;
    unsigned long taints;
    unsigned int num_bugs;
    struct list_head bug_list;
    struct bug_entry *bug_table;
    struct mod_kallsyms *kallsyms;
    struct mod_kallsyms core_kallsyms;
    struct module_sect_attrs;
    struct module_sect_attrs *sect_attrs;
    struct module_notes_attrs;
    struct module_notes_attrs *notes_attrs;
    char *args;
    void *percpu;
    unsigned int percpu_size;
    unsigned int num_tracepoints;
    tracepoint_ptr_t *tracepoints_ptrs;
    unsigned int num_srcu_structs;
    struct srcu_struct **srcu_struct_ptrs;
    unsigned int num_bpf_raw_events;
    struct bpf_raw_event_map *bpf_raw_events;
    struct jump_entry *jump_entries;
    unsigned int num_jump_entries;
    unsigned int num_trace_bprintk_fmt;
    const char **trace_bprintk_fmt_start;
    struct trace_event_call;
    struct trace_event_call **trace_events;
    unsigned int num_trace_events;
    struct trace_eval_map;
    struct trace_eval_map **trace_evals;
    unsigned int num_trace_evals;
    struct list_head source_list;
    struct list_head target_list;
    void (*exit)(void);
    atomic_t refcnt;
    struct error_injection_entry *ei_funcs;
    unsigned int num_ei_funcs;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct kobj_type {
    void (*release)(struct kobject *);
    const struct sysfs_ops *sysfs_ops;
    struct attribute **default_attrs;
    const struct attribute_group **default_groups;
    const struct kobj_ns_type_operations *(*child_ns_type)(struct kobject *);
    const void *(*namespace)(struct kobject *);
    void (*get_ownership)(struct kobject *, kuid_t *, kgid_t *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
typedef struct {
    u64 ctx_id;
    atomic64_t tlb_gen;
    struct rw_semaphore ldt_usr_sem;
    struct ldt_struct;
    struct ldt_struct *ldt;
    unsigned short ia32_compat;
    struct mutex lock;
    void *vdso;
    struct vdso_image;
    const struct vdso_image *vdso_image;
    atomic_t perf_rdpmc_allowed;
    u16 pkey_allocation_map;
    s16 execute_only_pkey;
} mm_context_t;
typedef struct wait_queue_head wait_queue_head_t;
struct idr {
    struct xarray idr_rt;
    unsigned int idr_base;
    unsigned int idr_next;
};
struct kernfs_open_file {
    struct kernfs_node *kn;
    struct file *file;
    struct seq_file *seq_file;
    void *priv;
    struct mutex mutex;
    struct mutex prealloc_mutex;
    int event;
    struct list_head list;
    char *prealloc_buf;
    size_t atomic_write_len;
    bool mmapped : 1;
    bool released : 1;
    const struct vm_operations_struct *vm_ops;
};
struct fpu {
    unsigned int last_cpu;
    unsigned long avx512_timestamp;
    union fpregs_state state;
};
struct ctl_table_root {
    struct ctl_table_set default_set;
    struct ctl_table_set *(*lookup)(struct ctl_table_root *);
    void (*set_ownership)(struct ctl_table_header *, struct ctl_table *, kuid_t *, kgid_t *);
    int (*permissions)(struct ctl_table_header *, struct ctl_table *);
};
struct __attribute__((aligned(4))) file {
    union {
        struct llist_node fu_llist;
        struct callback_head fu_rcuhead;
    } f_u;
    struct path f_path;
    struct inode *f_inode;
    const struct file_operations *f_op;
    spinlock_t f_lock;
    enum rw_hint f_write_hint;
    atomic_long_t f_count;
    unsigned int f_flags;
    fmode_t f_mode;
    struct mutex f_pos_lock;
    loff_t f_pos;
    struct fown_struct f_owner;
    const struct cred *f_cred;
    struct file_ra_state f_ra;
    u64 f_version;
    void *f_security;
    void *private_data;
    struct list_head f_ep_links;
    struct list_head f_tfile_llink;
    struct address_space *f_mapping;
    errseq_t f_wb_err;
    u64 android_kabi_reserved1;
    u64 android_vendor_data1;
};
struct __attribute__((aligned((1 << (6))))) inode_operations {
    struct dentry *(*lookup)(struct inode *, struct dentry *, unsigned int);
    const char *(*get_link)(struct dentry *, struct inode *, struct delayed_call *);
    int (*permission)(struct inode *, int);
    struct posix_acl *(*get_acl)(struct inode *, int);
    int (*readlink)(struct dentry *, char *, int);
    int (*create)(struct inode *, struct dentry *, umode_t, bool);
    int (*link)(struct dentry *, struct inode *, struct dentry *);
    int (*unlink)(struct inode *, struct dentry *);
    int (*symlink)(struct inode *, struct dentry *, const char *);
    int (*mkdir)(struct inode *, struct dentry *, umode_t);
    int (*rmdir)(struct inode *, struct dentry *);
    int (*mknod)(struct inode *, struct dentry *, umode_t, dev_t);
    int (*rename)(struct inode *, struct dentry *, struct inode *, struct dentry *, unsigned int);
    int (*setattr)(struct dentry *, struct iattr *);
    int (*getattr)(const struct path *, struct kstat *, u32, unsigned int);
    ssize_t (*listxattr)(struct dentry *, char *, size_t);
    int (*fiemap)(struct inode *, struct fiemap_extent_info *, u64, u64);
    int (*update_time)(struct inode *, struct timespec64 *, int);
    int (*atomic_open)(struct inode *, struct dentry *, struct file *, unsigned int, umode_t);
    int (*tmpfile)(struct inode *, struct dentry *, umode_t);
    int (*set_acl)(struct inode *, struct posix_acl *, int);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct seq_file {
    char *buf;
    size_t size;
    size_t from;
    size_t count;
    size_t pad_until;
    loff_t index;
    loff_t read_pos;
    u64 version;
    struct mutex lock;
    const struct seq_operations *op;
    int poll_event;
    const struct file *file;
    void *private;
};
struct user_namespace {
    struct uid_gid_map uid_map;
    struct uid_gid_map gid_map;
    struct uid_gid_map projid_map;
    atomic_t count;
    struct user_namespace *parent;
    int level;
    kuid_t owner;
    kgid_t group;
    struct ns_common ns;
    unsigned long flags;
    struct list_head keyring_name_list;
    struct key *user_keyring_register;
    struct rw_semaphore keyring_sem;
    struct work_struct work;
    struct ctl_table_set set;
    struct ctl_table_header *sysctls;
    struct ucounts *ucounts;
    int ucount_max[9];
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
struct cgroup_subsys_state {
    struct cgroup *cgroup;
    struct cgroup_subsys *ss;
    struct percpu_ref refcnt;
    struct list_head sibling;
    struct list_head children;
    struct list_head rstat_css_node;
    int id;
    unsigned int flags;
    u64 serial_nr;
    atomic_t online_cnt;
    struct work_struct destroy_work;
    struct rcu_work destroy_rwork;
    struct cgroup_subsys_state *parent;
};
struct __attribute__((aligned(sizeof(long)))) address_space {
    struct inode *host;
    struct xarray i_pages;
    gfp_t gfp_mask;
    atomic_t i_mmap_writable;
    struct rb_root_cached i_mmap;
    struct rw_semaphore i_mmap_rwsem;
    unsigned long nrpages;
    unsigned long nrexceptional;
    unsigned long writeback_index;
    const struct address_space_operations *a_ops;
    unsigned long flags;
    errseq_t wb_err;
    spinlock_t private_lock;
    struct list_head private_list;
    void *private_data;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct address_space_operations {
    int (*writepage)(struct page *, struct writeback_control *);
    int (*readpage)(struct file *, struct page *);
    int (*writepages)(struct address_space *, struct writeback_control *);
    int (*set_page_dirty)(struct page *);
    int (*readpages)(struct file *, struct address_space *, struct list_head *, unsigned int);
    int (*write_begin)(struct file *, struct address_space *, loff_t, unsigned int, unsigned int, struct page **, void **);
    int (*write_end)(struct file *, struct address_space *, loff_t, unsigned int, unsigned int, struct page *, void *);
    sector_t (*bmap)(struct address_space *, sector_t);
    void (*invalidatepage)(struct page *, unsigned int, unsigned int);
    int (*releasepage)(struct page *, gfp_t);
    void (*freepage)(struct page *);
    ssize_t (*direct_IO)(struct kiocb *, struct iov_iter *);
    int (*migratepage)(struct address_space *, struct page *, struct page *, enum migrate_mode);
    bool (*isolate_page)(struct page *, isolate_mode_t);
    void (*putback_page)(struct page *);
    int (*launder_page)(struct page *);
    int (*is_partially_uptodate)(struct page *, unsigned long, unsigned long);
    void (*is_dirty_writeback)(struct page *, bool *, bool *);
    int (*error_remove_page)(struct address_space *, struct page *);
    int (*swap_activate)(struct swap_info_struct *, struct file *, sector_t *);
    void (*swap_deactivate)(struct file *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct psi_group {
    struct mutex avgs_lock;
    struct psi_group_cpu *pcpu;
    u64 avg_total[5];
    u64 avg_last_update;
    u64 avg_next_update;
    struct delayed_work avgs_work;
    u64 total[2][5];
    unsigned long avg[5][3];
    atomic_t poll_scheduled;
    struct kthread_worker *poll_kworker;
    struct kthread_delayed_work poll_work;
    struct mutex trigger_lock;
    struct list_head triggers;
    u32 nr_triggers[5];
    u32 poll_states;
    u64 poll_min_period;
    u64 polling_total[5];
    u64 polling_next_update;
    u64 polling_until;
};
struct io_context {
    atomic_long_t refcount;
    atomic_t active_ref;
    atomic_t nr_tasks;
    spinlock_t lock;
    unsigned short ioprio;
    int nr_batch_requests;
    unsigned long last_waited;
    struct xarray icq_tree;
    struct io_cq *icq_hint;
    struct hlist_head icq_list;
    struct work_struct release_work;
};
struct perf_event_context {
    struct pmu *pmu;
    raw_spinlock_t lock;
    struct mutex mutex;
    struct list_head active_ctx_list;
    struct perf_event_groups pinned_groups;
    struct perf_event_groups flexible_groups;
    struct list_head event_list;
    struct list_head pinned_active;
    struct list_head flexible_active;
    int nr_events;
    int nr_active;
    int is_active;
    int nr_stat;
    int nr_freq;
    int rotate_disable;
    int rotate_necessary;
    refcount_t refcount;
    struct task_struct *task;
    u64 time;
    u64 timestamp;
    struct perf_event_context *parent_ctx;
    u64 parent_gen;
    u64 generation;
    int pin_count;
    void *task_ctx_data;
    struct callback_head callback_head;
};
struct device_type {
    const char *name;
    const struct attribute_group **groups;
    int (*uevent)(struct device *, struct kobj_uevent_env *);
    char *(*devnode)(struct device *, umode_t *, kuid_t *, kgid_t *);
    void (*release)(struct device *);
    const struct dev_pm_ops *pm;
};
struct freq_constraints {
    struct pm_qos_constraints min_freq;
    struct blocking_notifier_head min_freq_notifiers;
    struct pm_qos_constraints max_freq;
    struct blocking_notifier_head max_freq_notifiers;
};
struct class {
    const char *name;
    struct module *owner;
    const struct attribute_group **class_groups;
    const struct attribute_group **dev_groups;
    struct kobject *dev_kobj;
    int (*dev_uevent)(struct device *, struct kobj_uevent_env *);
    char *(*devnode)(struct device *, umode_t *);
    void (*class_release)(struct class *);
    void (*dev_release)(struct device *);
    int (*shutdown_pre)(struct device *);
    const struct kobj_ns_type_operations *ns_type;
    const void *(*namespace)(struct device *);
    void (*get_ownership)(struct device *, kuid_t *, kgid_t *);
    const struct dev_pm_ops *pm;
    struct subsys_private *p;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct hw_perf_event {
    union {
        struct {
            u64 config;
            u64 last_tag;
            unsigned long config_base;
            unsigned long event_base;
            int event_base_rdpmc;
            int idx;
            int last_cpu;
            int flags;
            struct hw_perf_event_extra extra_reg;
            struct hw_perf_event_extra branch_reg;
        };
        struct {
            struct hrtimer hrtimer;
        };
        struct {
            struct list_head tp_list;
        };
        struct {
            u64 pwr_acc;
            u64 ptsc;
        };
        struct {
            struct arch_hw_breakpoint info;
            struct list_head bp_list;
        };
        struct {
            u8 iommu_bank;
            u8 iommu_cntr;
            u16 padding;
            u64 conf;
            u64 conf1;
        };
    };
    struct task_struct *target;
    void *addr_filters;
    unsigned long addr_filters_gen;
    int state;
    local64_t prev_count;
    u64 sample_period;
    u64 last_period;
    local64_t period_left;
    u64 interrupts_seq;
    u64 interrupts;
    u64 freq_time_stamp;
    u64 freq_count_stamp;
};
struct trace_iterator {
    struct trace_array *tr;
    struct tracer *trace;
    struct trace_buffer *trace_buffer;
    void *private;
    int cpu_file;
    struct mutex mutex;
    struct ring_buffer_iter **buffer_iter;
    unsigned long iter_flags;
    struct trace_seq tmp_seq;
    cpumask_var_t started;
    bool snapshot;
    struct trace_seq seq;
    struct trace_entry *ent;
    unsigned long lost_events;
    int leftover;
    int ent_size;
    int cpu;
    u64 ts;
    loff_t pos;
    long idx;
};
struct dquot {
    struct hlist_node dq_hash;
    struct list_head dq_inuse;
    struct list_head dq_free;
    struct list_head dq_dirty;
    struct mutex dq_lock;
    spinlock_t dq_dqb_lock;
    atomic_t dq_count;
    struct super_block *dq_sb;
    struct kqid dq_id;
    loff_t dq_off;
    unsigned long dq_flags;
    struct mem_dqblk dq_dqb;
};
struct dquot_operations {
    int (*write_dquot)(struct dquot *);
    struct dquot *(*alloc_dquot)(struct super_block *, int);
    void (*destroy_dquot)(struct dquot *);
    int (*acquire_dquot)(struct dquot *);
    int (*release_dquot)(struct dquot *);
    int (*mark_dirty)(struct dquot *);
    int (*write_info)(struct super_block *, int);
    qsize_t *(*get_reserved_space)(struct inode *);
    int (*get_projid)(struct inode *, kprojid_t *);
    int (*get_inode_usage)(struct inode *, qsize_t *);
    int (*get_next_id)(struct super_block *, struct kqid *);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
struct quotactl_ops {
    int (*quota_on)(struct super_block *, int, int, const struct path *);
    int (*quota_off)(struct super_block *, int);
    int (*quota_enable)(struct super_block *, unsigned int);
    int (*quota_disable)(struct super_block *, unsigned int);
    int (*quota_sync)(struct super_block *, int);
    int (*set_info)(struct super_block *, int, struct qc_info *);
    int (*get_dqblk)(struct super_block *, struct kqid, struct qc_dqblk *);
    int (*get_nextdqblk)(struct super_block *, struct kqid *, struct qc_dqblk *);
    int (*set_dqblk)(struct super_block *, struct kqid, struct qc_dqblk *);
    int (*get_state)(struct super_block *, struct qc_state *);
    int (*rm_xquota)(struct super_block *, unsigned int);
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
struct block_device {
    dev_t bd_dev;
    int bd_openers;
    struct inode *bd_inode;
    struct super_block *bd_super;
    struct mutex bd_mutex;
    void *bd_claiming;
    void *bd_holder;
    int bd_holders;
    bool bd_write_holder;
    struct list_head bd_holder_disks;
    struct block_device *bd_contains;
    unsigned int bd_block_size;
    u8 bd_partno;
    struct hd_struct;
    struct hd_struct *bd_part;
    unsigned int bd_part_count;
    int bd_invalidated;
    struct gendisk;
    struct gendisk *bd_disk;
    struct request_queue *bd_queue;
    struct backing_dev_info *bd_bdi;
    struct list_head bd_list;
    unsigned long bd_private;
    int bd_fsfreeze_count;
    struct mutex bd_fsfreeze_mutex;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct mm_struct {
    struct {
        struct vm_area_struct *mmap;
        struct rb_root mm_rb;
        u64 vmacache_seqnum;
        unsigned long (*get_unmapped_area)(struct file *, unsigned long, unsigned long, unsigned long, unsigned long);
        unsigned long mmap_base;
        unsigned long mmap_legacy_base;
        unsigned long mmap_compat_base;
        unsigned long mmap_compat_legacy_base;
        unsigned long task_size;
        unsigned long highest_vm_end;
        pgd_t *pgd;
        atomic_t membarrier_state;
        atomic_t mm_users;
        atomic_t mm_count;
        atomic_long_t pgtables_bytes;
        int map_count;
        spinlock_t page_table_lock;
        struct rw_semaphore mmap_sem;
        struct list_head mmlist;
        unsigned long hiwater_rss;
        unsigned long hiwater_vm;
        unsigned long total_vm;
        unsigned long locked_vm;
        atomic64_t pinned_vm;
        unsigned long data_vm;
        unsigned long exec_vm;
        unsigned long stack_vm;
        unsigned long def_flags;
        spinlock_t arg_lock;
        unsigned long start_code;
        unsigned long end_code;
        unsigned long start_data;
        unsigned long end_data;
        unsigned long start_brk;
        unsigned long brk;
        unsigned long start_stack;
        unsigned long arg_start;
        unsigned long arg_end;
        unsigned long env_start;
        unsigned long env_end;
        unsigned long saved_auxv[46];
        struct mm_rss_stat rss_stat;
        struct linux_binfmt;
        struct linux_binfmt *binfmt;
        mm_context_t context;
        unsigned long flags;
        struct core_state *core_state;
        spinlock_t ioctx_lock;
        struct kioctx_table *ioctx_table;
        struct task_struct *owner;
        struct user_namespace *user_ns;
        struct file *exe_file;
        atomic_t tlb_flush_pending;
        bool tlb_flush_batched;
        struct uprobes_state uprobes_state;
        struct work_struct async_put_work;
        u64 android_vendor_data1;
    };
    unsigned long cpu_bitmap[];
};
struct completion {
    unsigned int done;
    wait_queue_head_t wait;
};
struct kernfs_root {
    struct kernfs_node *kn;
    unsigned int flags;
    struct idr ino_idr;
    u32 last_ino;
    u32 next_generation;
    struct kernfs_syscall_ops *syscall_ops;
    struct list_head supers;
    wait_queue_head_t deactivate_waitq;
};
struct ctl_table {
    const char *procname;
    void *data;
    int maxlen;
    umode_t mode;
    struct ctl_table *child;
    proc_handler *proc_handler;
    struct ctl_table_poll *poll;
    void *extra1;
    void *extra2;
};
struct ctl_table_poll {
    atomic_t event;
    wait_queue_head_t wait;
};
struct thread_struct {
    struct desc_struct tls_array[3];
    unsigned long sp;
    unsigned short es;
    unsigned short ds;
    unsigned short fsindex;
    unsigned short gsindex;
    unsigned long fsbase;
    unsigned long gsbase;
    struct perf_event *ptrace_bps[4];
    unsigned long debugreg6;
    unsigned long ptrace_dr7;
    unsigned long cr2;
    unsigned long trap_nr;
    unsigned long error_code;
    unsigned long *io_bitmap_ptr;
    unsigned long iopl;
    unsigned int io_bitmap_max;
    mm_segment_t addr_limit;
    unsigned int sig_on_uaccess_err : 1;
    unsigned int uaccess_err : 1;
    struct fpu fpu;
};
struct inode {
    umode_t i_mode;
    unsigned short i_opflags;
    kuid_t i_uid;
    kgid_t i_gid;
    unsigned int i_flags;
    struct posix_acl *i_acl;
    struct posix_acl *i_default_acl;
    struct inode_operations;
    const struct inode_operations *i_op;
    struct super_block *i_sb;
    struct address_space *i_mapping;
    void *i_security;
    unsigned long i_ino;
    union {
        const unsigned int i_nlink;
        unsigned int __i_nlink;
    };
    dev_t i_rdev;
    loff_t i_size;
    struct timespec64 i_atime;
    struct timespec64 i_mtime;
    struct timespec64 i_ctime;
    spinlock_t i_lock;
    unsigned short i_bytes;
    u8 i_blkbits;
    u8 i_write_hint;
    blkcnt_t i_blocks;
    unsigned long i_state;
    struct rw_semaphore i_rwsem;
    unsigned long dirtied_when;
    unsigned long dirtied_time_when;
    struct hlist_node i_hash;
    struct list_head i_io_list;
    struct list_head i_lru;
    struct list_head i_sb_list;
    struct list_head i_wb_list;
    union {
        struct hlist_head i_dentry;
        struct callback_head i_rcu;
    };
    atomic64_t i_version;
    atomic64_t i_sequence;
    atomic_t i_count;
    atomic_t i_dio_count;
    atomic_t i_writecount;
    atomic_t i_readcount;
    union {
        const struct file_operations *i_fop;
        void (*free_inode)(struct inode *);
    };
    struct file_lock_context;
    struct file_lock_context *i_flctx;
    struct address_space i_data;
    struct list_head i_devices;
    union {
        struct pipe_inode_info *i_pipe;
        struct block_device *i_bdev;
        struct cdev;
        struct cdev *i_cdev;
        char *i_link;
        unsigned int i_dir_seq;
    };
    __u32 i_generation;
    __u32 i_fsnotify_mask;
    struct fsnotify_mark_connector *i_fsnotify_marks;
    struct fscrypt_info *i_crypt_info;
    struct fsverity_info *i_verity_info;
    void *i_private;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
struct __attribute__((aligned((1 << (6))))) hrtimer_cpu_base {
    raw_spinlock_t lock;
    unsigned int cpu;
    unsigned int active_bases;
    unsigned int clock_was_set_seq;
    unsigned int hres_active : 1;
    unsigned int in_hrtirq : 1;
    unsigned int hang_detected : 1;
    unsigned int softirq_activated : 1;
    unsigned int nr_events;
    unsigned short nr_retries;
    unsigned short nr_hangs;
    unsigned int max_hang_time;
    ktime_t expires_next;
    struct hrtimer *next_timer;
    ktime_t softirq_expires_next;
    struct hrtimer *softirq_next_timer;
    struct hrtimer_clock_base clock_base[8];
};
struct pid {
    refcount_t count;
    unsigned int level;
    struct hlist_head tasks[4];
    wait_queue_head_t wait_pidfd;
    struct callback_head rcu;
    struct upid numbers[1];
};
struct pid_namespace {
    struct kref kref;
    struct idr idr;
    struct callback_head rcu;
    unsigned int pid_allocated;
    struct task_struct *child_reaper;
    struct kmem_cache *pid_cachep;
    unsigned int level;
    struct pid_namespace *parent;
    struct vfsmount *proc_mnt;
    struct dentry *proc_self;
    struct dentry *proc_thread_self;
    struct user_namespace *user_ns;
    struct ucounts;
    struct ucounts *ucounts;
    struct work_struct proc_work;
    kgid_t pid_gid;
    int hide_pid;
    int reboot;
    struct ns_common ns;
};
struct cgroup {
    struct cgroup_subsys_state self;
    unsigned long flags;
    int id;
    int level;
    int max_depth;
    int nr_descendants;
    int nr_dying_descendants;
    int max_descendants;
    int nr_populated_csets;
    int nr_populated_domain_children;
    int nr_populated_threaded_children;
    int nr_threaded_children;
    struct kernfs_node *kn;
    struct cgroup_file procs_file;
    struct cgroup_file events_file;
    u16 subtree_control;
    u16 subtree_ss_mask;
    u16 old_subtree_control;
    u16 old_subtree_ss_mask;
    struct cgroup_subsys_state *subsys[5];
    struct cgroup_root *root;
    struct list_head cset_links;
    struct list_head e_csets[5];
    struct cgroup *dom_cgrp;
    struct cgroup *old_dom_cgrp;
    struct cgroup_rstat_cpu *rstat_cpu;
    struct list_head rstat_css_list;
    struct cgroup_base_stat pending_bstat;
    struct cgroup_base_stat bstat;
    struct prev_cputime prev_cputime;
    struct list_head pidlists;
    struct mutex pidlist_mutex;
    wait_queue_head_t offline_waitq;
    struct work_struct release_agent_work;
    struct psi_group psi;
    struct cgroup_bpf bpf;
    atomic_t congestion_count;
    struct cgroup_freezer_state freezer;
    int ancestor_ids[];
};
struct cgroup_subsys {
    struct cgroup_subsys_state *(*css_alloc)(struct cgroup_subsys_state *);
    int (*css_online)(struct cgroup_subsys_state *);
    void (*css_offline)(struct cgroup_subsys_state *);
    void (*css_released)(struct cgroup_subsys_state *);
    void (*css_free)(struct cgroup_subsys_state *);
    void (*css_reset)(struct cgroup_subsys_state *);
    void (*css_rstat_flush)(struct cgroup_subsys_state *, int);
    int (*css_extra_stat_show)(struct seq_file *, struct cgroup_subsys_state *);
    int (*can_attach)(struct cgroup_taskset *);
    void (*cancel_attach)(struct cgroup_taskset *);
    void (*attach)(struct cgroup_taskset *);
    void (*post_attach)(void);
    int (*can_fork)(struct task_struct *);
    void (*cancel_fork)(struct task_struct *);
    void (*fork)(struct task_struct *);
    void (*exit)(struct task_struct *);
    void (*release)(struct task_struct *);
    void (*bind)(struct cgroup_subsys_state *);
    bool early_init : 1;
    bool implicit_on_dfl : 1;
    bool threaded : 1;
    bool broken_hierarchy : 1;
    bool warned_broken_hierarchy : 1;
    int id;
    const char *name;
    const char *legacy_name;
    struct cgroup_root *root;
    struct idr css_idr;
    struct list_head cfts;
    struct cftype *dfl_cftypes;
    struct cftype *legacy_cftypes;
    unsigned int depends_on;
};
struct signal_struct {
    refcount_t sigcnt;
    atomic_t live;
    int nr_threads;
    struct list_head thread_head;
    wait_queue_head_t wait_chldexit;
    struct task_struct *curr_target;
    struct sigpending shared_pending;
    struct hlist_head multiprocess;
    int group_exit_code;
    int notify_count;
    struct task_struct *group_exit_task;
    int group_stop_count;
    unsigned int flags;
    unsigned int is_child_subreaper : 1;
    unsigned int has_child_subreaper : 1;
    int posix_timer_id;
    struct list_head posix_timers;
    struct hrtimer real_timer;
    ktime_t it_real_incr;
    struct cpu_itimer it[2];
    struct thread_group_cputimer cputimer;
    struct posix_cputimers posix_cputimers;
    struct pid *pids[4];
    struct pid *tty_old_pgrp;
    int leader;
    struct tty_struct;
    struct tty_struct *tty;
    seqlock_t stats_lock;
    u64 utime;
    u64 stime;
    u64 cutime;
    u64 cstime;
    u64 gtime;
    u64 cgtime;
    struct prev_cputime prev_cputime;
    unsigned long nvcsw;
    unsigned long nivcsw;
    unsigned long cnvcsw;
    unsigned long cnivcsw;
    unsigned long min_flt;
    unsigned long maj_flt;
    unsigned long cmin_flt;
    unsigned long cmaj_flt;
    unsigned long inblock;
    unsigned long oublock;
    unsigned long cinblock;
    unsigned long coublock;
    unsigned long maxrss;
    unsigned long cmaxrss;
    struct task_io_accounting ioac;
    unsigned long long sum_sched_runtime;
    struct rlimit rlim[16];
    struct taskstats;
    struct taskstats *stats;
    unsigned int audit_tty;
    struct tty_audit_buf;
    struct tty_audit_buf *tty_audit_buf;
    bool oom_flag_origin;
    short oom_score_adj;
    short oom_score_adj_min;
    struct mm_struct *oom_mm;
    struct mutex cred_guard_mutex;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct sighand_struct {
    spinlock_t siglock;
    refcount_t count;
    wait_queue_head_t signalfd_wqh;
    struct k_sigaction action[64];
};
struct dev_pm_qos {
    struct pm_qos_constraints resume_latency;
    struct pm_qos_constraints latency_tolerance;
    struct freq_constraints freq;
    struct pm_qos_flags flags;
    struct dev_pm_qos_request *resume_latency_req;
    struct dev_pm_qos_request *latency_tolerance_req;
    struct dev_pm_qos_request *flags_req;
};
struct perf_cpu_context {
    struct perf_event_context ctx;
    struct perf_event_context *task_ctx;
    int active_oncpu;
    int exclusive;
    raw_spinlock_t hrtimer_lock;
    struct hrtimer hrtimer;
    ktime_t hrtimer_interval;
    unsigned int hrtimer_active;
    struct list_head sched_cb_entry;
    int sched_cb_usage;
    int online;
};
struct perf_event {
    struct list_head event_entry;
    struct list_head sibling_list;
    struct list_head active_list;
    struct rb_node group_node;
    u64 group_index;
    struct list_head migrate_entry;
    struct hlist_node hlist_entry;
    struct list_head active_entry;
    int nr_siblings;
    int event_caps;
    int group_caps;
    struct perf_event *group_leader;
    struct pmu *pmu;
    void *pmu_private;
    enum perf_event_state state;
    unsigned int attach_state;
    local64_t count;
    atomic64_t child_count;
    u64 total_time_enabled;
    u64 total_time_running;
    u64 tstamp;
    u64 shadow_ctx_time;
    struct perf_event_attr attr;
    u16 header_size;
    u16 id_header_size;
    u16 read_size;
    struct hw_perf_event hw;
    struct perf_event_context *ctx;
    atomic_long_t refcount;
    atomic64_t child_total_time_enabled;
    atomic64_t child_total_time_running;
    struct mutex child_mutex;
    struct list_head child_list;
    struct perf_event *parent;
    int oncpu;
    int cpu;
    struct list_head owner_entry;
    struct task_struct *owner;
    struct mutex mmap_mutex;
    atomic_t mmap_count;
    struct ring_buffer *rb;
    struct list_head rb_entry;
    unsigned long rcu_batches;
    int rcu_pending;
    wait_queue_head_t waitq;
    struct fasync_struct *fasync;
    int pending_wakeup;
    int pending_kill;
    int pending_disable;
    struct irq_work pending;
    atomic_t event_limit;
    struct perf_addr_filters_head addr_filters;
    struct perf_addr_filter_range *addr_filter_ranges;
    unsigned long addr_filters_gen;
    struct perf_event *aux_event;
    void (*destroy)(struct perf_event *);
    struct callback_head callback_head;
    struct pid_namespace *ns;
    u64 id;
    u64 (*clock)(void);
    perf_overflow_handler_t overflow_handler;
    void *overflow_handler_context;
    perf_overflow_handler_t orig_overflow_handler;
    struct bpf_prog *prog;
    struct trace_event_call *tp_event;
    struct event_filter;
    struct event_filter *filter;
    void *security;
    struct list_head sb_list;
};
struct file_lock {
    struct file_lock *fl_blocker;
    struct list_head fl_list;
    struct hlist_node fl_link;
    struct list_head fl_blocked_requests;
    struct list_head fl_blocked_member;
    fl_owner_t fl_owner;
    unsigned int fl_flags;
    unsigned char fl_type;
    unsigned int fl_pid;
    int fl_link_cpu;
    wait_queue_head_t fl_wait;
    struct file *fl_file;
    loff_t fl_start;
    loff_t fl_end;
    struct fasync_struct;
    struct fasync_struct *fl_fasync;
    unsigned long fl_break_time;
    unsigned long fl_downgrade_time;
    const struct file_lock_operations *fl_ops;
    const struct lock_manager_operations *fl_lmops;
    union {
        struct nfs_lock_info nfs_fl;
        struct nfs4_lock_info nfs4_fl;
        struct {
            struct list_head link;
            int state;
            unsigned int debug_id;
        } afs;
    } fl_u;
    struct list_head android_reserved1;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
struct rcu_sync {
    int gp_state;
    int gp_count;
    wait_queue_head_t gp_wait;
    struct callback_head cb_head;
};
struct core_state {
    atomic_t nr_threads;
    struct core_thread dumper;
    struct completion startup;
};
struct srcu_struct {
    struct srcu_node node[3];
    struct srcu_node *level[3];
    struct mutex srcu_cb_mutex;
    spinlock_t lock;
    struct mutex srcu_gp_mutex;
    unsigned int srcu_idx;
    unsigned long srcu_gp_seq;
    unsigned long srcu_gp_seq_needed;
    unsigned long srcu_gp_seq_needed_exp;
    unsigned long srcu_last_gp_end;
    struct srcu_data *sda;
    unsigned long srcu_barrier_seq;
    struct mutex srcu_barrier_mutex;
    struct completion srcu_barrier_completion;
    atomic_t srcu_barrier_cpu_cnt;
    struct delayed_work work;
};
struct dentry {
    unsigned int d_flags;
    seqcount_t d_seq;
    struct hlist_bl_node d_hash;
    struct dentry *d_parent;
    struct qstr d_name;
    struct inode *d_inode;
    unsigned char d_iname[32];
    struct lockref d_lockref;
    struct dentry_operations;
    const struct dentry_operations *d_op;
    struct super_block *d_sb;
    unsigned long d_time;
    void *d_fsdata;
    union {
        struct list_head d_lru;
        wait_queue_head_t *d_wait;
    };
    struct list_head d_child;
    struct list_head d_subdirs;
    union {
        struct hlist_node d_alias;
        struct hlist_bl_node d_in_lookup_hash;
        struct callback_head d_rcu;
    } d_u;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
};
struct task_struct {
    struct thread_info thread_info;
    volatile long state;
    void *stack;
    refcount_t usage;
    unsigned int flags;
    unsigned int ptrace;
    struct llist_node wake_entry;
    int on_cpu;
    unsigned int cpu;
    unsigned int wakee_flips;
    unsigned long wakee_flip_decay_ts;
    struct task_struct *last_wakee;
    int recent_used_cpu;
    int wake_cpu;
    int on_rq;
    int prio;
    int static_prio;
    int normal_prio;
    unsigned int rt_priority;
    struct sched_class;
    const struct sched_class *sched_class;
    struct sched_entity se;
    struct sched_rt_entity rt;
    struct task_group *sched_task_group;
    struct sched_dl_entity dl;
    struct uclamp_se uclamp_req[2];
    struct uclamp_se uclamp[2];
    unsigned int policy;
    int nr_cpus_allowed;
    const cpumask_t *cpus_ptr;
    cpumask_t cpus_mask;
    int rcu_read_lock_nesting;
    union rcu_special rcu_read_unlock_special;
    struct list_head rcu_node_entry;
    struct rcu_node *rcu_blocked_node;
    unsigned long rcu_tasks_nvcsw;
    u8 rcu_tasks_holdout;
    u8 rcu_tasks_idx;
    int rcu_tasks_idle_cpu;
    struct list_head rcu_tasks_holdout_list;
    struct sched_info sched_info;
    struct list_head tasks;
    struct plist_node pushable_tasks;
    struct rb_node pushable_dl_tasks;
    struct mm_struct *mm;
    struct mm_struct *active_mm;
    struct vmacache vmacache;
    struct task_rss_stat rss_stat;
    int exit_state;
    int exit_code;
    int exit_signal;
    int pdeath_signal;
    unsigned long jobctl;
    unsigned int personality;
    unsigned int sched_reset_on_fork : 1;
    unsigned int sched_contributes_to_load : 1;
    unsigned int sched_migrated : 1;
    unsigned int sched_remote_wakeup : 1;
    unsigned int sched_psi_wake_requeue : 1;
    unsigned int : 0;
    unsigned int in_execve : 1;
    unsigned int in_iowait : 1;
    unsigned int restore_sigmask : 1;
    unsigned int in_user_fault : 1;
    unsigned int no_cgroup_migration : 1;
    unsigned int frozen : 1;
    unsigned long atomic_flags;
    struct restart_block restart_block;
    pid_t pid;
    pid_t tgid;
    unsigned long stack_canary;
    struct task_struct *real_parent;
    struct task_struct *parent;
    struct list_head children;
    struct list_head sibling;
    struct task_struct *group_leader;
    struct list_head ptraced;
    struct list_head ptrace_entry;
    struct pid *thread_pid;
    struct hlist_node pid_links[4];
    struct list_head thread_group;
    struct list_head thread_node;
    struct completion *vfork_done;
    int *set_child_tid;
    int *clear_child_tid;
    u64 utime;
    u64 stime;
    u64 gtime;
    u64 *time_in_state;
    unsigned int max_state;
    struct prev_cputime prev_cputime;
    unsigned long nvcsw;
    unsigned long nivcsw;
    u64 start_time;
    u64 real_start_time;
    unsigned long min_flt;
    unsigned long maj_flt;
    struct posix_cputimers posix_cputimers;
    struct cred;
    const struct cred *ptracer_cred;
    const struct cred *real_cred;
    const struct cred *cred;
    struct key;
    struct key *cached_requested_key;
    char comm[16];
    struct nameidata *nameidata;
    struct fs_struct *fs;
    struct files_struct;
    struct files_struct *files;
    struct nsproxy *nsproxy;
    struct signal_struct *signal;
    struct sighand_struct *sighand;
    sigset_t blocked;
    sigset_t real_blocked;
    sigset_t saved_sigmask;
    struct sigpending pending;
    unsigned long sas_ss_sp;
    size_t sas_ss_size;
    unsigned int sas_ss_flags;
    struct callback_head *task_works;
    struct audit_context *audit_context;
    kuid_t loginuid;
    unsigned int sessionid;
    struct seccomp seccomp;
    u64 parent_exec_id;
    u64 self_exec_id;
    spinlock_t alloc_lock;
    raw_spinlock_t pi_lock;
    struct wake_q_node wake_q;
    struct rb_root_cached pi_waiters;
    struct task_struct *pi_top_task;
    struct rt_mutex_waiter;
    struct rt_mutex_waiter *pi_blocked_on;
    void *journal_info;
    struct bio_list *bio_list;
    struct blk_plug *plug;
    struct reclaim_state *reclaim_state;
    struct backing_dev_info *backing_dev_info;
    struct io_context *io_context;
    struct capture_control *capture_control;
    unsigned long ptrace_message;
    kernel_siginfo_t *last_siginfo;
    struct task_io_accounting ioac;
    unsigned int psi_flags;
    u64 acct_rss_mem1;
    u64 acct_vm_mem1;
    u64 acct_timexpd;
    nodemask_t mems_allowed;
    seqcount_t mems_allowed_seq;
    int cpuset_mem_spread_rotor;
    int cpuset_slab_spread_rotor;
    struct css_set;
    struct css_set *cgroups;
    struct list_head cg_list;
    struct robust_list_head *robust_list;
    struct compat_robust_list_head;
    struct compat_robust_list_head *compat_robust_list;
    struct list_head pi_state_list;
    struct futex_pi_state *pi_state_cache;
    struct mutex futex_exit_mutex;
    unsigned int futex_state;
    struct perf_event_context *perf_event_ctxp[2];
    struct mutex perf_event_mutex;
    struct list_head perf_event_list;
    unsigned long preempt_disable_ip;
    struct tlbflush_unmap_batch tlb_ubc;
    union {
        refcount_t rcu_users;
        struct callback_head rcu;
    };
    struct pipe_inode_info *splice_pipe;
    struct page_frag task_frag;
    int nr_dirtied;
    int nr_dirtied_pause;
    unsigned long dirty_paused_when;
    u64 timer_slack_ns;
    u64 default_timer_slack_ns;
    unsigned long trace;
    unsigned long trace_recursion;
    unsigned int kcov_mode;
    unsigned int kcov_size;
    void *kcov_area;
    struct kcov;
    struct kcov *kcov;
    u64 kcov_handle;
    int kcov_sequence;
    enum kflat_mode kflat_mode;
    unsigned int kflat_size;
    void *kflat_area;
    struct kflat;
    struct kflat *kflat;
    struct mem_cgroup *memcg_in_oom;
    gfp_t memcg_oom_gfp_mask;
    int memcg_oom_order;
    unsigned int memcg_nr_pages_over_high;
    struct mem_cgroup *active_memcg;
    struct uprobe_task *utask;
    int pagefault_disabled;
    struct task_struct *oom_reaper_list;
    struct vm_struct *stack_vm_area;
    refcount_t stack_refcount;
    void *security;
    u64 android_vendor_data1[3];
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
    u64 android_kabi_reserved5;
    u64 android_kabi_reserved6;
    u64 android_kabi_reserved7;
    u64 android_kabi_reserved8;
    struct thread_struct thread;
};
struct cgroup_root {
    struct kernfs_root *kf_root;
    unsigned int subsys_mask;
    int hierarchy_id;
    struct cgroup cgrp;
    int cgrp_ancestor_id_storage;
    atomic_t nr_cgrps;
    struct list_head root_list;
    unsigned int flags;
    struct idr cgroup_idr;
    char release_agent_path[4096];
    char name[64];
};
struct dev_pm_info {
    pm_message_t power_state;
    unsigned int can_wakeup : 1;
    unsigned int async_suspend : 1;
    bool in_dpm_list : 1;
    bool is_prepared : 1;
    bool is_suspended : 1;
    bool is_noirq_suspended : 1;
    bool is_late_suspended : 1;
    bool no_pm : 1;
    bool early_init : 1;
    bool direct_complete : 1;
    u32 driver_flags;
    spinlock_t lock;
    struct list_head entry;
    struct completion completion;
    struct wakeup_source *wakeup;
    bool wakeup_path : 1;
    bool syscore : 1;
    bool no_pm_callbacks : 1;
    unsigned int must_resume : 1;
    unsigned int may_skip_resume : 1;
    struct hrtimer suspend_timer;
    u64 timer_expires;
    struct work_struct work;
    wait_queue_head_t wait_queue;
    struct wake_irq *wakeirq;
    atomic_t usage_count;
    atomic_t child_count;
    unsigned int disable_depth : 3;
    unsigned int idle_notification : 1;
    unsigned int request_pending : 1;
    unsigned int deferred_resume : 1;
    unsigned int runtime_auto : 1;
    bool ignore_children : 1;
    unsigned int no_callbacks : 1;
    unsigned int irq_safe : 1;
    unsigned int use_autosuspend : 1;
    unsigned int timer_autosuspends : 1;
    unsigned int memalloc_noio : 1;
    unsigned int links_count;
    enum rpm_request request;
    enum rpm_status runtime_status;
    int runtime_error;
    int autosuspend_delay;
    u64 last_busy;
    u64 active_time;
    u64 suspended_time;
    u64 accounting_timestamp;
    struct pm_subsys_data *subsys_data;
    void (*set_latency_tolerance)(struct device *, s32);
    struct dev_pm_qos;
    struct dev_pm_qos *qos;
};
struct percpu_rw_semaphore {
    struct rcu_sync rss;
    unsigned int *read_count;
    struct rw_semaphore rw_sem;
    struct rcuwait writer;
    int readers_block;
};
struct device {
    struct kobject kobj;
    struct device *parent;
    struct device_private *p;
    const char *init_name;
    const struct device_type *type;
    struct bus_type *bus;
    struct device_driver *driver;
    void *platform_data;
    void *driver_data;
    struct mutex mutex;
    struct dev_links_info links;
    struct dev_pm_info power;
    struct dev_pm_domain *pm_domain;
    struct irq_domain;
    struct irq_domain *msi_domain;
    struct list_head msi_list;
    struct dma_map_ops;
    const struct dma_map_ops *dma_ops;
    u64 *dma_mask;
    u64 coherent_dma_mask;
    u64 bus_dma_mask;
    unsigned long dma_pfn_offset;
    struct device_dma_parameters *dma_parms;
    struct list_head dma_pools;
    struct cma;
    struct cma *cma_area;
    struct dev_archdata archdata;
    struct device_node *of_node;
    struct fwnode_handle *fwnode;
    dev_t devt;
    u32 id;
    spinlock_t devres_lock;
    struct list_head devres_head;
    struct class *class;
    const struct attribute_group **groups;
    void (*release)(struct device *);
    struct iommu_group *iommu_group;
    struct iommu_fwspec *iommu_fwspec;
    struct iommu_param *iommu_param;
    bool offline_disabled : 1;
    bool offline : 1;
    bool of_node_reused : 1;
    bool state_synced : 1;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
    u64 android_kabi_reserved5;
    u64 android_kabi_reserved6;
    u64 android_kabi_reserved7;
    u64 android_kabi_reserved8;
};
typedef void (*poll_queue_proc)(struct file *, wait_queue_head_t *, struct poll_table_struct *);
struct sb_writers {
    int frozen;
    wait_queue_head_t wait_unfrozen;
    struct percpu_rw_semaphore rw_sem[3];
};
struct super_block {
    struct list_head s_list;
    dev_t s_dev;
    unsigned char s_blocksize_bits;
    unsigned long s_blocksize;
    loff_t s_maxbytes;
    struct file_system_type *s_type;
    struct super_operations;
    const struct super_operations *s_op;
    const struct dquot_operations *dq_op;
    const struct quotactl_ops *s_qcop;
    const struct export_operations *s_export_op;
    unsigned long s_flags;
    unsigned long s_iflags;
    unsigned long s_magic;
    struct dentry *s_root;
    struct rw_semaphore s_umount;
    int s_count;
    atomic_t s_active;
    void *s_security;
    struct xattr_handler;
    const struct xattr_handler **s_xattr;
    const struct fscrypt_operations *s_cop;
    struct key *s_master_keys;
    const struct fsverity_operations *s_vop;
    struct unicode_map;
    struct unicode_map *s_encoding;
    __u16 s_encoding_flags;
    struct hlist_bl_head s_roots;
    struct list_head s_mounts;
    struct block_device *s_bdev;
    struct backing_dev_info *s_bdi;
    struct mtd_info;
    struct mtd_info *s_mtd;
    struct hlist_node s_instances;
    unsigned int s_quota_types;
    struct quota_info s_dquot;
    struct sb_writers s_writers;
    void *s_fs_info;
    u32 s_time_gran;
    time64_t s_time_min;
    time64_t s_time_max;
    __u32 s_fsnotify_mask;
    struct fsnotify_mark_connector *s_fsnotify_marks;
    char s_id[32];
    uuid_t s_uuid;
    unsigned int s_max_links;
    fmode_t s_mode;
    struct mutex s_vfs_rename_mutex;
    const char *s_subtype;
    const struct dentry_operations *s_d_op;
    int cleancache_poolid;
    struct shrinker s_shrink;
    atomic_long_t s_remove_count;
    atomic_long_t s_fsnotify_inode_refs;
    int s_readonly_remount;
    struct workqueue_struct *s_dio_done_wq;
    struct hlist_head s_pins;
    struct user_namespace *s_user_ns;
    struct list_lru s_dentry_lru;
    struct list_lru s_inode_lru;
    struct callback_head rcu;
    struct work_struct destroy_work;
    struct mutex s_sync_lock;
    int s_stack_depth;
    spinlock_t s_inode_list_lock __attribute__((aligned((1 << (6)))));
    struct list_head s_inodes;
    spinlock_t s_inode_wblist_lock;
    struct list_head s_inodes_wb;
    u64 android_kabi_reserved1;
    u64 android_kabi_reserved2;
    u64 android_kabi_reserved3;
    u64 android_kabi_reserved4;
};
struct poll_table_struct {
    poll_queue_proc _qproc;
    __poll_t _key;
};

/* Forward decls of global vars */


/* ----------------------------- */
/* Function declarations section */
/* ----------------------------- */


/*Functions defined in this file*/




static inline bool is_power_of_2(unsigned long n) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((const));


static inline int __order_base_2(unsigned long n) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((const));



static inline int fls(unsigned int x) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((always_inline));


static inline int fls64(__u64 x) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((always_inline));


void dummy_function_that_takes_task_struct_parameter(struct task_struct *t);

// Func decls

/* Additional function decls */

// Func decls

// Func decls

/*Static inline headers*/
static inline int __ilog2_u32(u32 n) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((const)) {
    return fls(n) - 1;
}


static inline int __ilog2_u64(u64 n) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((const)) {
    return fls64(n) - 1;
}


static inline bool is_power_of_2(unsigned long n) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((const)) {
    return (n != 0 && ((n & (n - 1)) == 0));
}


static inline int __order_base_2(unsigned long n) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((const)) {
    return n > 1 ? (__builtin_constant_p(n - 1) ? (__builtin_constant_p(n - 1) ? ((n - 1) < 2 ? 0 : (n - 1) & (1ULL << 63) ? 63 : (n - 1) & (1ULL << 62) ? 62 : (n - 1) & (1ULL << 61) ? 61 : (n - 1) & (1ULL << 60) ? 60 : (n - 1) & (1ULL << 59) ? 59 : (n - 1) & (1ULL << 58) ? 58 : (n - 1) & (1ULL << 57) ? 57 : (n - 1) & (1ULL << 56) ? 56 : (n - 1) & (1ULL << 55) ? 55 : (n - 1) & (1ULL << 54) ? 54 : (n - 1) & (1ULL << 53) ? 53 : (n - 1) & (1ULL << 52) ? 52 : (n - 1) & (1ULL << 51) ? 51 : (n - 1) & (1ULL << 50) ? 50 : (n - 1) & (1ULL << 49) ? 49 : (n - 1) & (1ULL << 48) ? 48 : (n - 1) & (1ULL << 47) ? 47 : (n - 1) & (1ULL << 46) ? 46 : (n - 1) & (1ULL << 45) ? 45 : (n - 1) & (1ULL << 44) ? 44 : (n - 1) & (1ULL << 43) ? 43 : (n - 1) & (1ULL << 42) ? 42 : (n - 1) & (1ULL << 41) ? 41 : (n - 1) & (1ULL << 40) ? 40 : (n - 1) & (1ULL << 39) ? 39 : (n - 1) & (1ULL << 38) ? 38 : (n - 1) & (1ULL << 37) ? 37 : (n - 1) & (1ULL << 36) ? 36 : (n - 1) & (1ULL << 35) ? 35 : (n - 1) & (1ULL << 34) ? 34 : (n - 1) & (1ULL << 33) ? 33 : (n - 1) & (1ULL << 32) ? 32 : (n - 1) & (1ULL << 31) ? 31 : (n - 1) & (1ULL << 30) ? 30 : (n - 1) & (1ULL << 29) ? 29 : (n - 1) & (1ULL << 28) ? 28 : (n - 1) & (1ULL << 27) ? 27 : (n - 1) & (1ULL << 26) ? 26 : (n - 1) & (1ULL << 25) ? 25 : (n - 1) & (1ULL << 24) ? 24 : (n - 1) & (1ULL << 23) ? 23 : (n - 1) & (1ULL << 22) ? 22 : (n - 1) & (1ULL << 21) ? 21 : (n - 1) & (1ULL << 20) ? 20 : (n - 1) & (1ULL << 19) ? 19 : (n - 1) & (1ULL << 18) ? 18 : (n - 1) & (1ULL << 17) ? 17 : (n - 1) & (1ULL << 16) ? 16 : (n - 1) & (1ULL << 15) ? 15 : (n - 1) & (1ULL << 14) ? 14 : (n - 1) & (1ULL << 13) ? 13 : (n - 1) & (1ULL << 12) ? 12 : (n - 1) & (1ULL << 11) ? 11 : (n - 1) & (1ULL << 10) ? 10 : (n - 1) & (1ULL << 9) ? 9 : (n - 1) & (1ULL << 8) ? 8 : (n - 1) & (1ULL << 7) ? 7 : (n - 1) & (1ULL << 6) ? 6 : (n - 1) & (1ULL << 5) ? 5 : (n - 1) & (1ULL << 4) ? 4 : (n - 1) & (1ULL << 3) ? 3 : (n - 1) & (1ULL << 2) ? 2 : 1) : -1) : (sizeof (n - 1) <= 4) ? __ilog2_u32(n - 1) : __ilog2_u64(n - 1)) + 1 : 0;
}


static inline int __bits_per(unsigned long n) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((const)) {
    if (n < 2)
        return 1;
    if (is_power_of_2(n))
        return (__builtin_constant_p(n) ? (((n) == 0 || (n) == 1) ? 0 : (__builtin_constant_p((n) - 1) ? (__builtin_constant_p((n) - 1) ? (((n) - 1) < 2 ? 0 : ((n) - 1) & (1ULL << 63) ? 63 : ((n) - 1) & (1ULL << 62) ? 62 : ((n) - 1) & (1ULL << 61) ? 61 : ((n) - 1) & (1ULL << 60) ? 60 : ((n) - 1) & (1ULL << 59) ? 59 : ((n) - 1) & (1ULL << 58) ? 58 : ((n) - 1) & (1ULL << 57) ? 57 : ((n) - 1) & (1ULL << 56) ? 56 : ((n) - 1) & (1ULL << 55) ? 55 : ((n) - 1) & (1ULL << 54) ? 54 : ((n) - 1) & (1ULL << 53) ? 53 : ((n) - 1) & (1ULL << 52) ? 52 : ((n) - 1) & (1ULL << 51) ? 51 : ((n) - 1) & (1ULL << 50) ? 50 : ((n) - 1) & (1ULL << 49) ? 49 : ((n) - 1) & (1ULL << 48) ? 48 : ((n) - 1) & (1ULL << 47) ? 47 : ((n) - 1) & (1ULL << 46) ? 46 : ((n) - 1) & (1ULL << 45) ? 45 : ((n) - 1) & (1ULL << 44) ? 44 : ((n) - 1) & (1ULL << 43) ? 43 : ((n) - 1) & (1ULL << 42) ? 42 : ((n) - 1) & (1ULL << 41) ? 41 : ((n) - 1) & (1ULL << 40) ? 40 : ((n) - 1) & (1ULL << 39) ? 39 : ((n) - 1) & (1ULL << 38) ? 38 : ((n) - 1) & (1ULL << 37) ? 37 : ((n) - 1) & (1ULL << 36) ? 36 : ((n) - 1) & (1ULL << 35) ? 35 : ((n) - 1) & (1ULL << 34) ? 34 : ((n) - 1) & (1ULL << 33) ? 33 : ((n) - 1) & (1ULL << 32) ? 32 : ((n) - 1) & (1ULL << 31) ? 31 : ((n) - 1) & (1ULL << 30) ? 30 : ((n) - 1) & (1ULL << 29) ? 29 : ((n) - 1) & (1ULL << 28) ? 28 : ((n) - 1) & (1ULL << 27) ? 27 : ((n) - 1) & (1ULL << 26) ? 26 : ((n) - 1) & (1ULL << 25) ? 25 : ((n) - 1) & (1ULL << 24) ? 24 : ((n) - 1) & (1ULL << 23) ? 23 : ((n) - 1) & (1ULL << 22) ? 22 : ((n) - 1) & (1ULL << 21) ? 21 : ((n) - 1) & (1ULL << 20) ? 20 : ((n) - 1) & (1ULL << 19) ? 19 : ((n) - 1) & (1ULL << 18) ? 18 : ((n) - 1) & (1ULL << 17) ? 17 : ((n) - 1) & (1ULL << 16) ? 16 : ((n) - 1) & (1ULL << 15) ? 15 : ((n) - 1) & (1ULL << 14) ? 14 : ((n) - 1) & (1ULL << 13) ? 13 : ((n) - 1) & (1ULL << 12) ? 12 : ((n) - 1) & (1ULL << 11) ? 11 : ((n) - 1) & (1ULL << 10) ? 10 : ((n) - 1) & (1ULL << 9) ? 9 : ((n) - 1) & (1ULL << 8) ? 8 : ((n) - 1) & (1ULL << 7) ? 7 : ((n) - 1) & (1ULL << 6) ? 6 : ((n) - 1) & (1ULL << 5) ? 5 : ((n) - 1) & (1ULL << 4) ? 4 : ((n) - 1) & (1ULL << 3) ? 3 : ((n) - 1) & (1ULL << 2) ? 2 : 1) : -1) : (sizeof ((n) - 1) <= 4) ? __ilog2_u32((n) - 1) : __ilog2_u64((n) - 1)) + 1) : __order_base_2(n)) + 1;
    return (__builtin_constant_p(n) ? (((n) == 0 || (n) == 1) ? 0 : (__builtin_constant_p((n) - 1) ? (__builtin_constant_p((n) - 1) ? (((n) - 1) < 2 ? 0 : ((n) - 1) & (1ULL << 63) ? 63 : ((n) - 1) & (1ULL << 62) ? 62 : ((n) - 1) & (1ULL << 61) ? 61 : ((n) - 1) & (1ULL << 60) ? 60 : ((n) - 1) & (1ULL << 59) ? 59 : ((n) - 1) & (1ULL << 58) ? 58 : ((n) - 1) & (1ULL << 57) ? 57 : ((n) - 1) & (1ULL << 56) ? 56 : ((n) - 1) & (1ULL << 55) ? 55 : ((n) - 1) & (1ULL << 54) ? 54 : ((n) - 1) & (1ULL << 53) ? 53 : ((n) - 1) & (1ULL << 52) ? 52 : ((n) - 1) & (1ULL << 51) ? 51 : ((n) - 1) & (1ULL << 50) ? 50 : ((n) - 1) & (1ULL << 49) ? 49 : ((n) - 1) & (1ULL << 48) ? 48 : ((n) - 1) & (1ULL << 47) ? 47 : ((n) - 1) & (1ULL << 46) ? 46 : ((n) - 1) & (1ULL << 45) ? 45 : ((n) - 1) & (1ULL << 44) ? 44 : ((n) - 1) & (1ULL << 43) ? 43 : ((n) - 1) & (1ULL << 42) ? 42 : ((n) - 1) & (1ULL << 41) ? 41 : ((n) - 1) & (1ULL << 40) ? 40 : ((n) - 1) & (1ULL << 39) ? 39 : ((n) - 1) & (1ULL << 38) ? 38 : ((n) - 1) & (1ULL << 37) ? 37 : ((n) - 1) & (1ULL << 36) ? 36 : ((n) - 1) & (1ULL << 35) ? 35 : ((n) - 1) & (1ULL << 34) ? 34 : ((n) - 1) & (1ULL << 33) ? 33 : ((n) - 1) & (1ULL << 32) ? 32 : ((n) - 1) & (1ULL << 31) ? 31 : ((n) - 1) & (1ULL << 30) ? 30 : ((n) - 1) & (1ULL << 29) ? 29 : ((n) - 1) & (1ULL << 28) ? 28 : ((n) - 1) & (1ULL << 27) ? 27 : ((n) - 1) & (1ULL << 26) ? 26 : ((n) - 1) & (1ULL << 25) ? 25 : ((n) - 1) & (1ULL << 24) ? 24 : ((n) - 1) & (1ULL << 23) ? 23 : ((n) - 1) & (1ULL << 22) ? 22 : ((n) - 1) & (1ULL << 21) ? 21 : ((n) - 1) & (1ULL << 20) ? 20 : ((n) - 1) & (1ULL << 19) ? 19 : ((n) - 1) & (1ULL << 18) ? 18 : ((n) - 1) & (1ULL << 17) ? 17 : ((n) - 1) & (1ULL << 16) ? 16 : ((n) - 1) & (1ULL << 15) ? 15 : ((n) - 1) & (1ULL << 14) ? 14 : ((n) - 1) & (1ULL << 13) ? 13 : ((n) - 1) & (1ULL << 12) ? 12 : ((n) - 1) & (1ULL << 11) ? 11 : ((n) - 1) & (1ULL << 10) ? 10 : ((n) - 1) & (1ULL << 9) ? 9 : ((n) - 1) & (1ULL << 8) ? 8 : ((n) - 1) & (1ULL << 7) ? 7 : ((n) - 1) & (1ULL << 6) ? 6 : ((n) - 1) & (1ULL << 5) ? 5 : ((n) - 1) & (1ULL << 4) ? 4 : ((n) - 1) & (1ULL << 3) ? 3 : ((n) - 1) & (1ULL << 2) ? 2 : 1) : -1) : (sizeof ((n) - 1) <= 4) ? __ilog2_u32((n) - 1) : __ilog2_u64((n) - 1)) + 1) : __order_base_2(n));
}


static inline int fls(unsigned int x) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((always_inline)) {
    int r;
    //asm ("bsrl %1,%0" : "=r" (r) : "rm" (x), "0" (-1));
    return r + 1;
}


static inline int fls64(__u64 x) __attribute__((gnu_inline)) __attribute__((unused)) __attribute__((no_instrument_function)) __attribute__((always_inline)) {
    int bitpos = -1;
    //asm ("bsrq %1,%q0" : "+r" (bitpos) : "rm" (x));
    return bitpos + 1;
}



#endif

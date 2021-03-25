/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_KFLAT_H
#define _LINUX_KFLAT_H

#include <linux/kflat_core.h>
#include <linux/mm.h>

#define kflat_fmt(fmt) "kflat: " fmt
#define flat_err(fmt) printk(KERN_ERR kflat_fmt(fmt));
#define flat_errs(fmt,...) printk(KERN_ERR kflat_fmt(fmt),__VA_ARGS__);
#define flat_info(fmt) printk(KERN_INFO kflat_fmt(fmt));
#define flat_infos(fmt,...) printk(KERN_INFO kflat_fmt(fmt),__VA_ARGS__);

#define DEFAULT_ITER_QUEUE_SIZE (1024*1024*8)

static inline void *libflat_zalloc(size_t size, size_t n) {
	return kvzalloc(size*n,GFP_KERNEL);
}

static inline void libflat_free(const void* p) {
	kvfree(p);
}

struct flat_node {
	struct rb_node rb;
	uintptr_t start;	/* Start of interval */
	uintptr_t last;	/* Last location _in_ interval */
	uintptr_t __subtree_last;
	struct blstream* storage;
};

struct flatten_pointer {
	struct flat_node* node;
	size_t offset;
};

struct flatten_header {
	size_t memory_size;
	size_t ptr_count;
	size_t root_addr_count;
	uint64_t magic;
};

struct FLCONTROL {
	struct blstream* bhead;
	struct blstream* btail;
	struct rb_root_cached fixup_set_root;
	struct rb_root_cached imap_root;
	struct flatten_header	HDR;
	struct root_addrnode* rhead;
	struct root_addrnode* rtail;
	struct root_addrnode* last_accessed_root;
	int debug_flag;
	unsigned long option;
	void* mem;
};

struct blstream {
	struct blstream* next;
	struct blstream* prev;
	void* data;
	size_t size;
	size_t index;
	size_t alignment;
	size_t align_offset;
};

struct fixup_set_node {
	struct rb_node node;
  	/* Storage area and offset where the original address to be fixed is stored */
	struct flat_node* inode;
	size_t offset;
	/* Storage area and offset where the original address points to */
	struct flatten_pointer* ptr;
};

/* Root address list */
struct root_addrnode {
	struct root_addrnode* next;
	uintptr_t root_addr;
};

struct interval_nodelist {
	struct interval_nodelist* next;
	struct flat_node* node;
};

struct queue_block {
    struct queue_block* next;
    unsigned char data[];
};

struct bqueue {
    size_t block_size;
    size_t size;
    struct queue_block* front_block;
    size_t front_index;
    struct queue_block* back_block;
    size_t back_index;
};

struct kflat {
	/*
	 * Reference counter. We keep one for:
	 *  - opened file descriptor
	 *  - task with enabled coverage (we can't unwire it from another task)
	 */
	atomic_t			refcount;
	/* The lock protects mode, size, area and t. */
	spinlock_t			lock;
	enum kflat_mode		mode;
	/* Size of arena (in bytes for KFLAT_MODE_ENABLED). */
	unsigned long		size;
	/* Coverage buffer shared with user space. */
	void				*area;
	/* Task for which we collect coverage, or NULL. */
	struct task_struct	*t;
	struct FLCONTROL 	FLCTRL;
	int 				errno;
};

struct flatten_base {};

typedef struct flatten_pointer* (*flatten_struct_t)(struct kflat* kflat, const struct flatten_base*, size_t n, struct bqueue*);
typedef struct flatten_pointer* (*flatten_struct_mixed_convert_t)(struct flatten_pointer*, const struct flatten_base*);

struct flatten_job {
    struct flat_node* node;
    size_t offset;
    size_t size;
    struct flatten_base* ptr;
    flatten_struct_t fun;
    /* Mixed pointer support */
    const struct flatten_base* fp;
    flatten_struct_mixed_convert_t convert;
};

/* Main interface functions */

void flatten_init(struct kflat* kflat);
int flatten_write(struct kflat* kflat);
int flatten_fini(struct kflat* kflat);
void unflatten_init(void);
int unflatten_read(void* f);
void unflatten_fini(void);

int flatten_write_internal(struct kflat* kflat, size_t* wcounter_p);
struct flatten_pointer* flatten_plain_type(struct kflat* kflat, const void* _ptr, size_t _sz);
int fixup_set_insert(struct kflat* kflat, struct flat_node* node, size_t offset, struct flatten_pointer* ptr);
int fixup_set_reserve_address(struct kflat* kflat, uintptr_t addr);
int fixup_set_reserve(struct kflat* kflat, struct flat_node* node, size_t offset);
int fixup_set_update(struct kflat* kflat, struct flat_node* node, size_t offset, struct flatten_pointer* ptr);
struct flatten_pointer* get_pointer_node(struct kflat* kflat, const void* _ptr);
int root_addr_append(struct kflat* kflat, size_t root_addr);
void* root_pointer_next(void);
void* root_pointer_seq(size_t index);
struct blstream* binary_stream_insert_back(struct kflat* kflat, const void* data, size_t size, struct blstream* where);
struct blstream* binary_stream_insert_front(struct kflat* kflat, const void* data, size_t size, struct blstream* where);
struct blstream* binary_stream_append(struct kflat* kflat, const void* data, size_t size);
struct rb_node *rb_next(const struct rb_node *node);
struct rb_node *rb_prev(const struct rb_node *node);
struct fixup_set_node* fixup_set_search(struct kflat* kflat, uintptr_t v);
void fixup_set_print(struct kflat* kflat);
size_t fixup_set_count(struct kflat* kflat);
void fixup_set_destroy(struct kflat* kflat);
int fixup_set_write(struct kflat* kflat, size_t* wcounter_p);
size_t root_addr_count(struct kflat* kflat);

int bqueue_init(struct bqueue* q, size_t block_size);
void bqueue_destroy(struct bqueue* q);
int bqueue_empty(struct bqueue* q);
size_t bqueue_size(struct bqueue* q);
int bqueue_push_back(struct bqueue* q, const void* m, size_t s);
int bqueue_pop_front(struct bqueue* q, void* m, size_t s);

static struct flat_node * interval_tree_iter_first(struct rb_root_cached *root, uintptr_t start, uintptr_t last) __attribute__ ((unused));
static  struct flat_node * interval_tree_iter_next(struct flat_node *node, uintptr_t start, uintptr_t last) __attribute__ ((unused));
static void interval_tree_insert(struct flat_node *node, struct rb_root_cached *root) __attribute__ ((unused));
static void interval_tree_remove(struct flat_node *node, struct rb_root_cached *root) __attribute__ ((unused));

#define DBGC(b,...)		do { if (b!=0)	__VA_ARGS__; } while(0)

enum flatten_option {
	option_silent = 0x01,
};

void flatten_set_option(struct kflat* kflat, int option);
void flatten_clear_option(struct kflat* kflat, int option);

static inline struct flatten_pointer* make_flatten_pointer(struct flat_node* node, size_t offset) {
	struct flatten_pointer* v = libflat_zalloc(sizeof(struct flatten_pointer),1);
	if (v==0) return 0;
	v->node = node;
	v->offset = offset;
	return v;
}

static inline void destroy_flatten_pointer(struct flatten_pointer* fp) {
	libflat_free(fp->node->storage);
	libflat_free(fp->node);
	libflat_free(fp);
}

static inline size_t strmemlen(const char* s) {
	return strlen(s)+1;
}

static inline size_t ptrarrmemlen(const void* const* m) {
	size_t count=1;
	while(*m) {
		count++;
		m++;
	}
	return count;
}

#define FLATTEN_MAGIC 0x464c415454454e00ULL

#define FLATTEN_WRITE_ONCE(addr,wsize,wcounter_p)	do {	\
		if ((*(wcounter_p)+wsize)>kflat->size) {	\
			kflat->errno = ENOMEM;	\
			return -1;	\
		}	\
		memcpy(kflat->area+(*(wcounter_p)),addr,wsize);	\
		*wcounter_p+=wsize;	\
} while(0);

#define DBG(m)							do { if (KFLAT_ACCESSOR->FLCTRL.debug_flag&1) flat_info(m); } while(0)
#define DBGS(...)						do { if (KFLAT_ACCESSOR->FLCTRL.debug_flag&1) flat_infos(__VA_ARGS__); } while(0)
#define DBGM1(name,a1)					do { if (KFLAT_ACCESSOR->FLCTRL.debug_flag&1) flat_info(#name "(" #a1 ")\n"); } while(0)
#define DBGF(name,F,FMT,P)				do { if (KFLAT_ACCESSOR->FLCTRL.debug_flag&1) flat_infos(#name "(" #F "[" FMT "])\n",P); } while(0)
#define DBGM2(name,a1,a2)				do { if (KFLAT_ACCESSOR->FLCTRL.debug_flag&1) flat_info(#name "(" #a1 "," #a2 ")\n"); } while(0)
#define DBGTF(name,T,F,FMT,P)			do { if (KFLAT_ACCESSOR->FLCTRL.debug_flag&1) flat_infos(#name "(" #T "," #F "[" FMT "])\n",P); } while(0)
#define DBGTFMF(name,T,F,FMT,P,PF,FF)	do { if (KFLAT_ACCESSOR->FLCTRL.debug_flag&1) flat_infos(#name "(" #T "," #F "[" FMT "]," #PF "," #FF ")\n",P); } while(0)
#define DBGTP(name,T,P)					do { if (KFLAT_ACCESSOR->FLCTRL.debug_flag&1) flat_infos(#name "(" #T "," #P "[%p])\n",P); } while(0)
#define DBGM3(name,a1,a2,a3)			do { if (KFLAT_ACCESSOR->FLCTRL.debug_flag&1) flat_info(#name "(" #a1 "," #a2 "," #a3 ")\n"); } while(0)
#define DBGM4(name,a1,a2,a3,a4)			do { if (KFLAT_ACCESSOR->FLCTRL.debug_flag&1) flat_info(#name "(" #a1 "," #a2 "," #a3 "," #a4 ")\n"); } while(0)

#define ATTR(f)	((_ptr)->f)

#define STRUCT_ALIGN(n)		do { _alignment=n; } while(0)

#define FUNCTION_DEFINE_FLATTEN_STRUCT_ARRAY(FLTYPE)	\
struct flatten_pointer* flatten_struct_##FLTYPE##_array(struct kflat* kflat, const struct FLTYPE* _ptr, size_t n) {	\
	size_t _i;	\
	void* _fp_first=0;	\
	DBGS("flatten_struct_" #FLTYPE "_array(%lx,%zu)\n",(uintptr_t)_ptr,n);	\
	for (_i=0; _i<n; ++_i) {	\
		void* _fp = (void*)flatten_struct_##FLTYPE(kflat,_ptr+_i);	\
		if (!_fp) {	\
			if (_fp_first) {	\
				libflat_free(_fp_first);	\
			}	\
			break;	\
		}	\
		if (!_fp_first) _fp_first=_fp;	\
		else libflat_free(_fp);	\
	}	\
	if (kflat->errno) {	\
		return 0;	\
	}	\
    return _fp_first;	\
}

#define FUNCTION_DECLARE_FLATTEN_STRUCT_ARRAY(FLTYPE)	\
	extern struct flatten_pointer* flatten_struct_##FLTYPE##_array(struct kflat* kflat, const struct FLTYPE* _ptr, size_t n);

#define FUNCTION_DEFINE_FLATTEN_STRUCT_TYPE_ARRAY(FLTYPE)	\
struct flatten_pointer* flatten_struct_type_##FLTYPE##_array(struct kflat* kflat, const FLTYPE* _ptr, size_t n) {	\
    size_t _i;	\
	void* _fp_first=0;	\
	DBGS("flatten_struct_type_" #FLTYPE "_array(%lx,%zu)\n",(uintptr_t)_ptr,n);	\
	for (_i=0; _i<n; ++_i) {	\
		void* _fp = (void*)flatten_struct_type_##FLTYPE(kflat,_ptr+_i);	\
		if (!_fp) {	\
			if (_fp_first) {	\
				libflat_free(_fp_first);	\
			}	\
			break;	\
		}	\
		if (!_fp_first) _fp_first=_fp;	\
		else libflat_free(_fp);	\
	}	\
	if (kflat->errno) {	\
		return 0;	\
	}	\
    return _fp_first;	\
}

#define FUNCTION_DECLARE_FLATTEN_STRUCT_TYPE_ARRAY(FLTYPE)	\
	extern struct flatten_pointer* flatten_struct_type_##FLTYPE##_array(struct kflat* kflat, const FLTYPE* _ptr, size_t n);

#define FUNCTION_DEFINE_FLATTEN_STRUCT_ARRAY_ITER(FLTYPE) \
struct flatten_pointer* flatten_struct_##FLTYPE##_array_iter(struct kflat* kflat, const struct FLTYPE* _ptr, size_t n, struct bqueue* __q) {    \
    size_t _i;  \
    void* _fp_first=0;  \
    DBGS("flatten_struct_" #FLTYPE "_array_iter(%lx,%zu)\n",(uintptr_t)_ptr,n);	\
	for (_i=0; _i<n; ++_i) {    \
		void* _fp = (void*)flatten_struct_##FLTYPE##_iter(kflat,_ptr+_i,__q);    \
		if (!_fp) {	\
			if (_fp_first) {	\
				libflat_free(_fp_first);	\
			}	\
			break;	\
		}	\
		if (!_fp_first) _fp_first=_fp;  \
		else libflat_free(_fp); \
	}   \
	if (kflat->errno) {	\
		return 0;	\
	}	\
	else {	\
		return _fp_first;   \
	}	\
}

#define FUNCTION_DECLARE_FLATTEN_STRUCT_ARRAY_ITER(FLTYPE) \
	extern struct flatten_pointer* flatten_struct_##FLTYPE##_array_iter(struct kflat* kflat, const struct FLTYPE* _ptr, size_t n, struct bqueue* __q);

#define FUNCTION_DEFINE_FLATTEN_STRUCT_TYPE_ARRAY_ITER(FLTYPE)    \
struct flatten_pointer* flatten_struct_type_##FLTYPE##_array_iter(struct kflat* kflat, const FLTYPE* _ptr, size_t n, struct bqueue* __q) {    \
	size_t _i;  \
	void* _fp_first=0;  \
	DBGS("flatten_struct_type_" #FLTYPE "_array_iter(%lx,%zu)\n",(uintptr_t)_ptr,n);	\
	for (_i=0; _i<n; ++_i) {    \
		void* _fp = (void*)flatten_struct_type_##FLTYPE##_iter(kflat,_ptr+_i,__q);    \
		if (!_fp) {	\
			if (_fp_first) {	\
				libflat_free(_fp_first);	\
			}	\
			break;	\
		}	\
		if (!_fp_first) _fp_first=_fp;  \
		else libflat_free(_fp); \
	}   \
	if (kflat->errno) {	\
		return 0;	\
	}	\
	else {	\
		return _fp_first;   \
	}	\
}

#define FUNCTION_DECLARE_FLATTEN_STRUCT_TYPE_ARRAY_ITER(FLTYPE)    \
	extern struct flatten_pointer* flatten_struct_type_##FLTYPE##_array_iter(struct kflat* kflat, const FLTYPE* _ptr, size_t n, struct bqueue* __q);

#define FUNCTION_DEFINE_FLATTEN_STRUCT(FLTYPE,...)	\
			\
struct flatten_pointer* flatten_struct_##FLTYPE(struct kflat* kflat, const struct FLTYPE* _ptr) {	\
			\
	typedef struct FLTYPE _container_type;	\
	size_t _alignment = 0;	\
	struct flatten_pointer* r = 0;	\
	size_t _node_offset;	\
			\
	struct flat_node *__node = interval_tree_iter_first(&kflat->FLCTRL.imap_root, (uint64_t)_ptr, (uint64_t)_ptr+sizeof(struct FLTYPE)-1);	\
	(_container_type*)_ptr;	\
	DBGS("flatten_struct_" #FLTYPE "(%lx): [%zu]\n",(uintptr_t)_ptr,sizeof(struct FLTYPE));	\
	if (__node) {	\
		uintptr_t p = (uintptr_t)_ptr;	\
    	struct flat_node *prev;	\
    	while(__node) {	\
			if (__node->start>p) {	\
				struct flat_node* nn;	\
				if (__node->storage==0) {	\
					kflat->errno = EFAULT;	\
					DBGS("flatten_struct_" #FLTYPE "(%lx): EFAULT (__node(%lx)->storage==0)\n",(uintptr_t)_ptr,__node);	\
					return 0;	\
				}	\
				nn = libflat_zalloc(sizeof(struct flat_node),1);	\
				if (nn==0) {	\
					kflat->errno = ENOMEM;	\
					DBGS("flatten_struct_" #FLTYPE "(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
					return 0;	\
				}	\
				nn->start = p;	\
				nn->last = __node->start-1;	\
				nn->storage = binary_stream_insert_front(kflat,(void*)p,__node->start-p,__node->storage);	\
				interval_tree_insert(nn, &kflat->FLCTRL.imap_root);	\
			}	\
			p = __node->last+1;	\
			prev = __node;	\
			__node = interval_tree_iter_next(__node, (uintptr_t)_ptr, (uintptr_t)_ptr+sizeof(struct FLTYPE)-1);	\
		}	\
		if ((uintptr_t)_ptr+sizeof(struct FLTYPE)>p) {	\
			struct flat_node* nn;	\
			if (prev->storage==0) {	\
				kflat->errno = EFAULT;	\
				DBGS("flatten_struct_" #FLTYPE "(%lx): EFAULT (prev(%lx)->storage==0)\n",(uintptr_t)_ptr,prev);	\
				return 0;	\
			}	\
			nn = libflat_zalloc(sizeof(struct flat_node),1);	\
			if (nn==0) {	\
				kflat->errno = ENOMEM;	\
				DBGS("flatten_struct_" #FLTYPE "(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
				return 0;	\
			}	\
			nn->start = p;	\
			nn->last = (uintptr_t)_ptr+sizeof(struct FLTYPE)-1;	\
			nn->storage = binary_stream_insert_back(kflat,(void*)p,(uintptr_t)_ptr+sizeof(struct FLTYPE)-p,prev->storage);	\
			interval_tree_insert(nn, &kflat->FLCTRL.imap_root);	\
		}	\
	}	\
	else {	\
		struct blstream* storage;	\
		struct rb_node* rb;	\
		struct rb_node* prev;	\
		__node = libflat_zalloc(sizeof(struct flat_node),1);	\
		if (!__node) {	\
			kflat->errno = ENOMEM;	\
			DBGS("flatten_struct_" #FLTYPE "(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
			return 0;	\
		}	\
		__node->start = (uint64_t)_ptr;	\
		__node->last = (uint64_t)_ptr + sizeof(struct FLTYPE)-1;	\
		interval_tree_insert(__node, &kflat->FLCTRL.imap_root);	\
		rb = &__node->rb;	\
		prev = rb_prev(rb);	\
		if (prev) {	\
			storage = binary_stream_insert_back(kflat,_ptr,sizeof(struct FLTYPE),((struct flat_node*)prev)->storage);	\
		}	\
		else {	\
			struct rb_node* next = rb_next(rb);	\
			if (next) {	\
				storage = binary_stream_insert_front(kflat,_ptr,sizeof(struct FLTYPE),((struct flat_node*)next)->storage);	\
			}	\
			else {	\
				storage = binary_stream_append(kflat,_ptr,sizeof(struct FLTYPE));	\
			}	\
		}	\
		if (!storage) {	\
			kflat->errno = ENOMEM;	\
			DBGS("flatten_struct_" #FLTYPE "(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
			return 0;	\
		}	\
		__node->storage = storage;	\
	}	\
		\
	__VA_ARGS__	\
	if (kflat->errno) {   \
		DBGS("flatten_struct_" #FLTYPE "(%lx): %d\n",(uintptr_t)_ptr,kflat->errno);	\
		return 0;	\
	}	\
	__node = interval_tree_iter_first(&kflat->FLCTRL.imap_root, (uint64_t)_ptr, (uint64_t)_ptr+sizeof(struct FLTYPE*)-1);    \
	if (__node==0) {	\
		kflat->errno = EFAULT;	\
		DBGS("flatten_struct_" #FLTYPE "(%lx): EFAULT (__node==0)\n",(uintptr_t)_ptr);	\
		return 0;	\
	}	\
	_node_offset = (uint64_t)_ptr-__node->start;	\
	__node->storage->alignment = _alignment;	\
	__node->storage->align_offset = _node_offset;	\
    r = make_flatten_pointer(__node,_node_offset);	\
    if (!r) {	\
    	kflat->errno = ENOMEM;	\
    	DBGS("flatten_struct_" #FLTYPE "(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
    	return 0;	\
    }	\
	return r;	\
}	\
\
FUNCTION_DEFINE_FLATTEN_STRUCT_ARRAY(FLTYPE)

#define FUNCTION_DECLARE_FLATTEN_STRUCT(FLTYPE)	\
	extern struct flatten_pointer* flatten_struct_##FLTYPE(struct kflat* kflat, const struct FLTYPE*);	\
	FUNCTION_DECLARE_FLATTEN_STRUCT_ARRAY(FLTYPE)

#define FUNCTION_DEFINE_FLATTEN_STRUCT_TYPE(FLTYPE,...)	\
			\
struct flatten_pointer* flatten_struct_type_##FLTYPE(struct kflat* kflat, const FLTYPE* _ptr) {	\
			\
	typedef FLTYPE _container_type;	\
	size_t _alignment = 0;	\
	struct flatten_pointer* r = 0;	\
	size_t _node_offset;	\
			\
	struct flat_node *__node = interval_tree_iter_first(&kflat->FLCTRL.imap_root, (uint64_t)_ptr, (uint64_t)_ptr+sizeof(FLTYPE)-1);	\
	(_container_type*)_ptr;	\
	DBGS("flatten_struct_type_" #FLTYPE "(%lx): [%zu]\n",(uintptr_t)_ptr,sizeof(FLTYPE));	\
	if (__node) {	\
		uintptr_t p = (uintptr_t)_ptr;	\
    	struct flat_node *prev;	\
    	while(__node) {	\
			if (__node->start>p) {	\
				struct flat_node* nn;	\
				if (__node->storage==0) {	\
					kflat->errno = EFAULT;	\
					DBGS("flatten_struct_type_" #FLTYPE "(%lx): EFAULT (__node(%lx)->storage==0)\n",(uintptr_t)_ptr,__node);	\
					return 0;	\
				}	\
				nn = libflat_zalloc(sizeof(struct flat_node),1);	\
				if (nn==0) {	\
					kflat->errno = ENOMEM;	\
					DBGS("flatten_struct_type_" #FLTYPE "(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
					return 0;	\
				}	\
				nn->start = p;	\
				nn->last = __node->start-1;	\
				nn->storage = binary_stream_insert_front(kflat,(void*)p,__node->start-p,__node->storage);	\
				interval_tree_insert(nn, &kflat->FLCTRL.imap_root);	\
			}	\
			p = __node->last+1;	\
			prev = __node;	\
			__node = interval_tree_iter_next(__node, (uintptr_t)_ptr, (uintptr_t)_ptr+sizeof(FLTYPE)-1);	\
		}	\
		if ((uintptr_t)_ptr+sizeof(FLTYPE)>p) {	\
			struct flat_node* nn;	\
			if (prev->storage==0) {	\
				kflat->errno = EFAULT;	\
				DBGS("flatten_struct_type_" #FLTYPE "(%lx): EFAULT (prev(%lx)->storage==0)\n",(uintptr_t)_ptr,prev);	\
				return 0;	\
			}	\
			nn = libflat_zalloc(sizeof(struct flat_node),1);	\
			if (nn==0) {	\
				kflat->errno = ENOMEM;	\
				DBGS("flatten_struct_type_" #FLTYPE "(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
				return 0;	\
			}	\
			nn->start = p;	\
			nn->last = (uintptr_t)_ptr+sizeof(FLTYPE)-1;	\
			nn->storage = binary_stream_insert_back(kflat,(void*)p,(uintptr_t)_ptr+sizeof(FLTYPE)-p,prev->storage);	\
			interval_tree_insert(nn, &kflat->FLCTRL.imap_root);	\
		}	\
	}	\
	else {	\
		struct blstream* storage;	\
		struct rb_node* rb;	\
		struct rb_node* prev;	\
		__node = libflat_zalloc(sizeof(struct flat_node),1);	\
		if (!__node) {	\
			kflat->errno = ENOMEM;	\
			DBGS("flatten_struct_type_" #FLTYPE "(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
			return 0;	\
		}	\
		__node->start = (uint64_t)_ptr;	\
		__node->last = (uint64_t)_ptr + sizeof(FLTYPE)-1;	\
		interval_tree_insert(__node, &kflat->FLCTRL.imap_root);	\
		rb = &__node->rb;	\
		prev = rb_prev(rb);	\
		if (prev) {	\
			storage = binary_stream_insert_back(kflat,_ptr,sizeof(FLTYPE),((struct flat_node*)prev)->storage);	\
		}	\
		else {	\
			struct rb_node* next = rb_next(rb);	\
			if (next) {	\
				storage = binary_stream_insert_front(kflat,_ptr,sizeof(FLTYPE),((struct flat_node*)next)->storage);	\
			}	\
			else {	\
				storage = binary_stream_append(kflat,_ptr,sizeof(FLTYPE));	\
			}	\
		}	\
		if (!storage) {	\
			kflat->errno = ENOMEM;	\
			DBGS("flatten_struct_type_" #FLTYPE "(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
			return 0;	\
		}	\
		__node->storage = storage;	\
	}	\
		\
	__VA_ARGS__	\
	if (kflat->errno) {   \
		DBGS("flatten_struct_type_" #FLTYPE "(%lx): %d\n",(uintptr_t)_ptr,kflat->errno);	\
		return 0;	\
	}	\
	__node = interval_tree_iter_first(&kflat->FLCTRL.imap_root, (uint64_t)_ptr, (uint64_t)_ptr+sizeof(FLTYPE*)-1);    \
	if (__node==0) {	\
		kflat->errno = EFAULT;	\
		DBGS("flatten_struct_type_" #FLTYPE "(%lx): EFAULT (__node==0)\n",(uintptr_t)_ptr);	\
		return 0;	\
	}	\
	_node_offset = (uint64_t)_ptr-__node->start;	\
	__node->storage->alignment = _alignment;	\
	__node->storage->align_offset = _node_offset;	\
    r = make_flatten_pointer(__node,_node_offset);	\
    if (!r) {	\
    	kflat->errno = ENOMEM;	\
    	DBGS("flatten_struct_type_" #FLTYPE "(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
    	return 0;	\
    }	\
	return r;	\
}	\
\
FUNCTION_DEFINE_FLATTEN_STRUCT_TYPE_ARRAY(FLTYPE)

#define FUNCTION_DECLARE_FLATTEN_STRUCT_TYPE(FLTYPE)	\
	extern struct flatten_pointer* flatten_struct_type_##FLTYPE(struct kflat* kflat, const FLTYPE*);	\
	FUNCTION_DECLARE_FLATTEN_STRUCT_TYPE_ARRAY(FLTYPE)

#define FUNCTION_DEFINE_FLATTEN_STRUCT_ITER(FLTYPE,...)  \
			\
struct flatten_pointer* flatten_struct_##FLTYPE##_iter(struct kflat* kflat, const struct FLTYPE* _ptr, struct bqueue* __q) {    \
            \
    typedef struct FLTYPE _container_type;  \
    size_t _alignment = 0;  \
    struct flatten_pointer* r = 0;	\
    size_t _node_offset;	\
            \
    struct flat_node *__node = interval_tree_iter_first(&kflat->FLCTRL.imap_root, (uint64_t)_ptr, (uint64_t)_ptr+sizeof(struct FLTYPE)-1);    \
    (_container_type*)_ptr;	\
    DBGS("flatten_struct_" #FLTYPE "_iter(%lx): [%zu]\n",(uintptr_t)_ptr,sizeof(struct FLTYPE));	\
	if (__node) {	\
		uintptr_t p = (uintptr_t)_ptr;	\
    	struct flat_node *prev;	\
    	while(__node) {	\
			if (__node->start>p) {	\
				struct flat_node* nn;	\
				if (__node->storage==0) {	\
					kflat->errno = EFAULT;	\
					DBGS("flatten_struct_" #FLTYPE "_iter(%lx): EFAULT (__node(%lx)->storage==0)\n",(uintptr_t)_ptr,__node);	\
					return 0;	\
				}	\
				nn = libflat_zalloc(sizeof(struct flat_node),1);	\
				if (nn==0) {	\
					kflat->errno = ENOMEM;	\
					DBGS("flatten_struct_" #FLTYPE "_iter(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
					return 0;	\
				}	\
				nn->start = p;	\
				nn->last = __node->start-1;	\
				nn->storage = binary_stream_insert_front(kflat,(void*)p,__node->start-p,__node->storage);	\
				interval_tree_insert(nn, &kflat->FLCTRL.imap_root);	\
			}	\
			p = __node->last+1;	\
			prev = __node;	\
			__node = interval_tree_iter_next(__node, (uintptr_t)_ptr, (uintptr_t)_ptr+sizeof(struct FLTYPE)-1);	\
		}	\
		if ((uintptr_t)_ptr+sizeof(struct FLTYPE)>p) {	\
			struct flat_node* nn;	\
			if (prev->storage==0) {	\
				kflat->errno = EFAULT;	\
				DBGS("flatten_struct_" #FLTYPE "_iter(%lx): EFAULT (prev(%lx)->storage==0)\n",(uintptr_t)_ptr,prev);	\
				return 0;	\
			}	\
			nn = libflat_zalloc(sizeof(struct flat_node),1);	\
			if (nn==0) {	\
				kflat->errno = ENOMEM;	\
				DBGS("flatten_struct_" #FLTYPE "_iter(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
				return 0;	\
			}	\
			nn->start = p;	\
			nn->last = (uintptr_t)_ptr+sizeof(struct FLTYPE)-1;	\
			nn->storage = binary_stream_insert_back(kflat,(void*)p,(uintptr_t)_ptr+sizeof(struct FLTYPE)-p,prev->storage);	\
			interval_tree_insert(nn, &kflat->FLCTRL.imap_root);	\
		}	\
	}	\
    else {  \
    	struct blstream* storage;   \
    	struct rb_node* rb;	\
    	struct rb_node* prev;	\
    	__node = libflat_zalloc(sizeof(struct flat_node),1);   \
    	if (!__node) {	\
    		kflat->errno = ENOMEM;	\
    		DBGS("flatten_struct_" #FLTYPE "_iter(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
			return 0;	\
		}	\
        __node->start = (uint64_t)_ptr; \
        __node->last = (uint64_t)_ptr + sizeof(struct FLTYPE)-1;    \
        interval_tree_insert(__node, &kflat->FLCTRL.imap_root);   \
        rb = &__node->rb;	\
        prev = rb_prev(rb); \
        if (prev) { \
            storage = binary_stream_insert_back(kflat,_ptr,sizeof(struct FLTYPE),((struct flat_node*)prev)->storage);    \
        }   \
        else {  \
            struct rb_node* next = rb_next(rb); \
            if (next) { \
                storage = binary_stream_insert_front(kflat,_ptr,sizeof(struct FLTYPE),((struct flat_node*)next)->storage);   \
            }   \
            else {  \
                storage = binary_stream_append(kflat,_ptr,sizeof(struct FLTYPE)); \
            }   \
        }   \
		if (!storage) {	\
			kflat->errno = ENOMEM;	\
			DBGS("flatten_struct_" #FLTYPE "_iter(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
			return 0;	\
		}	\
        __node->storage = storage;  \
    }   \
        \
    __VA_ARGS__ \
	if (kflat->errno) {   \
		DBGS("flatten_struct_" #FLTYPE "_iter(%lx): %d\n",(uintptr_t)_ptr,kflat->errno);	\
		return 0;	\
	}	\
	__node = interval_tree_iter_first(&kflat->FLCTRL.imap_root, (uint64_t)_ptr, (uint64_t)_ptr+sizeof(struct FLTYPE*)-1);    \
	if (__node==0) {	\
		kflat->errno = EFAULT;	\
		DBGS("flatten_struct_" #FLTYPE "_iter(%lx): EFAULT (__node==0)\n",(uintptr_t)_ptr);	\
		return 0;	\
	}	\
	_node_offset = (uint64_t)_ptr-__node->start;	\
	__node->storage->alignment = _alignment;	\
	__node->storage->align_offset = _node_offset;	\
    r = make_flatten_pointer(__node,_node_offset);	\
    if (!r) {	\
    	kflat->errno = ENOMEM;	\
    	DBGS("flatten_struct_" #FLTYPE "_iter(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
    	return 0;	\
    }	\
	return r;	\
}	\
\
FUNCTION_DEFINE_FLATTEN_STRUCT_ARRAY_ITER(FLTYPE)

#define FUNCTION_DECLARE_FLATTEN_STRUCT_ITER(FLTYPE) \
    extern struct flatten_pointer* flatten_struct_##FLTYPE##_iter(struct kflat* kflat, const struct FLTYPE*, struct bqueue*);	\
    FUNCTION_DECLARE_FLATTEN_STRUCT_ARRAY_ITER(FLTYPE)

#define FUNCTION_DEFINE_FLATTEN_STRUCT_TYPE_ITER(FLTYPE,...)  \
            \
struct flatten_pointer* flatten_struct_type_##FLTYPE##_iter(struct kflat* kflat, const FLTYPE* _ptr, struct bqueue* __q) {    \
			\
	typedef FLTYPE _container_type;  \
	size_t _alignment = 0;  \
	struct flatten_pointer* r = 0;	\
	size_t _node_offset;	\
			\
	struct flat_node *__node = interval_tree_iter_first(&kflat->FLCTRL.imap_root, (uint64_t)_ptr, (uint64_t)_ptr+sizeof(FLTYPE)-1);    \
	(_container_type*)_ptr;	\
	DBGS("flatten_struct_type_" #FLTYPE "_iter(%lx): [%zu]\n",(uintptr_t)_ptr,sizeof(FLTYPE));	\
	if (__node) {	\
		uintptr_t p = (uintptr_t)_ptr;	\
    	struct flat_node *prev;	\
    	while(__node) {	\
			if (__node->start>p) {	\
				struct flat_node* nn;	\
				if (__node->storage==0) {	\
					kflat->errno = EFAULT;	\
					DBGS("flatten_struct_type_" #FLTYPE "_iter(%lx): EFAULT (__node(%lx)->storage==0)\n",(uintptr_t)_ptr,__node);	\
					return 0;	\
				}	\
				nn = libflat_zalloc(sizeof(struct flat_node),1);	\
				if (nn==0) {	\
					kflat->errno = ENOMEM;	\
					DBGS("flatten_struct_type_" #FLTYPE "_iter(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
					return 0;	\
				}	\
				nn->start = p;	\
				nn->last = __node->start-1;	\
				nn->storage = binary_stream_insert_front(kflat,(void*)p,__node->start-p,__node->storage);	\
				interval_tree_insert(nn, &kflat->FLCTRL.imap_root);	\
			}	\
			p = __node->last+1;	\
			prev = __node;	\
			__node = interval_tree_iter_next(__node, (uintptr_t)_ptr, (uintptr_t)_ptr+sizeof(FLTYPE)-1);	\
		}	\
		if ((uintptr_t)_ptr+sizeof(FLTYPE)>p) {	\
			struct flat_node* nn;	\
			if (prev->storage==0) {	\
				kflat->errno = EFAULT;	\
				DBGS("flatten_struct_type_" #FLTYPE "_iter(%lx): EFAULT (prev(%lx)->storage==0)\n",(uintptr_t)_ptr,prev);	\
				return 0;	\
			}	\
			nn = libflat_zalloc(sizeof(struct flat_node),1);	\
			if (nn==0) {	\
				kflat->errno = ENOMEM;	\
				DBGS("flatten_struct_type_" #FLTYPE "_iter(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
				return 0;	\
			}	\
			nn->start = p;	\
			nn->last = (uintptr_t)_ptr+sizeof(FLTYPE)-1;	\
			nn->storage = binary_stream_insert_back(kflat,(void*)p,(uintptr_t)_ptr+sizeof(FLTYPE)-p,prev->storage);	\
			interval_tree_insert(nn, &kflat->FLCTRL.imap_root);	\
		}	\
	}	\
	else {  \
		struct blstream* storage;   \
		struct rb_node* rb;	\
		struct rb_node* prev;	\
		__node = libflat_zalloc(sizeof(struct flat_node),1);   \
		if (!__node) {	\
			kflat->errno = ENOMEM;	\
			DBGS("flatten_struct_type_" #FLTYPE "_iter(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
			return 0;	\
		}	\
		__node->start = (uint64_t)_ptr; \
		__node->last = (uint64_t)_ptr + sizeof(FLTYPE)-1;    \
		interval_tree_insert(__node, &kflat->FLCTRL.imap_root);   \
		rb = &__node->rb;	\
		prev = rb_prev(rb); \
		if (prev) { \
			storage = binary_stream_insert_back(kflat,_ptr,sizeof(FLTYPE),((struct flat_node*)prev)->storage);    \
		}   \
		else {  \
			struct rb_node* next = rb_next(rb); \
			if (next) { \
				storage = binary_stream_insert_front(kflat,_ptr,sizeof(FLTYPE),((struct flat_node*)next)->storage);   \
			}   \
			else {  \
				storage = binary_stream_append(kflat,_ptr,sizeof(FLTYPE)); \
			}   \
		}   \
		if (!storage) {	\
			kflat->errno = ENOMEM;	\
			DBGS("flatten_struct_type_" #FLTYPE "_iter(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
			return 0;	\
		}	\
		__node->storage = storage;  \
	}   \
		\
	__VA_ARGS__ \
	if (kflat->errno) {   \
		DBGS("flatten_struct_type_" #FLTYPE "_iter(%lx): %d\n",(uintptr_t)_ptr,kflat->errno);	\
		return 0;	\
	}	\
	__node = interval_tree_iter_first(&kflat->FLCTRL.imap_root, (uint64_t)_ptr, (uint64_t)_ptr+sizeof(struct FLTYPE*)-1);    \
	if (__node==0) {	\
		kflat->errno = EFAULT;	\
		DBGS("flatten_struct_type_" #FLTYPE "_iter(%lx): EFAULT (__node==0)\n",(uintptr_t)_ptr);	\
		return 0;	\
	}	\
	_node_offset = (uint64_t)_ptr-__node->start;	\
	__node->storage->alignment = _alignment;	\
	__node->storage->align_offset = _node_offset;	\
    r = make_flatten_pointer(__node,_node_offset);	\
    if (!r) {	\
    	kflat->errno = ENOMEM;	\
    	DBGS("flatten_struct_type_" #FLTYPE "_iter(%lx): ENOMEM\n",(uintptr_t)_ptr);	\
    	return 0;	\
    }	\
	return r;	\
}	\
\
FUNCTION_DEFINE_FLATTEN_STRUCT_TYPE_ARRAY_ITER(FLTYPE)

#define FUNCTION_DECLARE_FLATTEN_STRUCT_TYPE_ITER(FLTYPE) \
	extern struct flatten_pointer* flatten_struct_type_##FLTYPE##_iter(struct kflat* kflat, const FLTYPE*, struct bqueue*);	\
	FUNCTION_DECLARE_FLATTEN_STRUCT_TYPE_ARRAY_ITER(FLTYPE)

#define FLATTEN_STRUCT(T,p)	\
	do {	\
		DBGTP(FLATTEN_STRUCT,T,p);	\
		if (p&&(!KFLAT_ACCESSOR->errno)) {   \
			struct fixup_set_node* __inode = fixup_set_search(KFLAT_ACCESSOR,(uintptr_t)p);	\
			if (!__inode) {	\
				int err = fixup_set_reserve_address(KFLAT_ACCESSOR,(uintptr_t)p);	\
				if (err) {	\
					DBGS("FLATTEN_STRUCT:fixup_set_reserve_address(): err(%d)\n",err);	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
				else {	\
					err = fixup_set_insert(KFLAT_ACCESSOR,__fptr->node,__fptr->offset,flatten_struct_##T(KFLAT_ACCESSOR,(p)));	\
					if ((err) && (err!=EINVAL) && (err!=EEXIST)) {	\
						DBGS("FLATTEN_STRUCT:fixup_set_insert(): err(%d)\n",err);	\
						KFLAT_ACCESSOR->errno = err;	\
					}	\
				}	\
			}	\
			else {	\
				struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uintptr_t)p,\
						(uintptr_t)p+sizeof(struct T)-1);    \
				int err = fixup_set_insert(KFLAT_ACCESSOR,__fptr->node,__fptr->offset,make_flatten_pointer(__node,(uintptr_t)p-__node->start));	\
				if ((err) && (err!=EEXIST)) {	\
					DBGS("FLATTEN_STRUCT:fixup_set_insert(): err(%d)\n",err);	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
			}	\
		}	\
	} while(0)

#define FLATTEN_STRUCT_TYPE(T,p)	\
	do {	\
		DBGTP(FLATTEN_STRUCT_TYPE,T,p);	\
		if (p&&(!KFLAT_ACCESSOR->errno)) {   \
			int err = fixup_set_insert(KFLAT_ACCESSOR,__fptr->node,__fptr->offset,flatten_struct_type_##T(KFLAT_ACCESSOR,(p)));	\
			if ((err) && (err!=ENOKEY) && (err!=EEXIST)) {	\
				KFLAT_ACCESSOR->errno = err;	\
			}	\
		}	\
	} while(0)

#define FLATTEN_STRUCT_ITER(T,p)	\
	do {    \
        DBGTP(FLATTEN_STRUCT_ITER,T,p);  \
        if (p&&(!KFLAT_ACCESSOR->errno)) {   \
			struct flatten_job __job;   \
			int err;	\
			__job.node = __fptr->node;    \
			__job.offset = __fptr->offset; \
			__job.size = 1;	\
			__job.ptr = (struct flatten_base*)p;    \
			__job.fun = (flatten_struct_t)&flatten_struct_##T##_array_iter;    \
			__job.fp = 0;   \
			__job.convert = 0;  \
			err = bqueue_push_back(__q,&__job,sizeof(struct flatten_job));    \
			if (err) {	\
				KFLAT_ACCESSOR->errno = err;	\
			}	\
        }   \
    } while(0)

#define FLATTEN_STRUCT_TYPE_ITER(T,p)	\
	do {    \
        DBGTP(FLATTEN_STRUCT_TYPE_ITER,T,p);  \
        if (p&&(!KFLAT_ACCESSOR->errno)) {   \
			struct flatten_job __job;   \
			int err;	\
			__job.node = __fptr->node;    \
			__job.offset = __fptr->offset; \
			__job.size = 1;	\
			__job.ptr = (struct flatten_base*)p;    \
			__job.fun = (flatten_struct_t)&flatten_struct_type_##T##_array_iter;    \
			__job.fp = 0;   \
			__job.convert = 0;  \
			err = bqueue_push_back(__q,&__job,sizeof(struct flatten_job));    \
			if (err) {	\
				KFLAT_ACCESSOR->errno = err;	\
			}	\
        }   \
    } while(0)

#define FLATTEN_STRUCT_ARRAY(T,p,n)	\
	do {	\
		DBGM3(FLATTEN_STRUCT_ARRAY,T,p,n);	\
		if (p&&(!KFLAT_ACCESSOR->errno)) {   \
			int err = fixup_set_insert(KFLAT_ACCESSOR,__fptr->node,__fptr->offset,flatten_struct_##T##_array(KFLAT_ACCESSOR,(p),(n)));	\
			if ((err) && (err!=ENOKEY) && (err!=EEXIST)) {	\
				KFLAT_ACCESSOR->errno = err;	\
			}	\
		}	\
	} while(0)

#define FLATTEN_STRUCT_TYPE_ARRAY(T,p,n)	\
	do {	\
		DBGM3(FLATTEN_STRUCT_TYPE_ARRAY,T,p,n);	\
		if (p&&(!KFLAT_ACCESSOR->errno)) {   \
			int err = fixup_set_insert(KFLAT_ACCESSOR,__fptr->node,__fptr->offset,flatten_struct_type_##T##_array(KFLAT_ACCESSOR,(p),(n)));	\
			if ((err) && (err!=ENOKEY) && (err!=EEXIST)) {	\
				KFLAT_ACCESSOR->errno = err;	\
			}	\
		}	\
	} while(0)

#define FLATTEN_STRUCT_ARRAY_ITER(T,p,n)	\
	do {	\
		DBGM3(FLATTEN_STRUCT_ARRAY_ITER,T,p,n);	\
		if (p&&(!KFLAT_ACCESSOR->errno)) {   \
			struct flatten_job __job;   \
			int err;	\
			__job.node = __fptr->node;    \
			__job.offset = __fptr->offset; \
			__job.size = n;	\
			__job.ptr = (struct flatten_base*)p;    \
			__job.fun = (flatten_struct_t)&flatten_struct_##T##_array_iter;    \
			__job.fp = 0;   \
			__job.convert = 0;  \
			err = bqueue_push_back(__q,&__job,sizeof(struct flatten_job));    \
			if (err) {	\
				KFLAT_ACCESSOR->errno = err;	\
			}	\
		}	\
	} while(0)

#define FLATTEN_STRUCT_TYPE_ARRAY_ITER(T,p,n)	\
	do {	\
		DBGM3(FLATTEN_STRUCT_TYPE_ARRAY_ITER,T,p,n);	\
		if (p&&(!KFLAT_ACCESSOR->errno)) {   \
			struct flatten_job __job;   \
			int err;	\
			__job.node = __fptr->node;    \
			__job.offset = __fptr->offset; \
			__job.size = n;	\
			__job.ptr = (struct flatten_base*)p;    \
			__job.fun = (flatten_struct_t)&flatten_struct_type_##T##_array_iter;    \
			__job.fp = 0;   \
			__job.convert = 0;  \
			err = bqueue_push_back(__q,&__job,sizeof(struct flatten_job));    \
			if (err) {	\
				KFLAT_ACCESSOR->errno = err;	\
			}	\
		}	\
	} while(0)

#define AGGREGATE_FLATTEN_STRUCT(T,f)	\
	do {	\
		DBGTF(AGGREGATE_FLATTEN_STRUCT,T,f,"%p",(void*)ATTR(f));	\
    	if (ATTR(f)&&(!KFLAT_ACCESSOR->errno)) {	\
    		size_t _off = offsetof(_container_type,f);	\
    		struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uint64_t)_ptr+_off,\
    				(uint64_t)_ptr+_off+sizeof(struct T*)-1);    \
    		if (__node==0) {	\
				KFLAT_ACCESSOR->errno = EFAULT;	\
			}	\
			else {	\
				struct fixup_set_node* __inode = fixup_set_search(KFLAT_ACCESSOR,(uint64_t)ATTR(f));	\
				if (!__inode) {	\
					int err = fixup_set_reserve_address(KFLAT_ACCESSOR,(uintptr_t)ATTR(f));	\
					if (err) {	\
						DBGS("AGGREGATE_FLATTEN_STRUCT:fixup_set_reserve_address(): err(%d)\n",err);	\
						KFLAT_ACCESSOR->errno = err;	\
					}	\
					else {	\
						err = fixup_set_insert(KFLAT_ACCESSOR,__node,(uint64_t)_ptr-__node->start+_off,	\
								flatten_struct_##T(KFLAT_ACCESSOR,(const struct T*)ATTR(f)));	\
						if ((err) && (err!=EEXIST)) {	\
							DBGS("AGGREGATE_FLATTEN_STRUCT:fixup_set_insert(): err(%d)\n",err);	\
							KFLAT_ACCESSOR->errno = err;	\
						}	\
					}	\
				}	\
				else {	\
					struct flat_node *__struct_node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uintptr_t)ATTR(f),\
							(uintptr_t)ATTR(f)+sizeof(struct T)-1);    \
					if (__struct_node==0) {	\
						KFLAT_ACCESSOR->errno = EFAULT;	\
					}	\
					else {	\
						int err = fixup_set_insert(KFLAT_ACCESSOR,__node,(uint64_t)_ptr-__node->start+_off,	\
							make_flatten_pointer(__struct_node,(uintptr_t)ATTR(f)-__struct_node->start));	\
						if ((err) && (err!=EEXIST)) {	\
							DBGS("FLATTEN_STRUCT:fixup_set_insert(): err(%d)\n",err);	\
							KFLAT_ACCESSOR->errno = err;	\
						}	\
					}	\
				}	\
			}	\
		}	\
	} while(0)

#define AGGREGATE_FLATTEN_STRUCT_TYPE(T,f)	\
	do {	\
		DBGTF(AGGREGATE_FLATTEN_STRUCT_TYPE,T,f,"%p",(void*)ATTR(f));	\
    	if (ATTR(f)&&(!KFLAT_ACCESSOR->errno)) {	\
    		size_t _off = offsetof(_container_type,f);	\
    		struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uint64_t)_ptr+_off,\
    				(uint64_t)_ptr+_off+sizeof(T*)-1);    \
    		if (__node==0) {	\
				KFLAT_ACCESSOR->errno = EFAULT;	\
			}	\
			else {	\
				int err=0;	\
				struct fixup_set_node* __inode = fixup_set_search(KFLAT_ACCESSOR,(uint64_t)ATTR(f));	\
				if (!__inode) {	\
					err = fixup_set_reserve(KFLAT_ACCESSOR,__node,(uint64_t)_ptr-__node->start+_off);	\
					if (!err) {	\
						err = fixup_set_update(KFLAT_ACCESSOR,__node,(uint64_t)_ptr-__node->start+_off,	\
								flatten_struct_type_##T(KFLAT_ACCESSOR,(const T*)ATTR(f)));	\
					}	\
				}	\
				if ((err) && (err!=ENOKEY) && (err!=EEXIST)) {	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
			}	\
		}	\
	} while(0)

#define AGGREGATE_FLATTEN_STRUCT_STORAGE(T,p)	\
	do {	\
		DBGTF(AGGREGATE_FLATTEN_STRUCT_STORAGE,T,p,"%p",(void*)p);	\
    	if (!KFLAT_ACCESSOR->errno) {	\
    		struct fixup_set_node* __inode = fixup_set_search((uint64_t)p);	\
    		if (!__inode) {	\
    			int err = fixup_set_reserve_address((uintptr_t)p);	\
    			if (!err) {	\
    				flatten_struct_##T(KFLAT_ACCESSOR,(const struct T*)p);	\
    			}	\
				if ((err) && (err!=ENOKEY) && (err!=EEXIST)) {	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
    		}	\
		}	\
	} while(0)

#define AGGREGATE_FLATTEN_STRUCT_TYPE_STORAGE(T,p)	\
	do {	\
	} while(0)

#define AGGREGATE_FLATTEN_STRUCT_ITER(T,f)	\
	do {    \
        DBGTF(AGGREGATE_FLATTEN_STRUCT_ITER,T,f,"%p",(void*)ATTR(f));    \
        if (ATTR(f)&&(!KFLAT_ACCESSOR->errno)) {  \
        	size_t _off = offsetof(_container_type,f);  \
        	struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uint64_t)_ptr+_off,\
        			(uint64_t)_ptr+_off+sizeof(struct T*)-1);    \
			if (__node==0) {	\
				KFLAT_ACCESSOR->errno = EFAULT;	\
			}	\
			else {	\
				struct flatten_job __job;   \
				int err;	\
				__job.node = __node;    \
				__job.offset = (uint64_t)_ptr-__node->start+_off; \
				__job.size = 1;	\
				__job.ptr = (struct flatten_base*)ATTR(f);    \
				__job.fun = (flatten_struct_t)&flatten_struct_##T##_array_iter;    \
				__job.fp = 0;   \
				__job.convert = 0;  \
				err = bqueue_push_back(__q,&__job,sizeof(struct flatten_job));    \
				if (err) {	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
			}	\
        }   \
    } while(0)

#define AGGREGATE_FLATTEN_STRUCT_TYPE_ITER(T,f)	\
	do {    \
        DBGTF(AGGREGATE_FLATTEN_STRUCT_TYPE_ITER,T,f,"%p",(void*)ATTR(f));    \
        if (ATTR(f)&&(!KFLAT_ACCESSOR->errno)) {  \
        	size_t _off = offsetof(_container_type,f);  \
        	struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uint64_t)_ptr+_off,\
        			(uint64_t)_ptr+_off+sizeof(T*)-1);    \
			if (__node==0) {	\
				KFLAT_ACCESSOR->errno = EFAULT;	\
			}	\
			else {	\
				struct flatten_job __job;   \
				int err;	\
				__job.node = __node;    \
				__job.offset = (uint64_t)_ptr-__node->start+_off; \
				__job.size = 1;	\
				__job.ptr = (struct flatten_base*)ATTR(f);    \
				__job.fun = (flatten_struct_t)&flatten_struct_type_##T##_array_iter;    \
				__job.fp = 0;   \
				__job.convert = 0;  \
				err = bqueue_push_back(__q,&__job,sizeof(struct flatten_job));    \
				if (err) {	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
			}	\
        }   \
    } while(0)

#define AGGREGATE_FLATTEN_STRUCT_STORAGE_ITER(T,f)	\
    } while(0)

#define AGGREGATE_FLATTEN_STRUCT_TYPE_STORAGE_ITER(T,f)	\
	do {    \
    } while(0)

#define AGGREGATE_FLATTEN_STRUCT_MIXED_POINTER(T,f,pre_f,post_f)	\
	do {	\
		/* Beware here, pre_f() and post_f() should return 0 when NULL arguments passed */	\
		const struct T* _fp;	\
		DBGTFMF(AGGREGATE_FLATTEN_STRUCT_MIXED_POINTER,T,f,"%p",(void*)ATTR(f),pre_f,post_f);	\
		_fp = pre_f((const struct T*)ATTR(f));	\
    	if (_fp&&(!KFLAT_ACCESSOR->errno)) {	\
    		size_t _off = offsetof(_container_type,f);	\
			struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uint64_t)_ptr+_off,\
					(uint64_t)_ptr+_off+sizeof(struct T*)-1);    \
			if (__node==0) {	\
				KFLAT_ACCESSOR->errno = EFAULT;	\
			}	\
			else {	\
				struct fixup_set_node* __inode = fixup_set_search(KFLAT_ACCESSOR,(uint64_t)_fp);	\
				if (!__inode) {	\
					int err = fixup_set_reserve_address(KFLAT_ACCESSOR,(uintptr_t)_fp);	\
					if (err) {	\
						DBGS("AGGREGATE_FLATTEN_STRUCT:fixup_set_reserve_address(): err(%d)\n",err);	\
						KFLAT_ACCESSOR->errno = err;	\
					}	\
					else {	\
						err = fixup_set_insert(KFLAT_ACCESSOR,__node,(uint64_t)_ptr-__node->start+_off,	\
								post_f(flatten_struct_##T(KFLAT_ACCESSOR,_fp),(const struct T*)ATTR(f)));	\
						if ((err) && (err!=EEXIST)) {	\
							DBGS("AGGREGATE_FLATTEN_STRUCT:fixup_set_insert(): err(%d)\n",err);	\
							KFLAT_ACCESSOR->errno = err;	\
						}	\
					}	\
				}	\
				else {	\
					struct flat_node *__struct_node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uintptr_t)_fp,\
							(uintptr_t)_fp+sizeof(struct T)-1);    \
					if (__struct_node==0) {	\
						KFLAT_ACCESSOR->errno = EFAULT;	\
					}	\
					else {	\
						int err = fixup_set_insert(KFLAT_ACCESSOR,__node,(uint64_t)_ptr-__node->start+_off,	\
							make_flatten_pointer(__struct_node,(uintptr_t)_fp-__struct_node->start));	\
						if ((err) && (err!=EEXIST)) {	\
							DBGS("FLATTEN_STRUCT:fixup_set_insert(): err(%d)\n",err);	\
							KFLAT_ACCESSOR->errno = err;	\
						}	\
					}	\
				}	\
			}	\
		}	\
	} while(0)

#define AGGREGATE_FLATTEN_STRUCT_TYPE_MIXED_POINTER(T,f,pre_f,post_f)	\
	do {	\
		/* Beware here, pre_f() and post_f() should return 0 when NULL arguments passed */	\
		const T* _fp;	\
		DBGTFMF(AGGREGATE_FLATTEN_STRUCT_TYPE_MIXED_POINTER,T,f,"%p",(void*)ATTR(f),pre_f,post_f);	\
		_fp = pre_f((const T*)ATTR(f));	\
    	if (_fp&&(!KFLAT_ACCESSOR->errno)) {	\
    		size_t _off = offsetof(_container_type,f);	\
			struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uint64_t)_ptr+_off,\
					(uint64_t)_ptr+_off+sizeof(T*)-1);    \
			if (__node==0) {	\
				KFLAT_ACCESSOR->errno = EFAULT;	\
			}	\
			else {	\
				int err=0;	\
				struct fixup_set_node* __inode = fixup_set_search(KFLAT_ACCESSOR,(uint64_t)ATTR(f));	\
				if (!__inode) {	\
					err = fixup_set_reserve(KFLAT_ACCESSOR,__node,(uint64_t)_ptr-__node->start+_off);	\
					if (!err) {	\
						err = fixup_set_update(KFLAT_ACCESSOR,__node,(uint64_t)_ptr-__node->start+_off,	\
								post_f(flatten_struct_type_##T(KFLAT_ACCESSOR,_fp),(const T*)ATTR(f));	\
					}	\
				}	\
				if ((err) && (err!=ENOKEY) && (err!=EEXIST)) {	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
			}	\
		}	\
	} while(0)

#define AGGREGATE_FLATTEN_STRUCT_STORAGE_MIXED_POINTER(T,f)	\
    } while(0)

#define AGGREGATE_FLATTEN_STRUCT_TYPE_STORAGE_MIXED_POINTER(T,f)	\
	do {    \
    } while(0)

#define AGGREGATE_FLATTEN_STRUCT_MIXED_POINTER_ITER(T,f,pre_f,post_f)	\
	do {    \
		const struct T* _fp;	\
		DBGTFMF(AGGREGATE_FLATTEN_STRUCT_MIXED_POINTER_ITER,T,f,"%p",(void*)ATTR(f),pf,ff);  \
        _fp = pre_f((const struct T*)ATTR(f)); \
        if (_fp&&(!KFLAT_ACCESSOR->errno)) {  \
        	size_t _off = offsetof(_container_type,f);  \
        	struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uint64_t)_ptr+_off,\
        			(uint64_t)_ptr+_off+sizeof(struct T*)-1);    \
			if (__node==0) {	\
				KFLAT_ACCESSOR->errno = EFAULT;	\
			}	\
			else {	\
				struct flatten_job __job;   \
				int err;	\
				__job.node = __node;    \
				__job.offset = (uint64_t)_ptr-__node->start+_off; \
				__job.size = 1;	\
				__job.ptr = (struct flatten_base*)ATTR(f);    \
				__job.fun = (flatten_struct_t)&flatten_struct_##T##_array_iter;    \
				__job.fp = (const struct flatten_base*)_fp; \
				__job.convert = (flatten_struct_mixed_convert_t)&post_f; \
				err = bqueue_push_back(__q,&__job,sizeof(struct flatten_job));    \
				if (err) {	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
			}	\
        }   \
    } while(0)

#define AGGREGATE_FLATTEN_STRUCT_TYPE_MIXED_POINTER_ITER(T,f,pre_f,post_f)	\
	do {    \
		const T* _fp;	\
		DBGTFMF(AGGREGATE_FLATTEN_STRUCT_MIXED_POINTER_ITER,T,f,"%p",(void*)ATTR(f),pf,ff);  \
        _fp = pre_f((const T*)ATTR(f)); \
        if (_fp&&(!KFLAT_ACCESSOR->errno)) {  \
        	size_t _off = offsetof(_container_type,f);  \
        	struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uint64_t)_ptr+_off,\
        			(uint64_t)_ptr+_off+sizeof(T*)-1);    \
			if (__node==0) {	\
				KFLAT_ACCESSOR->errno = EFAULT;	\
			}	\
			else {	\
				struct flatten_job __job;   \
				int err;	\
				__job.node = __node;    \
				__job.offset = (uint64_t)_ptr-__node->start+_off; \
				__job.size = 1;	\
				__job.ptr = (struct flatten_base*)ATTR(f);    \
				__job.fun = (flatten_struct_t)&flatten_struct_type_##T##_array_iter;    \
				__job.fp = (const struct flatten_base*)_fp; \
				__job.convert = (flatten_struct_mixed_convert_t)&post_f; \
				err = bqueue_push_back(__q,&__job,sizeof(struct flatten_job));    \
				if (err) {	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
			}	\
        }   \
    } while(0)

#define AGGREGATE_FLATTEN_STRUCT_STORAGE_MIXED_POINTER_ITER(T,f)	\
    } while(0)

#define AGGREGATE_FLATTEN_STRUCT_TYPE_STORAGE_MIXED_POINTER_ITER(T,f)	\
	do {    \
    } while(0)

#define AGGREGATE_FLATTEN_STRUCT_ARRAY(T,f,n)	\
	do {	\
		DBGM3(AGGREGATE_FLATTEN_STRUCT_ARRAY,T,f,n);	\
    	if (ATTR(f)&&(!KFLAT_ACCESSOR->errno)) {	\
    		size_t _off = offsetof(_container_type,f);	\
    		struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uint64_t)_ptr+_off,\
    				(uint64_t)_ptr+_off+sizeof(struct T*)-1);    \
			if (__node==0) {	\
				KFLAT_ACCESSOR->errno = EFAULT;	\
			}	\
			else {	\
				int err = fixup_set_insert(KFLAT_ACCESSOR,__node,(uint64_t)_ptr-__node->start+_off,	\
						flatten_plain_type(KFLAT_ACCESSOR,ATTR(f),(n)*sizeof(struct T)));	\
				if ((err) && (err!=EEXIST)) {	\
					DBGS("AGGREGATE_FLATTEN_STRUCT_ARRAY:fixup_set_insert(): err(%d)\n",err);	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
				else {	\
					struct fixup_set_node* __struct_inode;	\
					size_t _i;	\
					for (_i=0; _i<(n); ++_i) {	\
						struct flat_node *__struct_node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root,	\
							(uint64_t)((void*)ATTR(f)+_i*sizeof(struct T)),(uint64_t)((void*)ATTR(f)+(_i+1)*sizeof(struct T)-1));    \
						if (__struct_node==0) {	\
							err = EFAULT;	\
							break;	\
						}	\
						__struct_inode = fixup_set_search(KFLAT_ACCESSOR,(uint64_t)((void*)ATTR(f)+_i*sizeof(struct T)));	\
						if (!__struct_inode) {	\
							void* _fp;	\
							int err = fixup_set_reserve_address(KFLAT_ACCESSOR,(uint64_t)((void*)ATTR(f)+_i*sizeof(struct T)));	\
							if (err) break;	\
							_fp = (void*)flatten_struct_##T(KFLAT_ACCESSOR,(void*)ATTR(f)+_i*sizeof(struct T));	\
							libflat_free(_fp);	\
						}	\
					}	\
				}	\
				if ((err) && (err!=EEXIST)) {	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
			}	\
		}	\
	} while(0)

#define AGGREGATE_FLATTEN_STRUCT_TYPE_ARRAY(T,f,n)	\
	do {	\
		DBGM3(AGGREGATE_FLATTEN_STRUCT_TYPE_ARRAY,T,f,n);	\
    	if (ATTR(f)&&(!KFLAT_ACCESSOR->errno)) {	\
    		int err = fixup_set_insert(KFLAT_ACCESSOR,__node,offsetof(_container_type,f),flatten_struct_type_##T##_array(KFLAT_ACCESSOR,ATTR(f),n));	\
			if ((err) && (err!=ENOKEY) && (err!=EEXIST)) {	\
				KFLAT_ACCESSOR->errno = err;	\
			}	\
		}	\
	} while(0)

#define AGGREGATE_FLATTEN_STRUCT_ARRAY_ITER(T,f,n)	\
	do {	\
		DBGM3(AGGREGATE_FLATTEN_STRUCT_ARRAY_ITER,T,f,n);	\
    	if (ATTR(f)&&(!KFLAT_ACCESSOR->errno)) {	\
    		size_t _off = offsetof(_container_type,f);  \
    		struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uint64_t)_ptr+_off,\
    				(uint64_t)_ptr+_off+sizeof(struct T*)-1);    \
			if (__node==0) {	\
				KFLAT_ACCESSOR->errno = EFAULT;	\
			}	\
			else {	\
				struct flatten_job __job;   \
				int err;	\
				__job.node = __node;    \
				__job.offset = (uint64_t)_ptr-__node->start+_off; \
				__job.size = n;	\
				__job.ptr = (struct flatten_base*)ATTR(f);    \
				__job.fun = (flatten_struct_t)&flatten_struct_##T##_array_iter;    \
				__job.fp = 0;   \
				__job.convert = 0;  \
				err = bqueue_push_back(__q,&__job,sizeof(struct flatten_job));    \
				if (err) {	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
			}	\
		}	\
	} while(0)

#define AGGREGATE_FLATTEN_STRUCT_TYPE_ARRAY_ITER(T,f,n)	\
	do {	\
		DBGM3(AGGREGATE_FLATTEN_STRUCT_TYPE_ARRAY_ITER,T,f,n);	\
    	if (ATTR(f)&&(!KFLAT_ACCESSOR->errno)) {	\
    		struct flatten_job __job;   \
    		int err;	\
			__job.node = __node;    \
			__job.offset = offsetof(_container_type,f); \
			__job.size = n;	\
			__job.ptr = (struct flatten_base*)ATTR(f);    \
			__job.fun = (flatten_struct_t)&flatten_struct_type_##T##_array_iter;    \
			__job.fp = 0;   \
			__job.convert = 0;  \
			err = bqueue_push_back(__q,&__job,sizeof(struct flatten_job));    \
			if (err) {	\
				KFLAT_ACCESSOR->errno = err;	\
			}	\
		}	\
	} while(0)

/* We would probably want the following versions at some point in time as well:
 * AGGREGATE_FLATTEN_STRUCT_STORAGE_ARRAY
 * AGGREGATE_FLATTEN_STRUCT_TYPE_STORAGE_ARRAY
 * AGGREGATE_FLATTEN_STRUCT_STORAGE_ARRAY_ITER
 * AGGREGATE_FLATTEN_STRUCT_TYPE_STORAGE_ARRAY_ITER
 * AGGREGATE_FLATTEN_STRUCT_MIXED_POINTER_ARRAY
 * AGGREGATE_FLATTEN_STRUCT_TYPE_MIXED_POINTER_ARRAY
 * AGGREGATE_FLATTEN_STRUCT_STORAGE_MIXED_POINTER_ARRAY
 * AGGREGATE_FLATTEN_STRUCT_TYPE_STORAGE_MIXED_POINTER_ARRAY
 * AGGREGATE_FLATTEN_STRUCT_MIXED_POINTER_ARRAY_ITER
 * AGGREGATE_FLATTEN_STRUCT_TYPE_MIXED_POINTER_ARRAY_ITER
 * AGGREGATE_FLATTEN_STRUCT_STORAGE_MIXED_POINTER_ARRAY_ITER
 * AGGREGATE_FLATTEN_STRUCT_TYPE_STORAGE_MIXED_POINTER_ARRAY_ITER
 */

#define FLATTEN_TYPE(T,p)	\
	do {	\
		DBGM2(FLATTEN_TYPE,T,p);	\
		if (p&&(!KFLAT_ACCESSOR->errno)) {   \
			int err = fixup_set_insert(KFLAT_ACCESSOR,__fptr->node,__fptr->offset,flatten_plain_type(KFLAT_ACCESSOR,(p),sizeof(T)));	\
			if ((err) && (err!=ENOKEY) && (err!=EEXIST)) {	\
				KFLAT_ACCESSOR->errno = err;	\
			}	\
		}	\
	} while(0)


#define FLATTEN_TYPE_ARRAY(T,p,n)	\
	do {	\
		DBGM3(FLATTEN_TYPE_ARRAY,T,p,n);	\
		if (p&&(!KFLAT_ACCESSOR->errno)) {   \
			int err = fixup_set_insert(KFLAT_ACCESSOR,__fptr->node,__fptr->offset,flatten_plain_type(KFLAT_ACCESSOR,(p),(n)*sizeof(T)));	\
			if ((err) && (err!=ENOKEY) && (err!=EEXIST)) {	\
				KFLAT_ACCESSOR->errno = err;	\
			}	\
		}	\
	} while(0)

#define FLATTEN_STRING(p)	\
	do {	\
		DBGM1(FLATTEN_STRING,p);	\
		if (p&&(!KFLAT_ACCESSOR->errno)) {   \
			int err = fixup_set_insert(KFLAT_ACCESSOR,__fptr->node,__fptr->offset,flatten_plain_type(KFLAT_ACCESSOR,(p),strmemlen(p)));	\
			if ((err) && (err!=ENOKEY) && (err!=EEXIST)) {	\
				KFLAT_ACCESSOR->errno = err;	\
			}	\
		}	\
	} while(0)

#define AGGREGATE_FLATTEN_TYPE(T,f)	\
	do {  \
		DBGM2(AGGREGATE_FLATTEN_TYPE,T,f);	\
        if (ATTR(f)&&(!KFLAT_ACCESSOR->errno)) {   \
        	size_t _off = offsetof(_container_type,f);	\
        	struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uint64_t)_ptr+_off,\
        			(uint64_t)_ptr+_off+sizeof(T*)-1);    \
			if (__node==0) {	\
				KFLAT_ACCESSOR->errno = EFAULT;	\
			}	\
			else {	\
				int err=0;	\
				struct fixup_set_node* __inode = fixup_set_search(KFLAT_ACCESSOR,(uint64_t)ATTR(f));	\
				if (!__inode) {	\
					err = fixup_set_reserve(KFLAT_ACCESSOR,__node,(uint64_t)_ptr-__node->start+_off);	\
					if (!err) {	\
						err = fixup_set_update(KFLAT_ACCESSOR,__node,(uint64_t)_ptr-__node->start+_off,	\
								flatten_plain_type(KFLAT_ACCESSOR,ATTR(f),sizeof(T)));	\
					}	\
				}	\
				if ((err) && (err!=ENOKEY) && (err!=EEXIST)) {	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
			}	\
        }   \
    } while(0)

#define AGGREGATE_FLATTEN_TYPE_ARRAY(T,f,n)	\
	do {  \
		DBGM3(AGGREGATE_FLATTEN_TYPE_ARRAY,T,f,n);	\
        if (ATTR(f)&&(!KFLAT_ACCESSOR->errno)) {   \
        	size_t _off = offsetof(_container_type,f);	\
        	struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uint64_t)_ptr+_off,\
					(uint64_t)_ptr+_off+sizeof(T*)-1);    \
			if (__node==0) {	\
				KFLAT_ACCESSOR->errno = EFAULT;	\
			}	\
			else {	\
				int err = fixup_set_insert(KFLAT_ACCESSOR,__node,(uint64_t)_ptr-__node->start+_off,	\
						flatten_plain_type(KFLAT_ACCESSOR,ATTR(f),(n)*sizeof(T)));	\
				if ((err) && (err!=EEXIST)) {	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
			}	\
        }   \
    } while(0)

#define AGGREGATE_FLATTEN_STRING(f)	\
	do {  \
		DBGF(AGGREGATE_FLATTEN_STRING,f,"%p",(void*)ATTR(f));	\
        if (ATTR(f)&&(!KFLAT_ACCESSOR->errno)) {   \
        	size_t _off = offsetof(_container_type,f);	\
			struct flat_node *__node = interval_tree_iter_first(&KFLAT_ACCESSOR->FLCTRL.imap_root, (uint64_t)_ptr+_off,\
					(uint64_t)_ptr+_off+sizeof(char*)-1);    \
			if (__node==0) {	\
				KFLAT_ACCESSOR->errno = EFAULT;	\
			}	\
			else {	\
				int err = fixup_set_insert(KFLAT_ACCESSOR,__node,(uint64_t)_ptr-__node->start+_off,	\
						flatten_plain_type(KFLAT_ACCESSOR,ATTR(f),strmemlen(ATTR(f))));	\
				if ((err) && (err!=ENOKEY) && (err!=EEXIST)) {	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
			}	\
        }   \
    } while(0)

#define AGGREGATE_FLATTEN_FUNCTION_POINTER(f)	\
	do {	\
	} while (0)

#define FOR_POINTER(PTRTYPE,v,p,...)	\
	do {	\
		DBGM3(FOR_POINTER,PTRTYPE,v,p);	\
		if (p&&(!KFLAT_ACCESSOR->errno)) {	\
			PTRTYPE const * _m = (PTRTYPE const *)(p);	\
			struct flatten_pointer* __fptr = get_pointer_node(KFLAT_ACCESSOR,_m);	\
			if (__fptr) {	\
				PTRTYPE v = *(_m);	\
				__VA_ARGS__;	\
				libflat_free(__fptr);	\
			}	\
			else {	\
				KFLAT_ACCESSOR->errno = ENOMEM;	\
			}	\
		}	\
	} while(0)

#define FOREACH_POINTER(PTRTYPE,v,p,s,...)	\
	do {	\
		DBGM4(FOREACH_POINTER,PTRTYPE,v,p,s);	\
		if (p&&(!KFLAT_ACCESSOR->errno)) {	\
			PTRTYPE const * _m = (PTRTYPE const *)(p);	\
			size_t _i, _sz = (s);	\
			for (_i=0; _i<_sz; ++_i) {	\
				struct flatten_pointer* __fptr = get_pointer_node(KFLAT_ACCESSOR,_m+_i);	\
				if (__fptr) {	\
					PTRTYPE v = *(_m+_i);	\
					__VA_ARGS__;	\
					libflat_free(__fptr);	\
				} \
				else {	\
					KFLAT_ACCESSOR->errno = ENOMEM;	\
					break;	\
				}	\
			}	\
		}	\
	} while(0)

#define FOR_ROOT_POINTER(p,...)	\
	do {	\
		DBGM1(FOR_ROOT_POINTER,p);	\
		if (p&&(!KFLAT_ACCESSOR->errno)) {	\
			struct flatten_pointer* __fptr = make_flatten_pointer(0,0);	\
			if (__fptr) {	\
				__VA_ARGS__;	\
				libflat_free(__fptr);	\
			}	\
			else {	\
				KFLAT_ACCESSOR->errno = ENOMEM;	\
			}	\
		}	\
		if (!KFLAT_ACCESSOR->errno) {	\
			KFLAT_ACCESSOR->errno = root_addr_append(KFLAT_ACCESSOR, (uintptr_t)(p) );	\
		}	\
	} while(0)

#define UNDER_ITER_HARNESS(...)	\
		do {	\
			struct bqueue bq;	\
			struct bqueue* __q;	\
			int err = bqueue_init(&bq,DEFAULT_ITER_QUEUE_SIZE);	\
			if (err) {	\
				KFLAT_ACCESSOR->errno = err;	\
				break;	\
			}	\
			__q = &bq;	\
			__VA_ARGS__	\
			while((!KFLAT_ACCESSOR->errno)&&(!bqueue_empty(&bq))) {	\
				struct flatten_job __job;	\
				int err = bqueue_pop_front(&bq,&__job,sizeof(struct flatten_job));	\
				if (err) {	\
					KFLAT_ACCESSOR->errno = err;	\
					break;	\
				}	\
				if (!__job.convert)	\
					err = fixup_set_insert(KFLAT_ACCESSOR,__job.node,__job.offset,(__job.fun)(KFLAT_ACCESSOR,__job.ptr,__job.size,&bq));	\
				else	\
					err = fixup_set_insert(KFLAT_ACCESSOR,__job.node,__job.offset,__job.convert((__job.fun)(KFLAT_ACCESSOR,__job.fp,__job.size,&bq),__job.ptr));	\
				if ((err) && (err!=ENOKEY) && (err!=EEXIST)) {	\
					KFLAT_ACCESSOR->errno = err;	\
				}	\
			}	\
			bqueue_destroy(&bq);	\
		} while(0)

#define PTRNODE(PTRV)	(interval_tree_iter_first(&kflat->FLCTRL.imap_root, (uintptr_t)(PTRV), (uintptr_t)(PTRV)))
#define FLATTEN_MEMORY_START	((unsigned char*)kflat->FLCTRL.mem+kflat->FLCTRL.HDR.ptr_count*sizeof(size_t))
#define FLATTEN_MEMORY_END		(FLATTEN_MEMORY_START+kflat->FLCTRL.HDR.memory_size)

#include <kflat_recipe.h>

#endif /* _LINUX_KFLAT_H */

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
#include <linux/kflat.h>

#define START(node) ((node)->start)
#define LAST(node)  ((node)->last)

struct rb_root recipe_fns = RB_ROOT;
struct kflat kflat_g;
struct kflat* kflat_g_p;
int kflat_g_filter_pid_cache;
int kflat_g_debug_cache;
struct rb_root if_fns = RB_ROOT;
EXPORT_SYMBOL(recipe_fns);

struct recipe_node* recipe_search(const char* s) {

	struct rb_node *node = recipe_fns.rb_node;

	while (node) {
		struct recipe_node* data = container_of(node, struct recipe_node, node);

		if (strcmp(s,data->s)<0) {
			node = node->rb_left;
		}
		else if (strcmp(s,data->s)>0) {
			node = node->rb_right;
		}
		else
			return data;
	}

	return 0;
}
EXPORT_SYMBOL(recipe_search);

int recipe_insert(const char* s, flatten_struct_f f) {

	struct recipe_node* data = libflat_zalloc(1,sizeof(struct recipe_node));
	struct rb_node **new, *parent = 0;
	data->s = libflat_zalloc(1,strlen(s)+1);
	strcpy(data->s,s);
	data->f = f;
	new = &(recipe_fns.rb_node);

	/* Figure out where to put new node */
	while (*new) {
		struct recipe_node* this = container_of(*new, struct recipe_node, node);

		parent = *new;
		if (strcmp(data->s,this->s)<0)
			new = &((*new)->rb_left);
		else if (strcmp(data->s,this->s)>0)
			new = &((*new)->rb_right);
		else {
		    libflat_free((void*)data->s);
		    libflat_free(data);
		    return 0;
		}
	}

	/* Add new node and rebalance tree. */
	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, &recipe_fns);

	return 1;
}
EXPORT_SYMBOL(recipe_insert);

int recipe_iter_insert(const char* s, flatten_struct_iter_f iterf) {

	struct recipe_node* data = libflat_zalloc(1,sizeof(struct recipe_node));
	struct rb_node **new, *parent = 0;
	data->s = libflat_zalloc(1,strlen(s)+1);
	strcpy(data->s,s);
	data->iterf = iterf;
	new = &(recipe_fns.rb_node);

	/* Figure out where to put new node */
	while (*new) {
		struct recipe_node* this = container_of(*new, struct recipe_node, node);

		parent = *new;
		if (strcmp(data->s,this->s)<0)
			new = &((*new)->rb_left);
		else if (strcmp(data->s,this->s)>0)
			new = &((*new)->rb_right);
		else {
		    libflat_free((void*)data->s);
		    libflat_free(data);
		    return 0;
		}
	}

	/* Add new node and rebalance tree. */
	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, &recipe_fns);

	return 1;
}
EXPORT_SYMBOL(recipe_iter_insert);

int recipe_delete(const char* s) {

	struct recipe_node* node = recipe_search(s);
	if (node) {
		rb_erase(&node->node, &recipe_fns);
		return 1;
	}
	return 0;
}
EXPORT_SYMBOL(recipe_delete);

void recipe_destroy(void) {

	struct rb_root* root = &recipe_fns;
	struct rb_node * p = rb_first(root);
    while(p) {
        struct recipe_node* data = (struct recipe_node*)p;
        rb_erase(p, root);
        p = rb_next(p);
        libflat_free((void*)data->s);
        libflat_free(data);
    }
}
EXPORT_SYMBOL(recipe_destroy);

size_t recipe_count(void) {

	struct rb_root* root = &recipe_fns;
	struct rb_node * p = rb_first(root);
	size_t count = 0;
	while(p) {
		count++;
		p = rb_next(p);
	}
	return count;
}
EXPORT_SYMBOL(recipe_count);

struct ifns_node* ifns_search(const char* s) {

	struct rb_node *node = if_fns.rb_node;

	while (node) {
		struct ifns_node* data = container_of(node, struct ifns_node, node);

		if (strcmp(s,data->s)<0) {
			node = node->rb_left;
		}
		else if (strcmp(s,data->s)>0) {
			node = node->rb_right;
		}
		else
			return data;
	}

	return 0;
}
EXPORT_SYMBOL(ifns_search);

int ifns_insert(const char* s, void* arg) {

	struct ifns_node* data = libflat_zalloc(1,sizeof(struct ifns_node));
	struct rb_node **new, *parent = 0;
	data->s = libflat_zalloc(1,strlen(s)+1);
	strcpy(data->s,s);
	data->f = arg;
	new = &(if_fns.rb_node);

	/* Figure out where to put new node */
	while (*new) {
		struct ifns_node* this = container_of(*new, struct ifns_node, node);

		parent = *new;
		if (strcmp(data->s,this->s)<0)
			new = &((*new)->rb_left);
		else if (strcmp(data->s,this->s)>0)
			new = &((*new)->rb_right);
		else {
		    libflat_free((void*)data->s);
		    libflat_free(data);
		    return 0;
		}
	}

	/* Add new node and rebalance tree. */
	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, &if_fns);

	return 1;
}
EXPORT_SYMBOL(ifns_insert);

int ifns_delete(const char* s) {

	struct ifns_node* node = ifns_search(s);
	if (node) {
		rb_erase(&node->node, &if_fns);
		return 1;
	}
	return 0;
}
EXPORT_SYMBOL(ifns_delete);

void ifns_destroy(void) {

	struct rb_root* root = &if_fns;
	struct rb_node * p = rb_first(root);
    while(p) {
        struct ifns_node* data = (struct ifns_node*)p;
        rb_erase(p, root);
        p = rb_next(p);
        libflat_free((void*)data->s);
        libflat_free(data);
    }
}
EXPORT_SYMBOL(ifns_destroy);

size_t ifns_count(void) {

	const struct rb_root* root = &if_fns;
	struct rb_node * p = rb_first(root);
	size_t count = 0;
	while(p) {
		count++;
		p = rb_next(p);
	}
	return count;
}
EXPORT_SYMBOL(ifns_count);

INTERVAL_TREE_DEFINE(struct flat_node, rb,
		     uintptr_t, __subtree_last,
		     START, LAST,static,interval_tree)

static struct blstream* create_binary_stream_element(struct kflat* kflat, size_t size) {
	struct blstream* n;
	void* m;
	n = kflat_zalloc(kflat,sizeof(struct blstream),1);
	if (n==0) return 0;
	m = kflat_zalloc(kflat,size,1);
	if (m==0) {
		kflat_free(n);
		return 0;
	}
	n->data = m;
	n->size = size;
	return n;
}

struct blstream* binary_stream_append(struct kflat* kflat, const void* data, size_t size) {
	struct blstream* v = create_binary_stream_element(kflat,size);
	if (v==0) return 0;
	memcpy(v->data,data,size);
    if (!kflat->FLCTRL.bhead) {
    	kflat->FLCTRL.bhead = v;
    	kflat->FLCTRL.btail = v;
    }
    else {
        v->prev = kflat->FLCTRL.btail;
        kflat->FLCTRL.btail->next = v;
        kflat->FLCTRL.btail = kflat->FLCTRL.btail->next;
    }
    return v;
}
EXPORT_SYMBOL(binary_stream_append);


struct blstream* binary_stream_append_reserve(struct kflat* kflat, size_t size) {
	struct blstream* v = kflat_zalloc(kflat,sizeof(struct blstream),1);
	if (v==0) return 0;
	v->data = 0;
	v->size = size;
	if (!kflat->FLCTRL.bhead) {
		kflat->FLCTRL.bhead = v;
		kflat->FLCTRL.btail = v;
    }
    else {
        v->prev = kflat->FLCTRL.btail;
        kflat->FLCTRL.btail->next = v;
        kflat->FLCTRL.btail = kflat->FLCTRL.btail->next;
    }
    return v;
}

struct blstream* binary_stream_update(struct kflat* kflat, const void* data, size_t size, struct blstream* where) {
	void* m = kflat_zalloc(kflat,size,1);
	if (m==0) return 0;
	where->data = m;
	memcpy(where->data,data,size);
	return where;
}


struct blstream* binary_stream_insert_front(struct kflat* kflat, const void* data, size_t size, struct blstream* where) {
	struct blstream* v = create_binary_stream_element(kflat,size);
	if (v==0) return 0;
	memcpy(v->data,data,size);
	v->next = where;
	v->prev = where->prev;
	if (where->prev) {
		where->prev->next = v;
	}
	else {
		kflat->FLCTRL.bhead = v;
	}
	where->prev = v;
	return v;
}
EXPORT_SYMBOL(binary_stream_insert_front);

struct blstream* binary_stream_insert_front_reserve(struct kflat* kflat, size_t size, struct blstream* where) {
	struct blstream* v = kflat_zalloc(kflat,sizeof(struct blstream),1);
	if (v==0) return 0;
	v->data = 0;
	v->size = size;
	v->next = where;
	v->prev = where->prev;
	if (where->prev) {
		where->prev->next = v;
	}
	else {
		kflat->FLCTRL.bhead = v;
	}
	where->prev = v;
	return v;
}

struct blstream* binary_stream_insert_back(struct kflat* kflat, const void* data, size_t size, struct blstream* where) {
	struct blstream* v = create_binary_stream_element(kflat,size);
	if (v==0) return 0;
	memcpy(v->data,data,size);
	v->next = where->next;
	v->prev = where;
	if (where->next) {
		where->next->prev = v;
	}
	else {
		kflat->FLCTRL.btail = v;
	}
	where->next = v;
	return v;
}
EXPORT_SYMBOL(binary_stream_insert_back);

struct blstream* binary_stream_insert_back_reserve(struct kflat* kflat, size_t size, struct blstream* where) {
	struct blstream* v = kflat_zalloc(kflat,sizeof(struct blstream),1);
	if (v==0) return 0;
	v->data = 0;
	v->size = size;
	v->next = where->next;
	v->prev = where;
	if (where->next) {
		where->next->prev = v;
	}
	else {
		kflat->FLCTRL.btail = v;
	}
	where->next = v;
	return v;
}

int binary_stream_calculate_index(struct kflat* kflat) {
	struct blstream* p = kflat->FLCTRL.bhead;
	size_t index=0;
    while(p) {
    	struct blstream* cp = p;
#if 0
    	size_t align=0;
#endif
    	p = p->next;
#if 0
    	if (cp->alignment) {
    		struct blstream* v;
    		unsigned char* padding = kflat_zalloc(kflat,cp->alignment,1);
    		if (!padding) {
    			return ENOMEM;
    		}
    		if (index==0) {
    			align=cp->alignment;
    		}
    		else if (index%cp->alignment) {
    			align=cp->alignment-(index%cp->alignment);
    		}
    		v = binary_stream_insert_front(kflat,padding,align,cp);
    		if (v==0) return ENOMEM;
    		kflat_free(padding);
    		v->index = index;
    		index+=v->size;
    	}
#endif

    	cp->index = index;
    	index+=cp->size;
    }
    return 0;
}

void binary_stream_destroy(struct kflat* kflat) {
	kflat->FLCTRL.btail = kflat->FLCTRL.bhead;
    while(kflat->FLCTRL.btail) {
    	struct blstream* p = kflat->FLCTRL.btail;
    	kflat->FLCTRL.btail = kflat->FLCTRL.btail->next;
    	kflat_free(p->data);
    	kflat_free(p);
    }
}

static void binary_stream_element_print(struct blstream* p) {
	flat_infos("(%zu)(%zu)[%zu]{%lx}[...]\n",p->index,p->alignment,p->size,(unsigned long)p);
}

void binary_stream_element_print_data(struct blstream* p) {
	size_t i;
	flat_infos("(%zu)(%zu)[%zu]{%lx}[ ",p->index,p->alignment,p->size,(unsigned long)p);
	for (i=0; i<p->size; ++i) {
		flat_infos("%02x ",((unsigned char*)(p->data))[i]);
	}
	flat_info("]\n");
}

static int binary_stream_element_write(struct kflat* kflat, struct blstream* p, size_t* wcounter_p) {

	FLATTEN_WRITE_ONCE((unsigned char*)(p->data),p->size,wcounter_p);
	return 0;
}

void binary_stream_print(struct kflat* kflat) {

	struct blstream* cp = kflat->FLCTRL.bhead;
	size_t total_size = 0;
    while(cp) {
    	struct blstream* p = cp;
    	cp = cp->next;
    	binary_stream_element_print(p);
    	total_size+=p->size;
    }
    flat_infos("@ Total size: %zu\n",total_size);
}

size_t binary_stream_write(struct kflat* kflat, size_t* wcounter_p) {
	int err;
	struct blstream* cp = kflat->FLCTRL.bhead;
    while(cp) {
    	struct blstream* p = cp;
    	cp = cp->next;
    	if ((err = binary_stream_element_write(kflat,p,wcounter_p))!=0) {
    		return err;
    	}
    }
    return 0;
}

size_t binary_stream_size(struct kflat* kflat) {

	struct blstream* cp = kflat->FLCTRL.bhead;
	size_t total_size = 0;
    while(cp) {
    	struct blstream* p = cp;
    	cp = cp->next;
    	total_size+=p->size;
    }
    return total_size;
}

void binary_stream_update_pointers(struct kflat* kflat) {
	struct rb_node * p = rb_first(&kflat->FLCTRL.fixup_set_root.rb_root);
	int count=0;
	while(p) {
    	struct fixup_set_node* node = (struct fixup_set_node*)p;
    	if ((node->ptr)&&(!(((unsigned long)node->ptr)&1))) {
			void* newptr = (unsigned char*)node->ptr->node->storage->index+node->ptr->offset;
			DBGS("@ ptr update at ((%lx)%lx:%zu) : %lx => %lx\n",(unsigned long)node->inode,(unsigned long)node->inode->start,node->offset,
					(unsigned long)newptr,(unsigned long)(((unsigned char*)node->inode->storage->data)+node->offset));
			memcpy(&((unsigned char*)node->inode->storage->data)[node->offset],&newptr,sizeof(void*));
    	}
    	p = rb_next(p);
    	count++;
    }
}

int bqueue_init(struct kflat* kflat, struct bqueue* q, size_t block_size) {

    q->block_size = block_size;
    q->size = 0;
    q->front_block = kflat_bqueue_zalloc(kflat,block_size+sizeof(struct queue_block*),1);
    if (!q->front_block) {
    	return ENOMEM;
    }
    q->front_block->next = 0;
    q->back_block = q->front_block;
    q->front_index=0;
    q->back_index=0;
    return 0;
}
EXPORT_SYMBOL(bqueue_init);

void bqueue_destroy(struct bqueue* q) {

    struct queue_block* back = q->back_block;
    while(back) {
        struct queue_block* tmp = back;
        back = back->next;
        kflat_bqueue_free(tmp);
    }
}
EXPORT_SYMBOL(bqueue_destroy);

int bqueue_empty(struct bqueue* q) {

    return q->size == 0;
}
EXPORT_SYMBOL(bqueue_empty);

size_t bqueue_size(struct bqueue* q) {

    return q->size;
}
EXPORT_SYMBOL(bqueue_size);


int bqueue_push_back(struct kflat* kflat, struct bqueue* q, const void* m, size_t s) {

    size_t copied = 0;
    while(s>0) {
        size_t avail_size = q->block_size-q->front_index;
        size_t copy_size = (s>avail_size)?(avail_size):(s);
        memcpy(q->front_block->data+q->front_index,m+copied,copy_size);
        copied+=copy_size;
        if (unlikely(s>=avail_size)) {
        	struct queue_block* new_block;
            s=s-avail_size;
            new_block = kflat_bqueue_zalloc(kflat,q->block_size+sizeof(struct queue_block*),1);
            if (!new_block) {
            	return ENOMEM;
            }
            new_block->next = 0;
            q->front_block->next = new_block;
            q->front_block = new_block;
        }
        else s=0;
        q->front_index = (q->front_index+copy_size)%q->block_size;
    }
    q->size+=copied;
    return 0;
}
EXPORT_SYMBOL(bqueue_push_back);

int bqueue_pop_front(struct bqueue* q, void* m, size_t s) {

	size_t copied = 0;

	if (q->size<s) {
    	flat_err("bqueue underflow");
    	return EFAULT;
    }

    while(s>0) {
        size_t avail_size = q->block_size-q->back_index;
        size_t copy_size = (s>avail_size)?(avail_size):(s);
        memcpy(m+copied,q->back_block->data+q->back_index,copy_size);
        copied+=copy_size;
        if (s>=avail_size) {
        	struct queue_block* tmp;
        	s=s-avail_size;
            tmp = q->back_block;
            q->back_block = q->back_block->next;
            kflat_bqueue_free(tmp);
        }
        else s=0;
        q->back_index = (q->back_index+copy_size)%q->block_size;
    }
    q->size-=copied;

    return 0;
}
EXPORT_SYMBOL(bqueue_pop_front);

#define ADDR_KEY(p)	((((p)->inode)?((p)->inode->start):0) + (p)->offset)

static struct fixup_set_node* create_fixup_set_node_element(struct kflat* kflat, struct flat_node* node, size_t offset, struct flatten_pointer* ptr) {
	struct fixup_set_node* n = kflat_zalloc(kflat,sizeof(struct fixup_set_node),1);
	if (n==0) return 0;
	n->inode = node;
	n->offset = offset;
	n->ptr = ptr;
	return n;
}

struct fixup_set_node *fixup_set_search(struct kflat* kflat, uintptr_t v) {
	struct rb_node *node = kflat->FLCTRL.fixup_set_root.rb_root.rb_node;

	while (node) {
		struct fixup_set_node *data = container_of(node, struct fixup_set_node, node);

		if (v < ADDR_KEY(data)) {
			node = node->rb_left;
		}
		else if (v > ADDR_KEY(data)) {
			node = node->rb_right;
		}
		else {
			DBGS("fixup_set_search(%lx): (%lx:%zu,%lx)\n",v,(unsigned long)data->inode,data->offset,(unsigned long)data->ptr);
			return data;
		}
	}

	DBGS("fixup_set_search(%lx): 0\n",v);
	return 0;
}
EXPORT_SYMBOL(fixup_set_search);

int fixup_set_reserve_address(struct kflat* kflat, uintptr_t addr) {

	struct fixup_set_node *data;
	struct rb_node **new, *parent;
	struct fixup_set_node* inode;

	DBGS("fixup_set_reserve_address(%lx)\n",addr);

	inode = fixup_set_search(kflat,addr);

	if (inode) {
		return EEXIST;
	}

	new = &(kflat->FLCTRL.fixup_set_root.rb_root.rb_node);
	parent = 0;

	data = create_fixup_set_node_element(kflat,0,addr,0);
	if (!data) {
		return ENOMEM;
	}

	/* Figure out where to put new node */
	while (*new) {
		struct fixup_set_node *this = container_of(*new, struct fixup_set_node, node);

		parent = *new;
		if (data->offset < ADDR_KEY(this))
			new = &((*new)->rb_left);
		else if (data->offset > ADDR_KEY(this))
			new = &((*new)->rb_right);
		else
			return EEXIST;
	}

	/* Add new node and rebalance tree. */
	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, &kflat->FLCTRL.fixup_set_root.rb_root);

	return 0;
}
EXPORT_SYMBOL(fixup_set_reserve_address);

int fixup_set_reserve(struct kflat* kflat, struct flat_node* node, size_t offset) {

	struct fixup_set_node* inode;
	struct fixup_set_node *data;
	struct rb_node **new, *parent;

	DBGS("fixup_set_reserve(%lx,%zu)\n",(uintptr_t)node,offset);

	if (node==0) {
		return EINVAL;
	}

	inode = fixup_set_search(kflat,node->start+offset);

	if (inode) {
		return EEXIST;
	}

	data = create_fixup_set_node_element(kflat,node,offset,0);
	if (!data) {
		return ENOMEM;
	}

	new = &(kflat->FLCTRL.fixup_set_root.rb_root.rb_node);
	parent = 0;

	/* Figure out where to put new node */
	while (*new) {
		struct fixup_set_node *this = container_of(*new, struct fixup_set_node, node);

		parent = *new;
		if (ADDR_KEY(data) < ADDR_KEY(this))
			new = &((*new)->rb_left);
		else if (ADDR_KEY(data) > ADDR_KEY(this))
			new = &((*new)->rb_right);
		else
			return EEXIST;
	}

	/* Add new node and rebalance tree. */
	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, &kflat->FLCTRL.fixup_set_root.rb_root);

	return 0;
}

int fixup_set_update(struct kflat* kflat, struct flat_node* node, size_t offset, struct flatten_pointer* ptr) {

	struct fixup_set_node* inode;

	DBGS("fixup_set_update(%lx[%lx:%zu],%zu,%lx)\n",(uintptr_t)node,
			(node)?(node->start):0,(node)?(node->last-node->start+1):0,
			offset,(uintptr_t)ptr);

	if (node==0) {
		kflat_free(ptr);
		return EINVAL;
	}

	inode = fixup_set_search(kflat,node->start+offset);

	if (!inode) {
		return ENOKEY;
	}

	if (!inode->inode) {
		if ((node->start + offset)!=inode->offset) {
			flat_err("node address not matching reserved offset");
			return EFAULT;
		}
		rb_erase(&inode->node, &kflat->FLCTRL.fixup_set_root.rb_root);
		return fixup_set_insert(kflat,node,offset,ptr);
	}

	inode->ptr = ptr;

	return 0;
}

int fixup_set_insert(struct kflat* kflat, struct flat_node* node, size_t offset, struct flatten_pointer* ptr) {

	struct fixup_set_node* inode;
	struct fixup_set_node *data;
	struct rb_node **new, *parent;

	DBGS("fixup_set_insert(%lx[%lx:%zu],%zu,%lx)\n",(uintptr_t)node,
			(node)?(node->start):0,(node)?(node->last-node->start+1):0,
			offset,(uintptr_t)ptr);

	if (!ptr) {
		DBG("fixup_set_insert(...): ptr - EINVAL\n");
		return EINVAL;
	}

	if (node==0) {
		kflat_free(ptr);
		DBG("fixup_set_insert(...): node - EINVAL\n");
		return EINVAL;
	}

	inode = fixup_set_search(kflat,node->start+offset);

	if (inode && inode->inode) {
		uintptr_t inode_ptr;
		if (((unsigned long)inode->ptr)&1) {
			inode_ptr = ((unsigned long)inode->ptr)&(~1);
		}
		else {
			inode_ptr = inode->ptr->node->start + inode->ptr->offset;
		}
		if (inode_ptr!=ptr->node->start+ptr->offset) {
			flat_errs("fixup_set_insert(...): multiple pointer mismatch for the same storage [%d]: (%lx vs %lx)\n",
					((unsigned long)inode->ptr)&1,inode_ptr,ptr->node->start+ptr->offset);
			kflat_free(ptr);
			DBG("fixup_set_insert(...): EFAULT\n");
			return EFAULT;
		}
		kflat_free(ptr);
		DBG("fixup_set_insert(...): node - EEXIST\n");
		return EEXIST;
	}

	if (inode) {
		return fixup_set_update(kflat,node, offset, ptr);
	}

	data = create_fixup_set_node_element(kflat,node,offset,ptr);
	if (!data) {
		kflat_free(ptr);
		return ENOMEM;
	}
	new = &(kflat->FLCTRL.fixup_set_root.rb_root.rb_node);
	parent = 0;

	/* Figure out where to put new node */
	while (*new) {
		struct fixup_set_node *this = container_of(*new, struct fixup_set_node, node);

		parent = *new;
		if (ADDR_KEY(data) < ADDR_KEY(this))
			new = &((*new)->rb_left);
		else if (ADDR_KEY(data) > ADDR_KEY(this))
			new = &((*new)->rb_right);
		else {
			DBG("fixup_set_insert(...): EEXIST\n");
			return EEXIST;
		}
	}

	/* Add new node and rebalance tree. */
	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, &kflat->FLCTRL.fixup_set_root.rb_root);

	DBG("fixup_set_insert(...): 0\n");

	return 0;
}
EXPORT_SYMBOL(fixup_set_insert);

int fixup_set_insert_force_update(struct kflat* kflat, struct flat_node* node, size_t offset, struct flatten_pointer* ptr) {

	struct fixup_set_node* inode;
	struct fixup_set_node *data;
	struct rb_node **new, *parent;

	DBGS("fixup_set_insert_force_update(%lx[%lx:%zu],%zu,%lx)\n",(uintptr_t)node,
			(node)?(node->start):0,(node)?(node->last-node->start+1):0,
			offset,(uintptr_t)ptr);

	if (!ptr) {
		DBG("fixup_set_insert_force_update(...): ptr - EINVAL\n");
		return EINVAL;
	}

	if (node==0) {
		kflat_free(ptr);
		DBG("fixup_set_insert_force_update(...): node - EINVAL\n");
		return EINVAL;
	}

	inode = fixup_set_search(kflat,node->start+offset);

	if (inode && inode->inode) {
		uintptr_t inode_ptr;
		if (((unsigned long)inode->ptr)&1) {
			inode_ptr = ((unsigned long)inode->ptr)&(~1);
		}
		else {
			inode_ptr = inode->ptr->node->start + inode->ptr->offset;
		}
		if (inode_ptr!=ptr->node->start+ptr->offset) {
			flat_errs("fixup_set_insert_force_update(...): multiple pointer mismatch for the same storage [%d]: (%lx vs %lx)\n",
					((unsigned long)inode->ptr)&1,inode_ptr,ptr->node->start+ptr->offset);
		}
		else {
			kflat_free(ptr);
			DBG("fixup_set_insert_force_update(...): node - EEXIST\n");
			return EEXIST;
		}
	}

	if (inode && !inode->inode) {
		return fixup_set_update(kflat,node, offset, ptr);
	}

	data = create_fixup_set_node_element(kflat,node,offset,ptr);
	if (!data) {
		kflat_free(ptr);
		return ENOMEM;
	}
	new = &(kflat->FLCTRL.fixup_set_root.rb_root.rb_node);
	parent = 0;

	/* Figure out where to put new node */
	while (*new) {
		struct fixup_set_node *this = container_of(*new, struct fixup_set_node, node);

		parent = *new;
		if (ADDR_KEY(data) < ADDR_KEY(this))
			new = &((*new)->rb_left);
		else if (ADDR_KEY(data) > ADDR_KEY(this))
			new = &((*new)->rb_right);
		else {
			kflat_free((void*)(((uintptr_t)data->ptr)&(~1)));
			data->ptr = ptr;
			return EAGAIN;
		}
	}

	/* Add new node and rebalance tree. */
	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, &kflat->FLCTRL.fixup_set_root.rb_root);

	DBG("fixup_set_insert_force_update(...): 0\n");

	return 0;
}
EXPORT_SYMBOL(fixup_set_insert_force_update);

int fixup_set_insert_fptr(struct kflat* kflat, struct flat_node* node, size_t offset, unsigned long fptr) {

	struct fixup_set_node* inode;
	struct fixup_set_node *data;
	struct rb_node **new, *parent;

	DBGS("fixup_set_insert_fptr(%lx[%lx:%zu],%zu,%lx)\n",(uintptr_t)node,
			(node)?(node->start):0,(node)?(node->last-node->start+1):0,
			offset,fptr);

	if (!fptr) {
		return EINVAL;
	}

	if (node==0) {
		return EINVAL;
	}

	inode = fixup_set_search(kflat,node->start+offset);

	if (inode && inode->inode) {
		if ((((unsigned long)inode->ptr)&(~1))!=fptr) {
			flat_errs("fixup_set_insert_fptr(...): multiple pointer mismatch for the same storage: (%lx vs %lx)\n",
					(((unsigned long)inode->ptr)&(~1)),fptr);
			return EFAULT;
		}
		return EEXIST;
	}

	if (inode) {
		return fixup_set_update(kflat,node, offset, (struct flatten_pointer*)(fptr|1));
	}

	data = create_fixup_set_node_element(kflat,node,offset,(struct flatten_pointer*)(fptr|1));
	if (!data) {
		return ENOMEM;
	}
	new = &(kflat->FLCTRL.fixup_set_root.rb_root.rb_node);
	parent = 0;

	/* Figure out where to put new node */
	while (*new) {
		struct fixup_set_node *this = container_of(*new, struct fixup_set_node, node);

		parent = *new;
		if (ADDR_KEY(data) < ADDR_KEY(this))
			new = &((*new)->rb_left);
		else if (ADDR_KEY(data) > ADDR_KEY(this))
			new = &((*new)->rb_right);
		else
			return EEXIST;
	}

	/* Add new node and rebalance tree. */
	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, &kflat->FLCTRL.fixup_set_root.rb_root);

	return 0;
}
EXPORT_SYMBOL(fixup_set_insert_fptr);

int fixup_set_insert_fptr_force_update(struct kflat* kflat, struct flat_node* node, size_t offset, unsigned long fptr) {

	struct fixup_set_node* inode;
	struct fixup_set_node *data;
	struct rb_node **new, *parent;

	DBGS("fixup_set_insert_fptr_force_update(%lx[%lx:%zu],%zu,%lx)\n",(uintptr_t)node,
			(node)?(node->start):0,(node)?(node->last-node->start+1):0,
			offset,fptr);

	if (!fptr) {
		return EINVAL;
	}

	if (node==0) {
		return EINVAL;
	}

	inode = fixup_set_search(kflat,node->start+offset);

	if (inode && inode->inode) {
		if ((((unsigned long)inode->ptr)&(~1))!=fptr) {
			flat_errs("fixup_set_insert_fptr_force_update(...): multiple pointer mismatch for the same storage: (%lx vs %lx)\n",
					(((unsigned long)inode->ptr)&(~1)),fptr);
		}
		return EEXIST;
	}

	if (inode && !inode->inode) {
		return fixup_set_update(kflat,node, offset, (struct flatten_pointer*)(fptr|1));
	}

	data = create_fixup_set_node_element(kflat,node,offset,(struct flatten_pointer*)(fptr|1));
	if (!data) {
		return ENOMEM;
	}
	new = &(kflat->FLCTRL.fixup_set_root.rb_root.rb_node);
	parent = 0;

	/* Figure out where to put new node */
	while (*new) {
		struct fixup_set_node *this = container_of(*new, struct fixup_set_node, node);

		parent = *new;
		if (ADDR_KEY(data) < ADDR_KEY(this))
			new = &((*new)->rb_left);
		else if (ADDR_KEY(data) > ADDR_KEY(this))
			new = &((*new)->rb_right);
		else {
			kflat_free((void*)(((uintptr_t)data->ptr)&(~1)));
			data->ptr = (struct flatten_pointer*)(fptr|1);
			return EAGAIN;
		}
	}

	/* Add new node and rebalance tree. */
	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, &kflat->FLCTRL.fixup_set_root.rb_root);

	return 0;
}
EXPORT_SYMBOL(fixup_set_insert_fptr_force_update);

void fixup_set_print(struct kflat* kflat) {
	struct rb_node * p = rb_first(&kflat->FLCTRL.fixup_set_root.rb_root);
	flat_info("[\n");
	while(p) {
    	struct fixup_set_node* node = (struct fixup_set_node*)p;
    	if (node->ptr) {
			if (((unsigned long)node->ptr)&1) {
				uintptr_t newptr = ((unsigned long)node->ptr)&(~1);
				uintptr_t origptr = node->inode->storage->index+node->offset;
				flat_infos(" %zu: (%lx:%zu)->(F) | %zu <- %zu\n",
					node->inode->storage->index,
					(unsigned long)node->inode,node->offset,
					origptr,newptr);
			}
			else {
				uintptr_t newptr = node->ptr->node->storage->index+node->ptr->offset;
				uintptr_t origptr = node->inode->storage->index+node->offset;
				flat_infos(" %zu: (%lx:%zu)->(%lx:%zu) | %zu <- %zu\n",
						node->inode->storage->index,
						(unsigned long)node->inode,node->offset,
						(unsigned long)node->ptr->node,node->ptr->offset,
						origptr,newptr);
			}
    	}
    	else if (node->inode) {
    		/* Reserved node but never filled */
    		uintptr_t origptr = node->inode->storage->index+node->offset;
    		flat_infos(" %zu: (%lx:%zu)-> 0 | %zu\n",
					node->inode->storage->index,
					(unsigned long)node->inode,node->offset,
					origptr);
    	}
    	else {
    		/* Reserved for dummy pointer */
    		flat_infos(" (%lx)-> 0 | \n",(unsigned long)node->offset);
    	}
    	p = rb_next(p);
    }
	flat_info("]\n");
}

int fixup_set_write(struct kflat* kflat, size_t* wcounter_p) {
	struct rb_node * p = rb_first(&kflat->FLCTRL.fixup_set_root.rb_root);
	while(p) {
    	struct fixup_set_node* node = (struct fixup_set_node*)p;
    	if ((node->ptr)&&(!(((unsigned long)node->ptr)&1))) {
			size_t origptr = node->inode->storage->index+node->offset;
			FLATTEN_WRITE_ONCE(&origptr,sizeof(size_t),wcounter_p);
    	}
    	p = rb_next(p);
    }
    return 0;
}

int fixup_set_fptr_write(struct kflat* kflat, size_t* wcounter_p) {
	struct rb_node * p = rb_first(&kflat->FLCTRL.fixup_set_root.rb_root);
	while(p) {
    	struct fixup_set_node* node = (struct fixup_set_node*)p;
    	if ((((unsigned long)node->ptr)&1)) {
			size_t origptr = node->inode->storage->index+node->offset;
			FLATTEN_WRITE_ONCE(&origptr,sizeof(size_t),wcounter_p);
    	}
    	p = rb_next(p);
    }
    return 0;
}

size_t mem_fragment_index_count(struct kflat* kflat) {

	struct rb_node * p = rb_first(&kflat->FLCTRL.imap_root.rb_root);
	size_t mcount = 0;
	while(p) {
		struct flat_node* node = (struct flat_node*)p;
		p = rb_next(p);
		if ((!p)||(node->last+1!=((struct flat_node*)p)->start)) {
			mcount++;
		}
	};

	return mcount;
}

int mem_fragment_index_write(struct kflat* kflat, size_t* wcounter_p) {

	struct rb_node * p = rb_first(&kflat->FLCTRL.imap_root.rb_root);
	size_t index = 0;
	size_t fragment_size = 0;
	size_t mcount = 0;
	while(p) {
		struct flat_node* node = (struct flat_node*)p;
		fragment_size += node->storage->size;
		p = rb_next(p);
		if ((!p)||(node->last+1!=((struct flat_node*)p)->start)) {
			if (p) {
				size_t nindex = ((struct flat_node*)p)->storage->index;
				size_t wrnfo;
				FLATTEN_WRITE_ONCE(&index,sizeof(size_t),wcounter_p);
				wrnfo = nindex-index;
				FLATTEN_WRITE_ONCE(&wrnfo,sizeof(size_t),wcounter_p);
				index = nindex;
			}
			else {
				FLATTEN_WRITE_ONCE(&index,sizeof(size_t),wcounter_p);
				FLATTEN_WRITE_ONCE(&fragment_size,sizeof(size_t),wcounter_p);
			}
			fragment_size = 0;
			mcount++;
		}
	};

	return 0;
}

int mem_fragment_index_debug_print(struct kflat* kflat) {

	struct rb_node * p = rb_first(&kflat->FLCTRL.imap_root.rb_root);
	size_t index = 0;
	size_t fragment_size = 0;
	size_t mcount = 0;
	while(p) {
		struct flat_node* node = (struct flat_node*)p;
		fragment_size += node->storage->size;
		p = rb_next(p);
		if ((!p)||(node->last+1!=((struct flat_node*)p)->start)) {
			if (p) {
				size_t nindex = ((struct flat_node*)p)->storage->index;
				flat_infos("MEM: %08zu [%zu]\n",index,nindex-index);
				index = nindex;
			}
			else {
				flat_infos("MEM: %08zu [%zu]\n",index,fragment_size);
			}
			fragment_size = 0;
			mcount++;
		}
	};

	return 0;
}

size_t fixup_set_count(struct kflat* kflat) {
	struct rb_node * p = rb_first(&kflat->FLCTRL.fixup_set_root.rb_root);
	size_t count=0;
	while(p) {
		struct fixup_set_node* node = (struct fixup_set_node*)p;
		if ((node->ptr)&&(!(((unsigned long)node->ptr)&1))) {
			count++;
		}
    	p = rb_next(p);
    }
    return count;
}

size_t fixup_set_fptr_count(struct kflat* kflat) {
	struct rb_node * p = rb_first(&kflat->FLCTRL.fixup_set_root.rb_root);
	size_t count=0;
	while(p) {
		struct fixup_set_node* node = (struct fixup_set_node*)p;
		if ((((unsigned long)node->ptr)&1)) {
			count++;
		}
    	p = rb_next(p);
    }
    return count;
}

void fixup_set_destroy(struct kflat* kflat) {
	struct rb_node * p = rb_first(&kflat->FLCTRL.fixup_set_root.rb_root);
	while(p) {
		struct fixup_set_node* node = (struct fixup_set_node*)p;
		rb_erase(p, &kflat->FLCTRL.fixup_set_root.rb_root);
		p = rb_next(p);
		if (!(((unsigned long)node->ptr)&1)) {
			kflat_free(node->ptr);
		}
		kflat_free(node);
	};
}

int root_addr_append(struct kflat* kflat, uintptr_t root_addr) {
    struct root_addrnode* v = kflat_zalloc(kflat,sizeof(struct root_addrnode),1);
    if (!v) {
    	return ENOMEM;
    }
    v->root_addr = root_addr;
    if (!kflat->FLCTRL.rhead) {
    	kflat->FLCTRL.rhead = v;
    	kflat->FLCTRL.rtail = v;
    }
    else {
    	kflat->FLCTRL.rtail->next = v;
    	kflat->FLCTRL.rtail = kflat->FLCTRL.rtail->next;
    }
    kflat->FLCTRL.root_addr_count++;
    return 0;
}
EXPORT_SYMBOL(root_addr_append);

int root_addr_append_extended(struct kflat* kflat, size_t root_addr, const char* name, size_t size) {

	struct root_addr_set_node* root_addr_node = root_addr_set_search(kflat, name);
	struct root_addrnode* v;

	if (root_addr_node) {
		return EEXIST;
	}

	v = kflat_zalloc(kflat,sizeof(struct root_addrnode),1);
    if (!v) {
    	return ENOMEM;
    }
    v->root_addr = root_addr;
    v->name = name;
    v->index = kflat->FLCTRL.root_addr_count;
    v->size = size;
    if (!kflat->FLCTRL.rhead) {
    	kflat->FLCTRL.rhead = v;
    	kflat->FLCTRL.rtail = v;
    }
    else {
    	kflat->FLCTRL.rtail->next = v;
    	kflat->FLCTRL.rtail = kflat->FLCTRL.rtail->next;
    }
    kflat->FLCTRL.root_addr_count++;
    root_addr_set_insert(kflat, name, root_addr);
    return 0;
}
EXPORT_SYMBOL(root_addr_append_extended);

size_t root_addr_count(struct kflat* kflat) {
	struct root_addrnode* p = kflat->FLCTRL.rhead;
	size_t count = 0;
    while(p) {
    	count++;
    	p = p->next;
    }
    return count;
}

size_t root_addr_extended_count(struct kflat* kflat) {
	struct root_addrnode* p = kflat->FLCTRL.rhead;
	size_t count = 0;
    while(p) {
    	if (p->name) {
    		count++;
    	}
    	p = p->next;
    }
    return count;
}

size_t root_addr_extended_size(struct kflat* kflat) {
	struct root_addrnode* p = kflat->FLCTRL.rhead;
	size_t size = 0;
    while(p) {
    	if (p->name) {
    		size+=3*sizeof(size_t)+strlen(p->name);
    	}
    	p = p->next;
    }
    return size;
}

struct root_addr_set_node* root_addr_set_search(struct kflat* kflat, const char* name) {

	struct rb_node *node = kflat->root_addr_set.rb_node;

	while (node) {
		struct root_addr_set_node* data = container_of(node, struct root_addr_set_node, node);

		if (strcmp(name,data->name)<0) {
			node = node->rb_left;
		}
		else if (strcmp(name,data->name)>0) {
			node = node->rb_right;
		}
		else
			return data;
	}

	return 0;
}
EXPORT_SYMBOL(root_addr_set_search);

int root_addr_set_insert(struct kflat* kflat, const char* name, uintptr_t v) {

	struct root_addr_set_node* data = libflat_zalloc(1,sizeof(struct root_addr_set_node));
	struct rb_node **new, *parent = 0;
	data->name = libflat_zalloc(1,strlen(name)+1);
	strcpy(data->name,name);
	data->root_addr = v;
	new = &(kflat->root_addr_set.rb_node);

	/* Figure out where to put new node */
	while (*new) {
		struct root_addr_set_node* this = container_of(*new, struct root_addr_set_node, node);

		parent = *new;
		if (strcmp(data->name,this->name)<0)
			new = &((*new)->rb_left);
		else if (strcmp(data->name,this->name)>0)
			new = &((*new)->rb_right);
		else {
			libflat_free((void*)data->name);
		    libflat_free(data);
		    return 0;
		}
	}

	/* Add new node and rebalance tree. */
	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, &kflat->root_addr_set);

	return 1;
}
EXPORT_SYMBOL(root_addr_set_insert);

int root_addr_set_delete(struct kflat* kflat, const char* name) {

	struct root_addr_set_node* node = root_addr_set_search(kflat,name);
	if (node) {
		rb_erase(&node->node, &kflat->root_addr_set);
		return 1;
	}
	return 0;
}
EXPORT_SYMBOL(root_addr_set_delete);

void root_addr_set_destroy(struct kflat* kflat) {

	struct rb_root* root = &kflat->root_addr_set;
	struct rb_node * p = rb_first(root);
    while(p) {
        struct root_addr_set_node* data = (struct root_addr_set_node*)p;
        rb_erase(p, root);
        p = rb_next(p);
        libflat_free((void*)data->name);
        libflat_free(data);
    }
}
EXPORT_SYMBOL(root_addr_set_destroy);

size_t root_addr_set_count(struct kflat* kflat) {

	struct rb_root* root = &kflat->root_addr_set;
	struct rb_node * p = rb_first(root);
	size_t count = 0;
	while(p) {
		count++;
		p = rb_next(p);
	}
	return count;
}
EXPORT_SYMBOL(root_addr_set_count);

void interval_tree_print(struct rb_root *root) {
	struct rb_node * p = rb_first(root);
	size_t total_size=0;
	while(p) {
		struct flat_node* node = (struct flat_node*)p;
		flat_infos("(%lx)[%lx:%lx](%zu){%lx}\n",(unsigned long)node,(unsigned long)node->start,(unsigned long)node->last,
				node->last-node->start+1,(unsigned long)node->storage);
		total_size+=node->last-node->start+1;
		p = rb_next(p);
	};
	flat_infos("@ Total size: %zu\n",total_size);
}

int interval_tree_destroy(struct kflat* kflat, struct rb_root *root) {
	struct interval_nodelist *h = 0, *i = 0;
	struct rb_node * p = rb_first(root);
	int rv = 0;
	while(p) {
		struct flat_node* node = (struct flat_node*)p;
		struct interval_nodelist* v;
		v = kflat_zalloc(kflat,sizeof(struct interval_nodelist),1);
		if (!v) {
			rv = ENOMEM;
			break;
		}
		interval_tree_remove(node,&kflat->FLCTRL.imap_root);
	    v->node = node;
	    if (!h) {
	        h = v;
	        i = v;
	    }
	    else {
	        i->next = v;
	        i = i->next;
	    }
		p = rb_next(p);
	};
	while(h) {
    	struct interval_nodelist* p = h;
    	h = h->next;
    	kflat_free(p->node);
    	kflat_free(p);
    }
	return rv;
}

struct flatten_pointer* flatten_plain_type(struct kflat* kflat, const void* _ptr, size_t _sz) {

	struct flat_node *node;
	struct flatten_pointer* r = 0;
	if (!_sz) {
		return 0;
	}
	node = interval_tree_iter_first(&kflat->FLCTRL.imap_root, (uintptr_t)_ptr, (uintptr_t)_ptr+_sz-1);
	if (node) {
		uintptr_t p = (uintptr_t)_ptr;
		struct flat_node *prev;
		while(node) {
			if (node->start>p) {
				struct flat_node* nn;
				if (!node->storage) {
					flat_err("flat_node missing storage");
					return 0;
				}
				nn = kflat_zalloc(kflat,sizeof(struct flat_node),1);
				if (nn==0) return 0;
				nn->start = p;
				nn->last = node->start-1;
				nn->storage = binary_stream_insert_front(kflat,(void*)p,node->start-p,node->storage);
				if (!nn->storage) {
					kflat_free(nn);
					return 0;
				}
				interval_tree_insert(nn, &kflat->FLCTRL.imap_root);
				if (r==0) {
					r = make_flatten_pointer(kflat,nn,0);
					if (!r) {
						return 0;
					}
				}
			}
			else {
				if (r==0) {
					r = make_flatten_pointer(kflat,node,p-node->start);
					if (!r) {
						return 0;
					}
				}
			}
			p = node->last+1;
			prev = node;
			node = interval_tree_iter_next(node, (uintptr_t)_ptr, (uintptr_t)_ptr+_sz-1);
		}
		if ((uintptr_t)_ptr+_sz>p) {
			struct flat_node* nn;
			if (!prev->storage) {
				kflat_free(r);
				return 0;
			}
			nn = kflat_zalloc(kflat,sizeof(struct flat_node),1);
			if (!nn) {
				kflat_free(r);
				return 0;
			}
			nn->start = p;
			nn->last = (uintptr_t)_ptr+_sz-1;
			nn->storage = binary_stream_insert_back(kflat,(void*)p,(uintptr_t)_ptr+_sz-p,prev->storage);
			if (!nn->storage) {
				kflat_free(nn);
				kflat_free(r);
				return 0;
			}
			interval_tree_insert(nn, &kflat->FLCTRL.imap_root);
		}
		return r;
	}
	else {
		struct blstream* storage;
		struct rb_node* rb;
		struct rb_node* prev;
		node = kflat_zalloc(kflat,sizeof(struct flat_node),1);
		if (!node) {
			return 0;
		}
		node->start = (uintptr_t)_ptr;
		node->last = (uintptr_t)_ptr + _sz-1;
		interval_tree_insert(node, &kflat->FLCTRL.imap_root);
		rb = &node->rb;
		prev = rb_prev(rb);
		if (prev) {
			storage = binary_stream_insert_back(kflat,_ptr,_sz,((struct flat_node*)prev)->storage);
		}
		else {
			struct rb_node* next = rb_next(rb);
			if (next) {
				storage = binary_stream_insert_front(kflat,_ptr,_sz,((struct flat_node*)next)->storage);
			}
			else {
				storage = binary_stream_append(kflat,_ptr,_sz);
			}
		}
		if (!storage) {
			return 0;
		}
		node->storage = storage;
		r = make_flatten_pointer(kflat,node,0);
		if (!r) {
			return 0;
		}
		return r;
	}
}
EXPORT_SYMBOL(flatten_plain_type);

int kflat_linear_memory_realloc(struct kflat* kflat, size_t nsize) {
	void* nmem = 0;
	if (nsize==kflat->msize) return 0;
	if (kflat->mptrindex>0) return EFAULT;
	if (kflat->bqueue_mptrindex>0) return EFAULT;
	nmem = kvzalloc(nsize,GFP_KERNEL);
	if (!nmem) {
		flat_errs("Failed to reallocate kflat memory pool for new size %zu\n",nsize);
		return ENOMEM;
	}
	kflat->msize = nsize;
	kvfree(kflat->mpool);
	kflat->mpool = nmem;
	nmem = kvzalloc(nsize,GFP_KERNEL);
	if (!nmem) {
		flat_errs("Failed to reallocate kflat bqueue memory pool for new size %zu\n",nsize);
		return ENOMEM;
	}
	kflat->bqueue_msize = nsize;
	kvfree(kflat->bqueue_mpool);
	kflat->bqueue_mpool = nmem;
	return 0;
}

void flatten_init(struct kflat* kflat) {
	memset(&kflat->FLCTRL,0,sizeof(struct FLCONTROL));
	kflat->FLCTRL.fixup_set_root = RB_ROOT_CACHED;
	kflat->FLCTRL.imap_root = RB_ROOT_CACHED;
	kflat->root_addr_set.rb_node = 0;
	kflat->mptrindex = 0;
	kflat->msize = 0;
	kflat->bqueue_mptrindex = 0;
	kflat->bqueue_msize = 0;
#if LINEAR_MEMORY_ALLOCATOR>0
	kflat->msize = KFLAT_LINEAR_MEMORY_INITIAL_POOL_SIZE;
	kflat->mpool = kvzalloc(KFLAT_LINEAR_MEMORY_INITIAL_POOL_SIZE,GFP_KERNEL);
	if (!kflat->mpool) {
		flat_errs("Failed to allocate initial kflat memory pool of size %zu\n",KFLAT_LINEAR_MEMORY_INITIAL_POOL_SIZE);
		kflat->errno = ENOMEM;
	}
	kflat->bqueue_msize = KFLAT_LINEAR_MEMORY_INITIAL_POOL_SIZE;
	kflat->bqueue_mpool = kvzalloc(KFLAT_LINEAR_MEMORY_INITIAL_POOL_SIZE,GFP_KERNEL);
	if (!kflat->bqueue_mpool) {
		flat_errs("Failed to allocate initial kflat bqueue memory pool of size %zu\n",KFLAT_LINEAR_MEMORY_INITIAL_POOL_SIZE);
		kflat->errno = ENOMEM;
	}
#else
	kflat->mpool = 0;
	kflat->bqueue_mpool = 0;
#endif
}

void flatten_debug_info(struct kflat* kflat) {
	binary_stream_print(kflat);
    interval_tree_print(&kflat->FLCTRL.imap_root.rb_root);
    fixup_set_print(kflat);
    mem_fragment_index_debug_print(kflat);
}

int flatten_write(struct kflat* kflat) {

	size_t written = sizeof(size_t);
	int err;

	if ((err=flatten_write_internal(kflat,&written))==0) {
		flat_infos("OK. Flatten size: %lu, %lu pointers, %zu root pointers, %lu function pointers, %lu continuous memory fragments, "
				"%zu bytes written, memory used: %zu, memory avail: %zu\n",
			kflat->FLCTRL.HDR.memory_size,kflat->FLCTRL.HDR.ptr_count,kflat->FLCTRL.HDR.root_addr_count,kflat->FLCTRL.HDR.fptr_count,
			kflat->FLCTRL.HDR.mcount,written-sizeof(size_t),kflat->mptrindex,kflat->msize);
	}
	else {
		flat_errs("ERROR %d: Could not write flatten image. Flatten size: %lu, %lu pointers, %zu root pointers, %lu function pointers,"
				"%lu continuous memory fragments, %zu bytes written\n",kflat->errno,kflat->FLCTRL.HDR.memory_size,
				kflat->FLCTRL.HDR.ptr_count,kflat->FLCTRL.HDR.root_addr_count,kflat->FLCTRL.HDR.fptr_count,kflat->FLCTRL.HDR.mcount,written-sizeof(size_t));
	}

	*((size_t*)(kflat->area)) = written-sizeof(size_t);

	return err;
}

volatile int vi;
int flatten_base_function_address(void) {
	return vi;
}
EXPORT_SYMBOL(flatten_base_function_address);

int flatten_base_global_address;
EXPORT_SYMBOL(flatten_base_global_address);

int flatten_write_internal(struct kflat* kflat, size_t* wcounter_p) {

	int err = 0;
	struct root_addrnode* p;
	binary_stream_calculate_index(kflat);
    binary_stream_update_pointers(kflat);
    if (kflat->FLCTRL.debug_flag) {
    	flatten_debug_info(kflat);
    }
    kflat->FLCTRL.HDR.memory_size = binary_stream_size(kflat);
    kflat->FLCTRL.HDR.ptr_count = fixup_set_count(kflat);
    kflat->FLCTRL.HDR.fptr_count = fixup_set_fptr_count(kflat);
    kflat->FLCTRL.HDR.root_addr_count = root_addr_count(kflat);
    kflat->FLCTRL.HDR.root_addr_extended_count = root_addr_extended_count(kflat);
    kflat->FLCTRL.HDR.root_addr_extended_size = root_addr_extended_size(kflat);
    kflat->FLCTRL.HDR.this_addr = (uintptr_t)&flatten_base_function_address;
    kflat->FLCTRL.HDR.mcount = mem_fragment_index_count(kflat);
    kflat->FLCTRL.HDR.magic = FLATTEN_MAGIC;
    FLATTEN_WRITE_ONCE(&kflat->FLCTRL.HDR,sizeof(struct flatten_header),wcounter_p);
    p = kflat->FLCTRL.rhead;
	while(p) {
		size_t root_addr_offset;
		if (p->root_addr) {
			struct flat_node *node = PTRNODE(p->root_addr);
			root_addr_offset = node->storage->index + (p->root_addr-node->start);
		}
		else {
			root_addr_offset = (size_t)-1;
		}
		FLATTEN_WRITE_ONCE(&root_addr_offset,sizeof(size_t),wcounter_p);
		p = p->next;
	}
	p = kflat->FLCTRL.rhead;
	while(p) {
		if (p->name) {
			size_t name_size = strlen(p->name);
			FLATTEN_WRITE_ONCE(&name_size,sizeof(size_t),wcounter_p);
			FLATTEN_WRITE_ONCE(p->name,name_size,wcounter_p);
			FLATTEN_WRITE_ONCE(&p->index,sizeof(size_t),wcounter_p);
			FLATTEN_WRITE_ONCE(&p->size,sizeof(size_t),wcounter_p);
		}
		p = p->next;
	}
	if ((err = fixup_set_write(kflat,wcounter_p))!=0) {
		return err;
	}
	if ((err = fixup_set_fptr_write(kflat,wcounter_p))!=0) {
		return err;
	}
	if ((err = mem_fragment_index_write(kflat,wcounter_p))!=0) {
		return err;
	}
	if ((err = binary_stream_write(kflat,wcounter_p))!=0) {
		return err;
	}
    return 0;
}

int flatten_fini(struct kflat* kflat) {
	binary_stream_destroy(kflat);
    fixup_set_destroy(kflat);
    kflat->FLCTRL.rtail = kflat->FLCTRL.rhead;
    while(kflat->FLCTRL.rtail) {
    	struct root_addrnode* p = kflat->FLCTRL.rtail;
    	kflat->FLCTRL.rtail = kflat->FLCTRL.rtail->next;
    	kflat_free(p);
    }
    interval_tree_destroy(kflat,&kflat->FLCTRL.imap_root.rb_root);
#if LINEAR_MEMORY_ALLOCATOR
    kvfree(kflat->mpool);
    kflat->mptrindex = 0;
    kflat->msize = 0;
    kvfree(kflat->bqueue_mpool);
    kflat->bqueue_mptrindex = 0;
    kflat->bqueue_msize = 0;
#endif
    root_addr_set_destroy(kflat);
    return 0;
}

void flatten_set_debug_flag(struct kflat* kflat, int flag) {
	kflat->FLCTRL.debug_flag = flag;
}

void flatten_set_option(struct kflat* kflat, int option) {
	kflat->FLCTRL.option |= option;
}
EXPORT_SYMBOL(flatten_set_option);

void flatten_clear_option(struct kflat* kflat, int option) {
	kflat->FLCTRL.option &= ~option;
}
EXPORT_SYMBOL(flatten_clear_option);

int kflat_in_progress() {
	struct kflat* kflat = get_current()->kflat;
	if ((kflat_g_p && (kflat_g_p->FLCTRL.option & KFLAT_OPTION_IN_PROGRESS)) ||
			(kflat && (kflat->FLCTRL.option & KFLAT_OPTION_IN_PROGRESS))) {
		return 1;
	}
	return 0;
}
EXPORT_SYMBOL(kflat_in_progress);

void flatten_debug_memory() {
#if 0
	unsigned char* m = FLATTEN_MEMORY_START;
	printf("(%p)\n",m);
	printf("[ ");
	for (;m<FLATTEN_MEMORY_END;) {
		printf("%02x ",*m);
		++m;
		if ((m-FLATTEN_MEMORY_START)%32==0)
			printf("\n  ");
	}
	printf("]\n");
#endif
}

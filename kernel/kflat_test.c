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

struct string_node {
	struct rb_node node;
	char* s;
};

void flatten_set_debug_flag(struct kflat* kflat, int flag);

static struct rb_root stringset_root = RB_ROOT;

static struct string_node* stringset_search(const char* s) {

	struct rb_node *node = stringset_root.rb_node;

	while (node) {
		struct string_node* data = container_of(node, struct string_node, node);

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

static int stringset_insert(const char* s) {

	struct string_node* data = libflat_zalloc(1,sizeof(struct string_node));
	struct rb_node **new, *parent = 0;
	data->s = libflat_zalloc(1,strlen(s)+1);
	strcpy(data->s,s);
	new = &(stringset_root.rb_node);

	/* Figure out where to put new node */
	while (*new) {
		struct string_node* this = container_of(*new, struct string_node, node);

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
	rb_insert_color(&data->node, &stringset_root);

	return 1;
}

static void stringset_destroy(struct rb_root* root) {

    struct rb_node * p = rb_first(root);
    while(p) {
        struct string_node* data = (struct string_node*)p;
        rb_erase(p, root);
        p = rb_next(p);
        libflat_free((void*)data->s);
        libflat_free(data);
    }
}

static size_t stringset_count(const struct rb_root* root) {

	struct rb_node * p = rb_first(root);
	size_t count = 0;
	while(p) {
		count++;
		p = rb_next(p);
	}
	return count;
}

struct B {
	unsigned char T[4];
};

struct A {
	unsigned long X;
	struct B* pB;
};

FUNCTION_DEFINE_FLATTEN_STRUCT(B,
);

FUNCTION_DEFINE_FLATTEN_STRUCT(A,
    AGGREGATE_FLATTEN_STRUCT(B,pB);
);

static int kflat_simple_test(struct kflat *kflat, int debug_flag) {

	struct B b = { "ABC" };
	struct A a = { 0x0000404F, &b };
	struct A* pA = &a;
	int err = 0;

	flatten_init(kflat);
	flatten_set_debug_flag(kflat,debug_flag);

	FOR_ROOT_POINTER(pA,
		FLATTEN_STRUCT(A, pA);
	);

	flat_infos("@Flatten done: %d\n",kflat->errno);
	if (!kflat->errno) {
		err = flatten_write(kflat);
	}
	flatten_fini(kflat);

	return err;

}

struct point {
    double x;
    double y;
    unsigned n;
    struct point** other;
};

struct figure {
    const char* name;
    unsigned n;
    struct point* points;
};


FUNCTION_DECLARE_FLATTEN_STRUCT(point);
FUNCTION_DECLARE_FLATTEN_STRUCT(figure);
FUNCTION_DECLARE_FLATTEN_STRUCT_ITER(point);
FUNCTION_DECLARE_FLATTEN_STRUCT_ITER(figure);

FUNCTION_DEFINE_FLATTEN_STRUCT(point,
    AGGREGATE_FLATTEN_TYPE_ARRAY(struct point*, other, ATTR(n));
    FOREACH_POINTER(struct point*, p, ATTR(other), ATTR(n),
            FLATTEN_STRUCT(point, p);
    );
);

FUNCTION_DEFINE_FLATTEN_STRUCT_ITER(point,
    AGGREGATE_FLATTEN_TYPE_ARRAY(struct point*, other, ATTR(n));
    FOREACH_POINTER(struct point*, p, ATTR(other), ATTR(n),
            FLATTEN_STRUCT_ITER(point, p);
    );
);

FUNCTION_DEFINE_FLATTEN_STRUCT(figure,
    AGGREGATE_FLATTEN_STRING(name);
    AGGREGATE_FLATTEN_STRUCT_ARRAY(point,points,ATTR(n));
);

FUNCTION_DEFINE_FLATTEN_STRUCT_ITER(figure,
    AGGREGATE_FLATTEN_STRING(name);
    AGGREGATE_FLATTEN_STRUCT_ARRAY_ITER(point,points,ATTR(n));
);

#define MAKE_POINT(p, i, N)   \
    p.x = (cosx[i]);	\
    p.y = (sinx[i]);	\
    p.n = (N);  \
    p.other = kvzalloc((N)*sizeof*p.other,GFP_KERNEL);


static int kflat_circle_test(struct kflat *kflat, size_t num_points, int debug_flag, double* cosx, double* sinx) {

	struct figure circle = { "circle",num_points };
	unsigned i, j;
	int err = 0;

	flatten_init(kflat);
	flatten_set_debug_flag(kflat,debug_flag);
	
	circle.points = kvzalloc(circle.n*sizeof(struct point),GFP_KERNEL);
	for (i = 0; i < circle.n; ++i) {
		MAKE_POINT(circle.points[i], i, circle.n - 1);
	}
	for (i = 0; i < circle.n; ++i) {
		unsigned u = 0;
		for (j = 0; j < circle.n; ++j) {
			if (i == j)
				continue;
			circle.points[i].other[u++] = &circle.points[j];
		}
	}

	FOR_ROOT_POINTER(&circle,
		FLATTEN_STRUCT(figure, &circle);
	);

	for (i = 0; i < circle.n; ++i) {
		kvfree(circle.points[i].other);
	}
	kvfree(circle.points);

	flat_infos("@Flatten done: %d\n",kflat->errno);
	if (!kflat->errno) {
		err = flatten_write(kflat);
	}
	flatten_fini(kflat);

	return err;

}

static int kflat_circle_test_iter(struct kflat *kflat, size_t num_points, int debug_flag, double* cosx, double* sinx) {

	struct figure circle = { "circle",num_points };
	unsigned i, j;
	int err = 0;

	flatten_init(kflat);
	flatten_set_debug_flag(kflat,debug_flag);

	circle.points = kvzalloc(circle.n*sizeof(struct point),GFP_KERNEL);
    for (i = 0; i < circle.n; ++i) {
        MAKE_POINT(circle.points[i], i, circle.n - 1);
    }
    for (i = 0; i < circle.n; ++i) {
		unsigned u = 0;
		for (j = 0; j < circle.n; ++j) {
			if (i == j)
				continue;
			circle.points[i].other[u++] = &circle.points[j];
		}
	}

	FOR_ROOT_POINTER(&circle,
		UNDER_ITER_HARNESS(
			FLATTEN_STRUCT_ITER(figure, &circle);
		);
	);

	for (i = 0; i < circle.n; ++i) {
		kvfree(circle.points[i].other);
	}
	kvfree(circle.points);

	flat_infos("@Flatten done: %d\n",kflat->errno);
	if (!kflat->errno) {
		err = flatten_write(kflat);
	}
	flatten_fini(kflat);

	return err;

}

static int kflat_pointer_test(struct kflat *kflat, int debug_flag) {

	double magic_number = 3.14159265359;
	double* pointer_to_it = &magic_number;
	double** pointer_to_pointer_to_it = &pointer_to_it;
	double*** ehhh = &pointer_to_pointer_to_it;
	int err = 0;

	flatten_init(kflat);
	flatten_set_debug_flag(kflat,debug_flag);

	FOR_ROOT_POINTER(ehhh,
		FLATTEN_TYPE_ARRAY(double**, &pointer_to_pointer_to_it, 1);
		FOREACH_POINTER(double**,p, &pointer_to_pointer_to_it, 1,
			FLATTEN_TYPE_ARRAY(double*, p, 1);
			FOREACH_POINTER(double*, q, p, 1,
				FLATTEN_TYPE_ARRAY(double, q, 1);
			);
		);
	);

	flat_infos("@Flatten done: %d\n",kflat->errno);
	if (!kflat->errno) {
		err = flatten_write(kflat);
	}
	flatten_fini(kflat);

	return err;

}

FUNCTION_DEFINE_FLATTEN_STRUCT_ITER(task_struct,
);

static int kflat_currenttask_test(struct kflat *kflat, int debug_flag) {

	int err = 0;

	flatten_init(kflat);
	flatten_set_debug_flag(kflat,debug_flag);

	struct task_struct* t = current;

	FOR_ROOT_POINTER(t,
		UNDER_ITER_HARNESS(
			FLATTEN_STRUCT_ITER(task_struct, t);
		);
	);

	flat_infos("@Flatten done: %d\n",kflat->errno);
	if (!kflat->errno) {
		err = flatten_write(kflat);
	}
	flatten_fini(kflat);

	return err;

}

static inline const struct string_node* ptr_remove_color(const struct string_node* ptr) {
	return (const struct string_node*)( (uintptr_t)ptr & ~3 );
}

static inline struct flatten_pointer* fptr_add_color(struct flatten_pointer* fptr, const struct string_node* ptr) {
	fptr->offset |= (size_t)((uintptr_t)ptr & 3);
	return fptr;
}

FUNCTION_DECLARE_FLATTEN_STRUCT(string_node);
FUNCTION_DECLARE_FLATTEN_STRUCT_ITER(string_node);

FUNCTION_DEFINE_FLATTEN_STRUCT(string_node,
	STRUCT_ALIGN(4);
	AGGREGATE_FLATTEN_STRUCT_MIXED_POINTER(string_node,node.__rb_parent_color,ptr_remove_color,fptr_add_color);
	AGGREGATE_FLATTEN_STRUCT(string_node,node.rb_right);
	AGGREGATE_FLATTEN_STRUCT(string_node,node.rb_left);
	AGGREGATE_FLATTEN_STRING(s);
);

FUNCTION_DEFINE_FLATTEN_STRUCT_ITER(string_node,
	STRUCT_ALIGN(4);
	AGGREGATE_FLATTEN_STRUCT_MIXED_POINTER_ITER(string_node,node.__rb_parent_color,ptr_remove_color,fptr_add_color);
	AGGREGATE_FLATTEN_STRUCT_ITER(string_node,node.rb_right);
	AGGREGATE_FLATTEN_STRUCT_ITER(string_node,node.rb_left);
	AGGREGATE_FLATTEN_STRING(s);
);

FUNCTION_DEFINE_FLATTEN_STRUCT(rb_root,
	AGGREGATE_FLATTEN_STRUCT(string_node,rb_node);
);

FUNCTION_DEFINE_FLATTEN_STRUCT_ITER(rb_root,
	AGGREGATE_FLATTEN_STRUCT_ITER(string_node,rb_node);
);

static int kflat_stringset_test(struct kflat *kflat, size_t num_strings, int debug_flag) {

	static const char chars[] = "ABCDEFGHIJ";
	unsigned i,j;
	int err = 0;

	for (j=0; j<num_strings; ++j) {
		char* s = libflat_zalloc(1,sizeof chars);
		for (i=0; i<sizeof chars - 1; ++i) {
			unsigned char u;
			get_random_bytes(&u,1);
			s[i] = chars[u%(sizeof chars - 1)];
		}
		stringset_insert(s);
		libflat_free(s);
	}

	flat_infos("@String set size: %zu\n",stringset_count(&stringset_root));

	flatten_init(kflat);
	flatten_set_debug_flag(kflat,debug_flag);

	FOR_ROOT_POINTER(&stringset_root,
		FLATTEN_STRUCT(rb_root,&stringset_root);
	);

	flat_infos("@Flatten done: %d\n",kflat->errno);
	if (!kflat->errno) {
		err = flatten_write(kflat);
	}
	flatten_fini(kflat);

	return err;
}

static int kflat_stringset_test_iter(struct kflat *kflat, size_t num_strings, int debug_flag) {

	static const char chars[] = "ABCDEFGHIJ";
	unsigned i,j;
	int err = 0;

	for (j=0; j<num_strings; ++j) {
		char* s = libflat_zalloc(1,sizeof chars);
		for (i=0; i<sizeof chars - 1; ++i) {
			unsigned char u;
			get_random_bytes(&u,1);
			s[i] = chars[u%(sizeof chars - 1)];
		}
		stringset_insert(s);
		libflat_free(s);
	}

	flat_infos("@String set size: %zu\n",stringset_count(&stringset_root));

	flatten_init(kflat);
	flatten_set_debug_flag(kflat,debug_flag);

	FOR_ROOT_POINTER(&stringset_root,
		UNDER_ITER_HARNESS(
			FLATTEN_STRUCT_ITER(rb_root,&stringset_root);
		);
	);

	flat_infos("@Flatten done: %d\n",kflat->errno);
	if (!kflat->errno) {
		err = flatten_write(kflat);
	}
	flatten_fini(kflat);

	return err;
}

enum KFLAT_TEST_CASE {
	DEBUG_FLAG=1,
	TEST_ITER=2,
	CIRCLE=1<<2,
	STRINGSET=2<<2,
	POINTER=3<<2,
	CURRENTTASK=4<<2,
	SIMPLE=5<<2,
};

#include "kflat_test_data.h"

int kflat_ioctl_test(struct kflat *kflat, unsigned int cmd, unsigned long arg) {

	int err;

	if ((arg&(~0x3))==SIMPLE) {
		err = kflat_simple_test(kflat,arg&0x01);	/* Always recursive */
		if (err) return err;
	}

	if ((arg&(~0x3))==CIRCLE) {
		if ((arg&2)==0) {
			err = kflat_circle_test(kflat,30,arg&0x01,cosx,sinx);
			if (err) return err;
		}
		else {
			err = kflat_circle_test_iter(kflat,750,arg&0x01,cosxi,sinxi);
			if (err) return err;
		}
	}

	if ((arg&(~0x3))==STRINGSET) {
		if ((arg&2)==0) {
			err = kflat_stringset_test(kflat,50,arg&0x01);
			if (err) return err;
		}
		else {
			err = kflat_stringset_test_iter(kflat,500,arg&0x01);
			if (err) return err;
		}
	}

	if ((arg&(~0x3))==POINTER) { /* Always recursive */
		err = kflat_pointer_test(kflat,arg&0x01);
		if (err) return err;
	}

	if ((arg&(~0x3))==CURRENTTASK) { /* Always iterative (?) */
		err = kflat_currenttask_test(kflat,arg&0x01);
		if (err) return err;
	}

	return 0;
}

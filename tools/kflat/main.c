#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <sys/time.h>
#include "aot.h"
#include "stringset.h"

#define TIME_MARK_START(start_marker)		\
		struct timeval  tv_mark_##start_marker;	\
		gettimeofday(&tv_mark_##start_marker, 0)

#define TIME_CHECK_FMT(start_marker,end_marker,fmt)	do {	\
		struct timeval  tv_mark_##start_marker##_##end_marker;	\
		gettimeofday(&tv_mark_##start_marker##_##end_marker, 0);	\
		printf(fmt,	\
		(double) (tv_mark_##start_marker##_##end_marker.tv_usec - tv_mark_##start_marker.tv_usec) / 1000000 +	\
		         (double) (tv_mark_##start_marker##_##end_marker.tv_sec - tv_mark_##start_marker.tv_sec) );	\
	} while(0)

struct flatten_header {
	size_t memory_size;
	size_t ptr_count;
	size_t root_addr_count;
	uint64_t magic;
};

enum flatten_option {
	option_silent = 0x01
};

struct blstream {
	struct blstream* next;
	struct blstream* prev;
	void* data;
	size_t size;
	size_t index;
	size_t alignment;
};

/* We got def from aot.h. */
/*
#define _ALIGNAS(n)	__attribute__((aligned(n)))
#define RB_NODE_ALIGN	(sizeof(long))

struct _ALIGNAS(RB_NODE_ALIGN) rb_node {
	uintptr_t  __rb_parent_color;
	struct rb_node *rb_right;
	struct rb_node *rb_left;
};

struct rb_root {
	struct rb_node *rb_node;
};
*/

/* Root address list */
struct root_addrnode {
	struct root_addrnode* next;
	uintptr_t root_addr;
};

struct FLCONTROL {
	struct blstream* bhead;
	struct blstream* btail;
	struct rb_root fixup_set_root;
	struct rb_root imap_root;
	struct flatten_header	HDR;
	struct root_addrnode* rhead;
	struct root_addrnode* rtail;
	struct root_addrnode* last_accessed_root;
	int debug_flag;
	unsigned long option;
	void* mem;
};

#define RB_ROOT	{ 0, }

struct FLCONTROL FLCTRL = {
		.bhead = 0,
		.btail = 0,
		.fixup_set_root = RB_ROOT,
		.imap_root = RB_ROOT,
		.rhead = 0,
		.rtail = 0,
		.mem = 0,
		.last_accessed_root=0,
		.debug_flag=0,
		.option=0
};

#define FLATTEN_MAGIC 0x464c415454454e00ULL

#define ROOT_POINTER_NEXT(PTRTYPE)	((PTRTYPE)(root_pointer_next()))
#define ROOT_POINTER_SEQ(PTRTYPE,n)	((PTRTYPE)(root_pointer_seq(n)))
#define FLATTEN_MEMORY_START	((unsigned char*)FLCTRL.mem+FLCTRL.HDR.ptr_count*sizeof(size_t))

void* root_pointer_next() {
	
	assert(FLCTRL.rhead!=0);

	if (FLCTRL.last_accessed_root==0) {
		FLCTRL.last_accessed_root = FLCTRL.rhead;
	}
	else {
		if (FLCTRL.last_accessed_root->next) {
			FLCTRL.last_accessed_root = FLCTRL.last_accessed_root->next;
		}
		else {
			assert(0);
		}
	}

	if (FLCTRL.last_accessed_root->root_addr==(size_t)-1) {
		return 0;
	}
	else {
		return (FLATTEN_MEMORY_START+FLCTRL.last_accessed_root->root_addr);
	}
}

void* root_pointer_seq(size_t index) {

	assert(FLCTRL.rhead!=0);

	FLCTRL.last_accessed_root = FLCTRL.rhead;

	size_t i=0;
	for (i=0; i<index; ++i) {
		if (FLCTRL.last_accessed_root->next) {
			FLCTRL.last_accessed_root = FLCTRL.last_accessed_root->next;
		}
		else {
			assert(0);
		}
	}

	if (FLCTRL.last_accessed_root->root_addr==(size_t)-1) {
		return 0;
	}
	else {
		return (FLATTEN_MEMORY_START+FLCTRL.last_accessed_root->root_addr);
	}
}

void root_addr_append(uintptr_t root_addr) {
    struct root_addrnode* v = calloc(1,sizeof(struct root_addrnode));
    assert(v!=0);
    v->root_addr = root_addr;
    if (!FLCTRL.rhead) {
        FLCTRL.rhead = v;
        FLCTRL.rtail = v;
    }
    else {
        FLCTRL.rtail->next = v;
        FLCTRL.rtail = FLCTRL.rtail->next;
    }
}

void fix_unflatten_memory(struct flatten_header* hdr, void* memory) {
	size_t i;
	void* mem = (unsigned char*)memory+hdr->ptr_count*sizeof(size_t);
	for (i=0; i<hdr->ptr_count; ++i) {
		size_t fix_loc = *((size_t*)memory+i);
		uintptr_t ptr = (uintptr_t)( *((void**)((unsigned char*)mem+fix_loc)) );
		/* Make the fix */
		*((void**)((unsigned char*)mem+fix_loc)) = (unsigned char*)mem + ptr;
	}
}

void unflatten_init() {
}

int unflatten_read(FILE* f) {

	TIME_MARK_START(unfl_b);
	size_t readin = 0;
	size_t rd = fread(&FLCTRL.HDR,sizeof(struct flatten_header),1,f);
	if (rd!=1) return -1; else readin+=sizeof(struct flatten_header);
	if (FLCTRL.HDR.magic!=FLATTEN_MAGIC) {
		fprintf(stderr,"Invalid magic while reading flattened image\n");
		return -1;
	}
	size_t i;
	for (i=0; i<FLCTRL.HDR.root_addr_count; ++i) {
		size_t root_addr_offset;
		size_t rd = fread(&root_addr_offset,sizeof(size_t),1,f);
		if (rd!=1) return -1; else readin+=sizeof(size_t);
		root_addr_append(root_addr_offset);
	}
	size_t memsz = FLCTRL.HDR.memory_size+FLCTRL.HDR.ptr_count*sizeof(size_t);
	FLCTRL.mem = malloc(memsz);
	assert(FLCTRL.mem);
	rd = fread(FLCTRL.mem,1,memsz,f);
	if (rd!=memsz) return -1; else readin+=rd;
	if ((FLCTRL.option&option_silent)==0) {
		printf("# Unflattening done. Summary:\n");
		TIME_CHECK_FMT(unfl_b,read_e,"  Image read time: %fs\n");
	}
	TIME_MARK_START(fix_b);
	fix_unflatten_memory(&FLCTRL.HDR,FLCTRL.mem);
	if ((FLCTRL.option&option_silent)==0) {
		TIME_CHECK_FMT(fix_b,fix_e,"  Fixing memory time: %fs\n");
		TIME_CHECK_FMT(unfl_b,fix_e,"  Total time: %fs\n");
		printf("  Total bytes read: %zu\n",readin);
	}
	return 0;
}

void unflatten_fini() {
	FLCTRL.rtail = FLCTRL.rhead;
    while(FLCTRL.rtail) {
    	struct root_addrnode* p = FLCTRL.rtail;
    	FLCTRL.rtail = FLCTRL.rtail->next;
    	free(p);
    }
    free(FLCTRL.mem);
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

struct B {
	unsigned char T[4];
};

struct A {
	unsigned long X;
	struct B* pB;
};

struct my_list_head {
	struct my_list_head* prev;
	struct my_list_head* next;
};

struct intermediate {
	struct my_list_head* plh;
};

struct my_task_struct {
	int pid;
	struct intermediate* im;
	struct my_list_head u;
	float w;
};

typedef struct struct_B {
	int i;
} my_B;

typedef struct struct_A {
	unsigned long ul;
	my_B* pB0;
	my_B* pB1;
	my_B* pB2;
	my_B* pB3;
	char* p;
} /*__attribute__((aligned(64)))*/ my_A;

int main(int argc, char* argv[]) {

	FILE* in = fopen(argv[1], "r");
	assert(in);

	size_t size;
	fread(&size,sizeof(size_t),1,in);
	printf("Size of flatten image: %zu\n",size);

	unflatten_init();
	assert(unflatten_read(in) == 0);

	if (argc>=3) {
		if (!strcmp(argv[2],"SIMPLE")) {
			printf("sizeof(struct A): %zu\n",sizeof(struct A));
			printf("sizeof(struct B): %zu\n",sizeof(struct B));
			const struct A* pA = ROOT_POINTER_NEXT(const struct A*);
			printf("pA->X: %016lx\n",pA->X);
			printf("pA->pB->T: [%02x%02x%02x%02x]\n",pA->pB->T[0],pA->pB->T[1],pA->pB->T[2],pA->pB->T[3]);
		}
		else if (!strcmp(argv[2],"CIRCLE")) {
			
			const struct figure* circle = ROOT_POINTER_NEXT(const struct figure*);
			unsigned i, j;
			double length = 0, circumference = 0;
			unsigned edge_number = 0;
			for (i = 0; i < circle->n - 1; ++i) {
				for (j = i; j < circle->n - 1; ++j) {
					if (circle->points[i].other[j]) {

						double path_len = sqrt(  pow(circle->points[i].x-circle->points[i].other[j]->x,2) +
								pow(circle->points[i].y-circle->points[i].other[j]->y,2) );
						length += path_len;

						if (j == i)
							circumference += path_len;
						if ((i == 0) && (j == circle->n - 2))
							circumference += path_len;

						unsigned u;
						for (u = 0; u < circle->n - 1; ++u) {
							if (circle->points[i].other[j]->other[u] == &circle->points[i]) {
								circle->points[i].other[j]->other[u] = 0;
							}
						}
						edge_number++;
					}
				}
			}

			printf("Number of edges/diagonals: %u\n", edge_number);
			printf("Sum of lengths of edges/diagonals: %.17f\n", length);
			printf("Half of the circumference: %.17f\n", circumference / 2);
		}
		else if (!strcmp(argv[2],"CURRENTTASK")) {
			printf("sizeof(struct task_struct): %zu\n",sizeof(struct task_struct));
		}
		else if (!strcmp(argv[2],"OVERLAPLIST")) {
			struct my_task_struct *T = ROOT_POINTER_NEXT(struct my_task_struct*);
			printf("pid: %d\n",T->pid);
			printf("T: %lx\n",(uintptr_t)T);
			printf("T->im->plh: %lx\n",(uintptr_t)T->im->plh);
			printf("T->u.prev: %lx\n",(uintptr_t)T->u.prev);
			printf("T->u.next: %lx\n",(uintptr_t)T->u.next);
			printf("w: %f\n",T->w);
		}
		else if (!strcmp(argv[2],"OVERLAPPTR")) {
			unsigned char* p = ROOT_POINTER_NEXT(unsigned char*);
			(void)p;
			my_A* pA = ROOT_POINTER_NEXT(my_A*);

			printf("%d %d %d %d\n",pA->pB0->i,pA->pB1->i,pA->pB2->i,pA->pB3->i);
			printf("%lx\n",(uintptr_t)pA->p);
			printf("%s\n",pA->p);
		}
		else if (!strcmp(argv[2],"STRINGSET")) {
			const struct rb_root* root = ROOT_POINTER_NEXT(const struct rb_root*);
			printf("stringset size: %zu\n",stringset_count(root));
			stringset_nprint(root,10);
		}
		else if (!strcmp(argv[2],"POINTER")) {
			double*** ehhh = ROOT_POINTER_SEQ(double***, 0);
			printf("The magic answer to the ultimate question of life?: %f\n", ***ehhh);
		}
	}

	unflatten_fini();
	fclose(in);

    return 0;
}

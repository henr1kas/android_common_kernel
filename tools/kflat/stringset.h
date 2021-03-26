#ifndef STRINGSET_H_
#define STRINGSET_H_

#include <stddef.h>
#include "rbtree.h"

#ifdef __linux__
#define _ALIGNAS(n)	__attribute__((aligned(n)))
#define RB_NODE_ALIGN	(sizeof(long))
#else
#ifdef _WIN32
#define _ALIGNAS(n)	__declspec(align(n))
#ifdef _M_IX86
#define RB_NODE_ALIGN	4
#elif defined _M_X64
#define RB_NODE_ALIGN	8
#endif
#endif	/* _WIN32 */
#endif /* __linux__ */

#ifdef __linux__
#include <alloca.h>
#define ALLOCA(x)	alloca(x)
#else
#ifdef _WIN32
#include <malloc.h>
#define ALLOCA(x)	_malloca(x)
#endif
#endif

#ifdef __linux__
#define container_of(ptr, type, member) ({			\
	const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
	(type *)( (char *)__mptr - offsetof(type,member) );})
#else
#ifdef _WIN32
#define container_of(ptr, type, member) (type *)( (char *)(ptr) - offsetof(type,member) )
#endif
#endif

static struct rb_root stringset_root = RB_ROOT;

struct string_node {
	struct rb_node node;
	const char* s;
};

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

	struct string_node* data = calloc(1,sizeof(struct string_node));
	data->s = strdup(s);
	struct rb_node **new = &(stringset_root.rb_node), *parent = 0;

	/* Figure out where to put new node */
	while (*new) {
		struct string_node* this = container_of(*new, struct string_node, node);

		parent = *new;
		if (strcmp(data->s,this->s)<0)
			new = &((*new)->rb_left);
		else if (strcmp(data->s,this->s)>0)
			new = &((*new)->rb_right);
		else {
		    free((void*)data->s);
		    free(data);
		    return 0;
		}
	}

	/* Add new node and rebalance tree. */
	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, &stringset_root);

	return 1;
}

static void stringset_print(const struct rb_root* root) {

	struct rb_node * p = rb_first(root);
	printf("[\n");
	while(p) {
		struct string_node* data = (struct string_node*)p;
		printf("  %s\n",data->s);
		p = rb_next(p);
	}
	printf("]\n");
}

static void stringset_nprint(const struct rb_root* root, size_t n) {

	struct rb_node * p = rb_first(root);
	printf("[\n");
	size_t i=0;
	while(p) {
		struct string_node* data = (struct string_node*)p;
		printf("  %s\n",data->s);
		p = rb_next(p);
		if (p && (i>=n-1)) {
			printf("  ...\n");
			break;
		}
		++i;
	}
	printf("]\n");
}

static void stringset_destroy(struct rb_root* root) {

    struct rb_node * p = rb_first(root);
    while(p) {
        struct string_node* data = (struct string_node*)p;
        rb_erase(p, root);
        p = rb_next(p);
        free((void*)data->s);
        free(data);
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

#endif /* STRINGSET_H_ */

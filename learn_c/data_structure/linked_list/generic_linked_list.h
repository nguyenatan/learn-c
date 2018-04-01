#ifndef _NAT_GENERIC_LINKED_LIST_H
#define _NAT_GENERIC_LINKED_LIST_H

#include <stddef.h>

struct node {
	void *data;
	struct node *next;
};

struct node* new_node(void *, size_t);

void display(struct node *, void (*)(struct node *));
void print_int(struct node *);
void print_float(struct node *);
void print_char(struct node *);
void print_str(struct node *);

void insert_tail(struct node **, void *, size_t);
void insert_head(struct node **, void *, size_t);

void clean(struct node **head);

#endif

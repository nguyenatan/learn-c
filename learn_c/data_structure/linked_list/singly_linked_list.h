#ifndef _NAT_SINGLY_LINKED_LIST_H
#define _NAT_SINGLY_LINKED_LIST_H

// sll - Singly Linked List
struct sll_node {
	int data;
	struct sll_node *next;
};

struct sll_node* sll_new(int);

int sll_length(struct sll_node *);
int sll_get_nodeth(struct sll_node *, int);

// If NULL, print "NULL"
void sll_display(struct sll_node *);
void sll_rdisplay(struct sll_node *); // Print reverse

void sll_reverse(struct sll_node **);

void sll_insert_tail(struct sll_node **, int);
void sll_insert_head(struct sll_node **, int);

void sll_delete(struct sll_node **, int);
void sll_clean(struct sll_node **);

#endif

#ifndef _NAT_BINARY_TREE_H
#define _NAT_BINARY_TREE_H

struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_node* t_new(int);

size_t t_leaf_count(struct tree_node *);

void t_display(struct tree_node *);

_Bool t_search(struct tree_node *, int);
int t_min_data(struct tree_node *);
int t_max_data(struct tree_node *);

// Returns level of a node if data is present, otherwise returns 0
int t_level_of_node_util(struct tree_node *, int, int);
int t_level_of_node(struct tree_node *, int);

void t_insert(struct tree_node **, int);

/* Queue function prototypes */
#define MAX_Q_SIZE 100

struct tree_node** create_queue(int *, int *);
void en_queue(struct tree_node **, int *, struct tree_node *);
struct tree_node* de_queue(struct tree_node **, int *);
/*                           */

#endif

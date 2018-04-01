#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main(void)
{
	struct tree_node *root = t_new(4);
	
	t_insert(&root, 7);
	t_insert(&root, 1);
	t_insert(&root, 5);
	t_insert(&root, 9);
	t_insert(&root, 8);
	
	t_display(root);
	printf("\n%d\n", t_search(root, 3));
	printf("%d\n", t_level_of_node(root, 4));
	
	return 0;
}

struct tree_node* t_new(int data)
{
	struct tree_node *node = malloc(sizeof(struct tree_node));
	node->data = data;
	node->left = node->right = NULL;
	
	return node;
}

size_t t_leaf_count(struct tree_node *root)
{
	if (!root)
		return 0;
	
	if (!root->left && !root->right)
		return 1;
	else
		return t_leaf_count(root->left) + t_leaf_count(root->right);
}

void t_display(struct tree_node *root)
{
	int front, rear;
	struct tree_node **queue = create_queue(&front, &rear);
	
	while (root) {
		printf("%d ", root->data);
		
		if (root->left)
			en_queue(queue, &rear, root->left);
		
		if (root->right)
			en_queue(queue, &rear, root->right);
			
		root = de_queue(queue, &front);
	}
}

_Bool t_search(struct tree_node *root, int key)
{
	if (!root)
		return 0;
	
	if (root->data == key)
		return 1;
	
	if (root->data > key)
		return t_search(root->left, key);
	
	return t_search(root->right, key);
}

int t_min_data(struct tree_node *root)
{
	while (root) {
		if (!root->left)
			return root->data;
		root = root->left;
	}
}

int t_max_data(struct tree_node *root)
{
	while (root) {
		if (!root->right)
			return root->data;
		root = root->right;
	}
}

int t_level_of_node_util(struct tree_node *root, int key, int level)
{
	if (!root)
		return 0;
	
	if (root->data == key)
		return level;
	
	int downLevel = t_level_of_node_util(root->left, key, level+1);
	if (downLevel)
		return downLevel;
	
	downLevel = t_level_of_node_util(root->right, key, level+1);
	return downLevel;
}

int t_level_of_node(struct tree_node *root, int key)
{
	return t_level_of_node_util(root, key, 1);
}

void t_insert(struct tree_node **root, int data)
{
	while (*root) {
		if ((*root)->data == data)
			return;
		
		if ((*root)->data > data)
			root = &(*root)->left;
		else
			root = &(*root)->right;
	}
	
	if (!(*root = t_new(data)))
		printf("Allocate error\n");
}

/* Queue functions */
struct tree_node** create_queue(int *front, int *rear)
{
	struct tree_node **queue = malloc(sizeof(struct tree_node)*MAX_Q_SIZE);
	*front = *rear = 0;
	
	return queue;
}

void en_queue(struct tree_node **queue, int *rear, struct tree_node *node)
{
	queue[(*rear)++] = node;
}

struct tree_node* de_queue(struct tree_node **queue, int *front)
{
	return queue[(*front)++];
}

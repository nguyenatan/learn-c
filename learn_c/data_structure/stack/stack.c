#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

int main(void)
{
	struct stack *root = NULL;
	int i = 0;
	while (i++ < 5)
		push(&root, i);
	
	i = 0;
	while (i++ < 6) {
		s_display(root);
		printf("pop(): %d\n\n", pop(&root));
	}
	
	return 0;
}

struct stack* s_new(int data)
{
	struct stack *node = malloc(sizeof(struct stack));
	node->data = data;
	node->next = NULL;
	
	return node;
}

size_t stack_size(struct stack *root)
{
	size_t count = 0;
	
	while (root) {
		++count;
		root = root->next;
	}
	
	return count;
}

void s_display(struct stack *root)
{
	if (!root) {
		printf("NULL\n");
		return;
	}
	
	printf("Top - ");
	while (root) {
		printf(root->next ? "%d " : "%d\n", root->data);
		root = root->next;
	}
}

void push(struct stack **root, int data)
{
	struct stack *node = s_new(data);
	node->next = *root;
	
	*root = node;
}

int pop(struct stack **root)
{
	if (!*root)
		return INT_MIN;
	
	int value = (*root)->data;
	*root = (*root)->next;
	free(root);
	
	return value;
}

int peek(struct stack *root)
{
	if (!root)
		return INT_MIN;
	
	return root->data;
}

void clean(struct stack **root)
{
	while (*root) {
		struct stack *temp = *root;
		*root = (*root)->next;
		free(temp);
	}
}

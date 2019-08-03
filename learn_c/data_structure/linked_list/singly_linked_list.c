#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

int main(void)
{
	struct sll_node *head = sll_new(2);
	
	int i = 2;
	while (i++ < 5)
		sll_insert_tail(&head, i);
		
	sll_insert_head(&head, 1);
	
	printf("%d\n", sll_length(head));
	
	sll_display(head);
	
	sll_reverse(&head);
	sll_display(head);
	
	sll_delete(&head, 1);
	sll_delete(&head, 5);
	sll_display(head);
	sll_rdisplay(head);
	
	sll_clean(&head);
	sll_display(head);
	sll_rdisplay(head);
	
	return 0;
}

struct sll_node* sll_new(int data)
{
	struct sll_node *node = malloc(sizeof(struct sll_node));
	
	node->data = data;
	node->next = NULL;
	
	return node;
}

int sll_length(struct sll_node *head)
{
	return !head ? 0 : 1 + sll_length(head->next);
}

int sll_get_nodeth(struct sll_node *head, int position)
{
	int i = 0;
	while (i < position-1 && head) {
		head = head->next;
		++i;
	}
	
	return head->data;
}

void sll_display(struct sll_node *head)
{
	if (!head) {
		printf("NULL\n");
		return;
	}
	
	while (head) {
		printf(head->next ? "%d " : "%d\n", head->data);
		head = head->next;
	}
}

void sll_rdisplay(struct sll_node *head)
{
	int n = sll_length(head);
	
	if (!head) {
		printf("NULL\n");
		return;
	}
	
	int i = n;
	while (i >= 1) {
		printf(i != 1 ? "%d " : "%d\n", sll_get_nodeth(head, i));
		--i;
	}
}

void sll_reverse(struct sll_node **head)
{
	struct sll_node *prev = NULL;
	
	while (*head) {
		struct sll_node *next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	
	*head = prev;
}

void sll_insert_tail(struct sll_node **head, int data)
{
	struct sll_node *node = sll_new(data);
	
	while (*head)
		head = &(*head)->next;
	
	*head = node;
}

void sll_insert_head(struct sll_node **head, int data)
{
	struct sll_node *node = malloc(sizeof(struct sll_node));
	
	node->data = data;
	node->next = *head;
	
	*head = node;
}

void sll_delete(struct sll_node **head, int key)
{
	struct sll_node *entry = *head;
	
	while (entry) {
		if (entry->data == key)
			*head = entry->next;
		
		head = &(*head)->next;
		entry = entry->next;
	}
}

void sll_clean(struct sll_node **head)
{
	while (*head) {
		struct sll_node *temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

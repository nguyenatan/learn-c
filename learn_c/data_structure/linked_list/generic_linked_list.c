#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic_linked_list.h"

int main(void)
{
	struct node *int_head = NULL;
	int int_data = 1; int int_size = sizeof(int);
	
	struct node *float_head = NULL;
	float float_data = 1.0; int float_size = sizeof(float);
	
	struct node *char_head = NULL;
	char char_data = 'a'; int char_size = sizeof(char);
	
	struct node *str_head = NULL;
	char *str[] = { "Nguyen", "A", "Tan" };
	
	int i = -1;
	while (i++ < 2) {
		insert_tail(&int_head, &int_data, int_size);
		++int_data;
		
		insert_tail(&float_head, &float_data, float_size);
		++float_data;
		
		insert_tail(&char_head, &char_data, char_size);
		++char_data;
		
		int str_size = strlen(str[i]) + 1;
		insert_tail(&str_head, str[i], str_size);
	}
	
	display(int_head, print_int);
	display(float_head, print_float);
	display(char_head, print_char);
	display(str_head, print_str);
	
	clean(&str_head);
	display(str_head, print_str);
	
	return 0;
}

struct node* new_node(void *data, size_t data_size)
{
	struct node *node = malloc(sizeof(struct node));
	node->data = malloc(data_size);
	node->next = NULL;
	
	int i = 0;
	while (i < data_size) {
		*(char *)(node->data + i) = *(char *)(data + i);
		++i;
	}
	
	return node;
}

void display(struct node *head, void (*fp)(struct node *))
{
	if (!head) {
		printf("NULL\n");
		return;
	}
	
	while (head) {
		(*fp)(head);
		head = head->next;
	}
}

void print_int(struct node *head)
{
	printf(head->next ? "%d " : "%d\n", *(int *)head->data);
}

void print_float(struct node *head)
{
	printf(head->next ? "%f " : "%f\n", *(float *)head->data);
}

void print_char(struct node *head)
{
	printf(head->next ? "%c " : "%c\n", *(char *)head->data);
}

void print_str(struct node *head)
{
	printf(head->next ? "\"%s\" " : "\"%s\"\n", (char *)head->data);
}

void insert_tail(struct node **head, void *data, size_t data_size)
{
	struct node *node = new_node(data, data_size);
	
	while (*head)
		head = &(*head)->next;
	
	*head = node;
}

void insert_head(struct node **head, void *data, size_t data_size)
{
	struct node *node = malloc(sizeof(struct node));
	node->data = malloc(data_size);
	node->next = *head;
	
	int i = 0;
	while (i < data_size) {
		*(char *)(node->data + i) = *(char *)(data + i);
		++i;
	}
	
	*head = node;
}

void clean(struct node **head)
{
	while (*head) {
		struct node *temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

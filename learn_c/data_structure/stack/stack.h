#ifndef _NAT_STACK_H
#define _NAT_STACK_H

#include <stddef.h>

struct stack {
	int data;
	struct stack *next;
};

struct stack* s_new(int);

size_t stack_size(struct stack *);

void s_display(struct stack *);

void push(struct stack **, int);

int pop(struct stack **);

int peek(struct stack *);

void clean(struct stack **);

#endif

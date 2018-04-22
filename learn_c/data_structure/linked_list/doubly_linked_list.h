#ifndef _NAT_DOUBLY_LINKED_LIST_H
#define _NAT_DOUBLY_LINKED_LIST_H

#include "nat_utility.h"

struct list_head {
	struct list_node *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name)	\
		struct list_head name = LIST_HEAD_INIT(name)
		
static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}


static inline bool
__list_add_valid(struct list_head *new, struct list_head *prev, struct list_head *next)
{
	return true;
}

static inline bool __list_del_entry_valid(struct list_head *entry)
{
	return true;
}

/*
 * Insert a new entry between consecutive entries.
 */
static inline void
__list_add(struct list_head *new, struct list_head *prev, struct list_head *next)
{
	if (!__list_add_valid(new, prev, next))
		return;
	
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

/*
 * list_add - add a new entry after the specified head.
 */
static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}

/*
 * list_add_tail - add a new entry before the specified head.
 */
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
	__list_add(new, head->prev, head);
}

/*
 * list_del - deletes entry from list.
 */
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
	next->prev = prev;
	prev->next = next;
}

static inline void __list_del_entry(struct list_head *entry)
{
	if (!__list_del_entry_valid(entry))
		return;
	
	__list_del(entry->prev, entry->next);
}

static inline void list_del(struct list_head *entry)
{
	__list_del_entry(entry);
	entry->next = NULL;
	entry->prev = NULL;
}

/*
 * list_empty - tests whether a list is empty.
 */
static inline int list_empty(const struct list_head *head)
{
	return head->next == head;
}

/*
 * list_entry - get the struct for this entry.
 */
#define list_entry(ptr, type, member)	\
		container_of(ptr, type, member)

/*
 * list_for_each - iterate over a list.
 */
#define list_for_each(pos, head)	\
		for (pos = (head)->next; pos != (head); pos = pos->next)

/*
 * list_next_entry - get the next element in list.
 */
#define list_next_entry(pos, member)	\
		list_entry((pos)->member.next, typeof(*(pos)), member)

#endif

#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

struct animal_list {
	char name[20];
	struct list_head list;
};

int main(void)
{
	struct animal_list *entry;
	struct list_head *pos;
	
	struct animal_list myList;
	INIT_LIST_HEAD(&myList.list);
	
	int i = 0;
	for (; i < 3; ++i) {
		entry = malloc(sizeof(struct animal_list));
		
		printf("Type animal name: ");
		scanf("%s", entry->name);
		
		list_add(&entry->list, &myList.list);
	}
	
	printf("\n");
	
	list_for_each(pos, &myList.list) {
		entry = list_entry(pos, struct animal_list, list);
		
		printf("%s\n", entry->name);
	}
	
	printf("\n");
	
	list_del(&entry->list);
	list_for_each(pos, &myList.list) {
		entry = list_entry(pos, struct animal_list, list);
		
		printf("%s\n", entry->name);
	}
	
	return 0;
}

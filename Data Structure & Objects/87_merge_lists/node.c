#include <stdio.h>
#include "node.h"

struct node *merge(struct node *list1, struct node *list2) {
	struct node *newList = NULL;

	if (list1 == NULL)
		return list2;
	else if (list2 == NULL)
		return list1;
	else {
		if (list1 -> value < list2 -> value) {
			newList = list1;
			newList -> next = merge(list1 -> next, list2);
		} else {
			newList = list2;
			newList -> next = merge(list1, list2 -> next);
		}
	}

	return newList;
}
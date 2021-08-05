#include <stdio.h>
#include "node.h"

struct node *getNode(struct node *head, unsigned int i) {
	unsigned int count = 0;
	struct node *ptr = head;
	
	while(ptr != NULL) {
		++count;
		ptr = ptr -> next;
	}

	if (i >= count)
		return NULL;

	ptr = head;
	for (int n = 0; n + i + 1 != count; ++n)
		ptr = ptr -> next;

	return ptr;
}
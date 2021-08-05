#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "memory.h"

Memory *getMemoryBlock(int start, int length, Memory *next) {
	Memory *memory = (Memory *)malloc(sizeof(Memory));
	memory -> start = start;
	memory -> length = length;
	memory -> next = next;

	return memory;
}

void initMemory(Memory **memory, int length) {
	*memory = getMemoryBlock(0, length, NULL);
}

void printMemory(Memory **memory) {
	Memory *ptr = *memory;

	printf("==========\n");
	while (ptr != NULL) {
		printf("start %d, length %d\n", ptr -> start, ptr -> length);
		ptr = ptr -> next;
	}
}

void allocateMemory(Memory **memory, int start, int length) {
	Memory *current = *memory;
	Memory *before = NULL;

	// skip current block does not include start
	while ((start < current -> start) || (start >= current -> start + current -> length)) {
		before = current;
		current = current -> next;
	}

	bool beginSame = (start == current -> start);
	bool endSame = (start + length == current -> start + current -> length);

	if (beginSame && endSame) {
		if (before == NULL) {
			*memory = current -> next;
		} else before -> next = current -> next;

		free(current);
	} else if (beginSame) {
		current -> start += length;
		current -> length -= length;
	} else if (endSame) {
		current -> length -= length;
	} else {
		Memory *after = getMemoryBlock(start + length, current -> start + current -> length - (start + length), current -> next);
		current -> next = after;
		current -> length = start - current -> start;
	}
}

void freeMemory(Memory **memory, int start, int length) {
	Memory *current = *memory;
	Memory *before = NULL;
	
	// locate the used memory that is within the before block and the current block
	while ((current != NULL) && (start > current -> start)) {
		before = current;
		current = current -> next;
	}

	bool adjacentBefore = (before != NULL) && (start == before -> start + before -> length);
	bool adjacentCurrent = (current != NULL) && (start + length == current -> start);

	if (adjacentBefore && adjacentCurrent) {
		before -> length += (length + current -> length);
		before -> next = current -> next;
		free(current);
	} else if (adjacentBefore) {
		before -> length += length;
	} else if (adjacentCurrent) {
		current -> length += length;
		current -> start -= length;
	} else {
		Memory *between = getMemoryBlock(start, length, current);
		if (before == NULL)
			*memory = between;
		else
			before -> next = between;
	}
}
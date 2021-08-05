#include <stdio.h>
#include "heap.h"

void initialize(struct Heap *heap) {
	heap -> num = 0;
	return;
}

int removeMin(struct Heap *heap) {
	int min = heap -> ary[0], target;

	for (int i = 0; i < heap -> num; ++i) {
		if (heap -> ary[i] > min)
			continue;

		min = heap -> ary[i];
		target = i;
	}

	--heap -> num;

	for (int i = target; i < heap -> num; ++i)
		heap -> ary[i] = heap -> ary[i + 1];

	return min;
}

void add(struct Heap *heap, int i) {
	heap -> ary[heap -> num++] = i;
	return;
}

int isFull(struct Heap *heap) {
	return (heap -> num == MAXHEAP);
}

int isEmpty(struct Heap *heap) {
	return (heap -> num == 0);
}
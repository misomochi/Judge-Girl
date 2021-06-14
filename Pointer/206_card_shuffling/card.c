#include <stdio.h>
#include "card.h"

void shuffle(int *deck[]) {
	int index = 0;
	int *temp[10000] = {NULL};

	while (deck[index] != NULL) {
		temp[index] = deck[index];
		++index;
	}

	for (int i = 0; i < index; ++i)
		deck[i] = (i % 2 == 0) ? temp[i / 2] : temp[(i + index) / 2];

	return;
}

void print(int *deck[]) {
	int index = 0;

	while(deck[index] != NULL) {
		printf("%d ", *deck[index]);
		++index;
	}

	return;
}
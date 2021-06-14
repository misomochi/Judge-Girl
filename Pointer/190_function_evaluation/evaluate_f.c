#include <stdio.h>
#include "evaluate_f.h"

int evaluate_f(int *iptr[], int n, int *index) {
	int max = -2147483648; // INT_MIN

	for (int i = 0; i < n; ++i) {
		if (f(*iptr[i], *(iptr[i] + 1)) <= max)
			continue;

		max = f(*iptr[i], *(iptr[i] + 1));
		*index = i;
	}

	return max;
}

int f(int x, int y) {
	return 4 * x - 6 * y;
}
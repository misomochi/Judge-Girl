#include "max.h"

int max(int *iptr[], int n) {
	int temp = -2147483648; // INT_MIN

	for (int i = 0; i < n; ++i) {
		if (*iptr[i] < temp)
			continue;

		temp = *iptr[i];
	}

	return temp;
}
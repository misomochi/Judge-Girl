#include <stdio.h>
#include "fill_array.h"

void fill_array(int *ptr[], int n) {
	for (int *p = ptr[0]; p != ptr[n - 1]; ++p)
		*p = -1;

	for (int i = 0; i < n; ++i)
		*ptr[i] = i;

	int *start = ptr[0], *end = ptr[0];
	for (int *p = ptr[0]; p != ptr[n - 1]; ++p) {
		if (*p == -1)
			*p = *start + *end;
		else {
			start = p;

			do {
				++end;
			} while (*end == -1);
		}
	}

	return;
}
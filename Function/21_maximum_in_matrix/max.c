#include "max.h"

int max(int array[ROWSIZE][COLUMNSIZE]) {
	int max = -2147483648;

	for (int i = 0; i < ROWSIZE; ++i) {
		for (int j = 0; j < COLUMNSIZE; ++j) {
			if (array[i][j] <= max)
				continue;

			max = array[i][j];
		}
	}

	return max;
}
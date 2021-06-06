#include "posneg.h"

void posneg(int array[ARRAYSIZE][ARRAYSIZE], int result[RESULTSIZE]) {
	for (int i = 0; i < RESULTSIZE; ++i)
		result[i] = 0;

	for (int i = 0; i < ARRAYSIZE; ++i) {
		for (int j = 0; j < ARRAYSIZE; ++j) {
			if (array[i][j] == 0)
				continue;

			(array[i][j] > 0) ? ++result[1] : ++result[0];
		}
	}
}
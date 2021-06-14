#include <stdio.h>
#include "snake.h"

void snake(const int *ptr_array[100][100], int m) {
	const int *temp[10000];

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			temp[i * m + j] = ptr_array[i][j];

	bubbleSort(temp, m * m);

	for (int i = 0; i < m; ++i) {
		switch (i % 2) {
			case 0:
				for (int j = 0; j < m; ++j)
					ptr_array[i][j] = temp[i * m + j];
				break;
			case 1:
				for (int j = 0; j < m; ++j)
					ptr_array[i][m - 1 - j] = temp[i * m + j];
				break;
		}
	}

	return;
}

void bubbleSort(const int *arr[], int n) {
    const int *p;
    
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (*arr[j] > *arr[j + 1]) {
				p = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = p;
			}
		}
	}
}
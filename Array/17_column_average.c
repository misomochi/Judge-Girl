#include <stdio.h>

int main(int argc, char const *argv[])
{
	int r, c;
	scanf("%d%d", &r, &c);

	int i, j, matrix[r][c];
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) {
			scanf("%d", &(matrix[i][j]));
		}
	}

	int sum;

	for (j = 0; j < c; ++j) {
		sum = 0;

		for (i = 0; i < r; ++i) {
			sum += matrix[i][j];
		}

		printf("%d\n", sum / r);
	}

	return 0;
}
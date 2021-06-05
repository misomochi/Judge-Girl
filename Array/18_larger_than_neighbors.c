#include <stdio.h>

int main(int argc, char const *argv[])
{
	int r, c;
	scanf("%d%d", &r, &c);

	int matrix[r + 2][c + 2];
	for (int i = 0; i < r + 2; ++i) {
		for (int j = 0; j < c + 2; ++j) {
			if (!(i && j) || i == r + 1 || j == c + 1)
				matrix[i][j] = 0;
			else
				scanf("%d", &(matrix[i][j]));
		}
	}

	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (matrix[i][j] > matrix[i - 1][j] && matrix[i][j] > matrix[i][j - 1] && matrix[i][j] > matrix[i][j + 1] && matrix[i][j] > matrix[i + 1][j])
				printf("%d\n", matrix[i][j]);

			continue;
		}
	}

	return 0;
}
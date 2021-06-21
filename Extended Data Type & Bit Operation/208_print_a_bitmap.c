#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	int column, row, mask = INT_MIN;
	scanf("%d%d", &column, &row);

	char c1[2], c2[2];
	scanf("%s%s", c1, c2);

	unsigned int n;

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			if ((i * column + j) % 32 == 0)
				scanf("%u", &n);

			(n & mask) ? printf("%s", c1) : printf("%s", c2);
			n <<= 1;
		}

		printf("\n");
	}

	return 0;
}
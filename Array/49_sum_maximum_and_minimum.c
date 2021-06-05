#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d%d", &n, &m);

	int remainder[m][3];
	for (int i = 0; i < m; ++i) {
		remainder[i][0] = 0;
		remainder[i][1] = 0;
		remainder[i][2] = 10000;
	}

	int temp, r;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &temp);

		r = temp % m;

		remainder[r][0] += temp;
		remainder[r][1] = (temp > remainder[r][1]) ? temp : remainder[r][1];
		remainder[r][2] = (temp < remainder[r][2]) ? temp : remainder[r][2];
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%d", remainder[i][j]);
			(j == 2) ? printf("\n") : printf(" ");
		}
	}

	return 0;
}
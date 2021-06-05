#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int f[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &(f[i]));

	int m;
	scanf("%d", &m);

	int g[m];
	for (int i = 0; i < m; ++i)
		scanf("%d", &(g[i]));

	int fg[m + n - 1];
	for (int i = 0; i < m + n - 1; ++i)
		fg[i] = 0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			fg[i + j] += f[i] * g[j];

	for (int i = 0; i < m + n - 1; ++i) {
		printf("%d", fg[i]);
		(i == m + n - 2) ? printf("\n") : printf(" ");
	}

	return 0;
}
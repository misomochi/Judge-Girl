#include <stdio.h>

int combination(int, int);

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d%d", &n, &m);

	int sum = 0;

	for (int i = 0; i <= m; ++i)
		sum += combination(n, i);

	printf("%d\n", sum);

	return 0;
}

int combination(int n, int k) {
	int c = 1;

	for (int i = n; i > n - k; --i)
		c *= i;

	for (int i = k; i > 0; --i)
		c /= i;

	return c;
}
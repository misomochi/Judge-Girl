#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		printf("%d\n", i);

	for (int j = n - 1; j > 0; --j)
		printf("%d\n", j);

	return 0;
}
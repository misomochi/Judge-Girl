#include <stdio.h>

#define MAXARRAYSIZE 200000

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int num[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &(num[i]));

	int m;
	scanf("%d", &m);

	int remainder[MAXARRAYSIZE] = {0};

	for (int i = 0; i < n; ++i)
		++remainder[num[i] % m];

	for (int i = 0; i < m; ++i)
		printf("%d\n", remainder[i]);

	return 0;
}
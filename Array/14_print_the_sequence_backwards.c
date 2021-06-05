#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int seq[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &(seq[i]));

	for (int i = n - 1; i >= 0; --i) {
		printf("%d", seq[i]);

		if (i != 0)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}
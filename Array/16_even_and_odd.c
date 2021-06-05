#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int seq[n], odd = 0, even = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &(seq[i]));

		(seq[i] % 2 == 0) ? ++even : ++ odd;
	}

	for (int i = 0; i < n; ++i) {
		if (seq[i] % 2 == 0)
			continue;

		printf("%d", seq[i]);
		--odd;

		if (odd != 0)
			printf(" ");
		else
			printf("\n");
	}

	for (int i = 0; i < n; ++i) {
		if (seq[i] % 2 == 1)
			continue;

		printf("%d", seq[i]);
		--even;

		if (even != 0)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}
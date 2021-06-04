#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int num, r0 = 0, r1 = 0, r2 = 0;

	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);

		switch (num % 3) {
			case 0:
				++r0;
				break;
			case 1:
				++r1;
				break;
			case 2:
				++r2;
				break;
		}
	}

	printf("%d %d %d", r0, r1, r2);

	return 0;
}
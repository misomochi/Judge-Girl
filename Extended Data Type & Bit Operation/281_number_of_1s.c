#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, count;
	
	while (scanf("%d", &n) != EOF) {
		count = 0;

		while (n != 0) {
			count = (n % 2) ? count + 1 : count;
			n /= 2;
		}

		printf("%d\n", count);
	}

	return 0;
}
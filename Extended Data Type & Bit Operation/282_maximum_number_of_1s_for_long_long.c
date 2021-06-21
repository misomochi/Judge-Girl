#include <stdio.h>

int main(int argc, char const *argv[])
{
	long long int n;
	int count;
	
	while (scanf("%lld", &n) != EOF) {
		count = 0;

		while (n != 0) {
			count = (n % 2) ? count + 1 : count;
			n /= 2;
		}

		printf("%d\n", count);
	}

	return 0;
}
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	int n, count, max;
	bool previous;

	while (scanf("%d", &n) != EOF) {
	    max = count = 0;
		previous = false;

		while (n != 0) {
			count = (n % 2) ? (previous ? count + 1 : 1) : 0;
            max = (count > max) ? count : max;
            previous = n % 2;
			n /= 2;
		}
		
		printf("%d\n", max);
	}

	return 0;
}
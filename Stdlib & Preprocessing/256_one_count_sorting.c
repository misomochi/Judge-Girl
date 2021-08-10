#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE 1000

int compare(const void *a, const void *b);

int main(int argc, char const *argv[])
{
	unsigned long long int num[ARRAYSIZE] = {0};
	int index = 0;

	while (scanf("%llu", &(num[index])) != EOF) {
		++index;
	}

	qsort(num, index, sizeof(unsigned long long int), compare);

	for (int i = 0; i < index; ++i)
		printf("%llu\n", num[i]);

	return 0;
}

int compare(const void *a, const void *b) {
	unsigned long long int *n1 = (unsigned long long int *)a;
	unsigned long long int *n2 = (unsigned long long int *)b;
	unsigned long long int mask = 1;
	int c1 = 0, c2 = 0;

	for (int i = 0; i < 64; ++i) {
		if (*n1 & (mask << i))
			++c1;

		if (*n2 & (mask << i))
			++c2;
	}

	if (c1 == c2) {
		if (*n1 > *n2)
			return 1;
		else if (*n1 < *n2)
			return -1;
		else
			return 0;
	}
	else
		return c1 - c2;
}
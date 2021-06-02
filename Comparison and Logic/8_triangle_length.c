#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	bool valid = (a + b > c) && (b + c > a) && (c + a > b);

	printf("%d\n", valid);

	return 0;
}
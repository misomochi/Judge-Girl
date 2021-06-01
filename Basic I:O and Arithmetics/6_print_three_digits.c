#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x;
	scanf("%d", &x);

	if (x < 100 || x > 999)
		return -1;

	printf("%d\n", x / 100);
	x %= 100;
	printf("%d\n", x / 10);
	x %= 10;
	printf("%d\n", x);

	return 0;
}
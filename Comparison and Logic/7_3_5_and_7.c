#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	int x;
	scanf("%d", &x);

	bool result = (x % 3 == 0) && (x % 5 == 0) && (x % 7 != 0);

	printf("%d\n", !result);

	return 0;
}
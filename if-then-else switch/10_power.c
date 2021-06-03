#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, power;
	scanf("%d%d", &n, &power);

	int result = 1;

	for (int i = 0; i < power; ++i)
		result *= n;

	printf("%d", result);

	return 0;
}
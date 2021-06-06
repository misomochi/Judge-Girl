#include <stdio.h>

int gcd(int, int);

int main(int argc, char const *argv[])
{
	int n, lcm = 1;
	while (scanf("%d", &n) != EOF)
		lcm = lcm * n / gcd(lcm, n);

	printf("%d\n", lcm);

	return 0;
}

// Euclidean Algorithm
int gcd(int a, int b) {
	if (a == 0)
		return b;

	return gcd(b % a, a);
}
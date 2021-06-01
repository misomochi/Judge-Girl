#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a, b, c, d, e;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

	int area = 2 * (a * b + b * c + c * a + d * 4 * ((a - 2 * e) + (b - 2 * e) + (c - 2 * e)));
	int volume = a * b * c - 2 * d * ((a - 2 * e) * (c - 2 * e) + (b - 2 * e) * (c - 2 * e) + (a - 2 * e) * (b - 2 * e));

	printf("%d\n", area);
	printf("%d\n", volume);

	return 0;
}
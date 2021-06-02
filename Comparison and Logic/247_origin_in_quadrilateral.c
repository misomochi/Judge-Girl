#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	int a, b, c, d, e, f, g, h;
	scanf("%d%d", &a, &b);
	scanf("%d%d", &c, &d);
	scanf("%d%d", &e, &f);
	scanf("%d%d", &g, &h);

	bool result = (a * d - b * c > 0) && (c * f - d * e > 0) && (e * h - f * g > 0) && (b * g - a * h > 0);

	printf("%d\n", result);

	return 0;
}
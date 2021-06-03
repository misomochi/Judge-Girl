#include <stdio.h>

int main(int argc, char const *argv[])
{
	int s, f, t;
	scanf("%d%d%d", &s, &f, &t);

	int crab = s - t;
	int rabbit = (f + 6 * t - 8 * s) / 2;
	int chicken = (8 * s - 4 * t - f) / 2;

	if (s - t < 0 || f + 6 * t - 8 * s < 0 || 8 * s - 4 * t - f < 0 || (f + 6 * t - 8 * s) % 2 == 1 || (8 * s - 4 * t - f) % 2 == 1)
		printf("%d\n", 0);
	else {
		printf("%d\n", chicken);
		printf("%d\n", rabbit);
		printf("%d\n", crab);
	}

	return 0;
}
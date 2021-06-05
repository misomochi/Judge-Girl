#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x, y;
	int max_x = -10000, max_y = -10000, min_x = 10000, min_y = 10000;

	while (scanf("%d%d", &x, &y) != EOF) {
		max_x = (x > max_x) ? x : max_x;
		max_y = (y > max_y) ? y : max_y;
		min_x = (x < min_x) ? x : min_x;
		min_y = (y < min_y) ? y : min_y;
	}

	// area
	printf("%d\n", (max_x - min_x) * (max_y - min_y));

	return 0;
}
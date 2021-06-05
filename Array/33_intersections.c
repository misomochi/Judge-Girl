#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int road[n + 2][n + 2];
	for (int i = 0; i < n + 2; ++i) {
		for (int j = 0; j < n + 2; ++j) {
			if (!(i && j) || i == n + 1 || j == n + 1)
				road[i][j] = 0;
			else
				scanf("%d", &(road[i][j]));
		}
	}

	int intersections = 0, t_junctions = 0, turns = 0, dead_ends = 0, sum = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (road[i][j])
				sum = road[i - 1][j] + road[i][j - 1] + road[i][j + 1] + road[i + 1][j];
			else continue;

			switch (sum) {
				case 1:
					++dead_ends;
					break;
				case 2:
					if (!(road[i - 1][j] && road[i + 1][j]) && !(road[i][j - 1] && road[i][j + 1]))
						++turns;
					else continue;
					break;
				case 3:
					++t_junctions;
					break;
				case 4:
					++intersections;
					break;
				default:
					continue;
			}
		}
	}

	printf("%d\n", intersections);
	printf("%d\n", t_junctions);
	printf("%d\n", turns);
	printf("%d\n", dead_ends);

	return 0;
}
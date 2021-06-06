#include "intersection.h"

void intersection(int map[MAPSIZE][MAPSIZE], int result[RESULTSIZE]) {
	int road[MAPSIZE + 2][MAPSIZE + 2];

	for (int i = 0; i < MAPSIZE + 2; ++i) {
		for (int j = 0; j < MAPSIZE + 2; ++j) {
			if (!(i && j) || i == MAPSIZE + 1 || j == MAPSIZE + 1)
				road[i][j] = 0;
			else
				road[i][j] = map[i - 1][j - 1];
		}
	}

	for (int i = 0; i < RESULTSIZE; ++i)
		result[i] = 0;

	int sum = 0;

	for (int i = 1; i <= MAPSIZE; ++i) {
		for (int j = 1; j <= MAPSIZE; ++j) {
			if (road[i][j])
				sum = road[i - 1][j] + road[i][j - 1] + road[i][j + 1] + road[i + 1][j];
			else continue;

			switch (sum) {
				case 1:
					++result[3];
					break;
				case 2:
					if (!(road[i - 1][j] && road[i + 1][j]) && !(road[i][j - 1] && road[i][j + 1]))
						++result[2];
					else continue;
					break;
				case 3:
					++result[1];
					break;
				case 4:
					++result[0];
					break;
				default:
					continue;
			}
		}
	}
}
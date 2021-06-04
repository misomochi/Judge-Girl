#include <stdio.h>

int main(int argc, char const *argv[])
{
	int w, d;
	scanf("%d%d", &w, &d);

	int mirror[d][w];

	for (int i = 0; i < d; ++i) {
		for (int j = 0; j < w; ++j)
			scanf("%d", &(mirror[i][j]));
	}

	int x, y, reflection;

	//mirror[d - 1][0] ~ mirror[d - 1][w - 1]
	for (int i = 0; i < w; ++i) {
		// starting position
		x = d - 1;
		y = i;
		reflection = 0;

		while (x >= 0 && x < d && y >= 0 && y < w) {
			if (mirror[x][y])
				++reflection;
			
			(reflection % 2) ? ++y : --x;
		}

		if (reflection % 2 == 0)
			printf("%d\n", (2 * w + d - 1) - y);
		else
			printf("%d\n", (w + d - 1) - x);
	}

	//mirror[d - 1][w - 1] ~ mirror[0][w - 1]
	for (int i = d - 1; i >= 0; --i) {
		// starting position
		x = i;
		y = w - 1;
		reflection = 0;

		while (x >= 0 && x < d && y >= 0 && y < w) {
			if (mirror[x][y])
				++reflection;
			
			(reflection % 2) ? ++x : --y;
		}

		if (reflection % 2 == 0)
			printf("%d\n", x + (2 * w + d));
		else
			printf("%d\n", y);
	}

	// mirror[d - 1][w - 1] ~ mirror[d - 1][0]
	for (int i = w - 1; i >= 0; --i) {
		// starting position
		x = 0;
		y = i;
		reflection = 0;

		while (x >= 0 && x < d && y >= 0 && y < w) {
			if (mirror[x][y])
				++reflection;
			
			(reflection % 2) ? --y : ++x;
		}

		if (reflection % 2 == 0)
			printf("%d\n", y);
		else
			printf("%d\n", x + (2 * w + d));
	}

	// mirror[0][w - 1] ~ mirror[d - 1][w - 1]
	for (int i = 0; i < d; ++i) {
		// starting position
		x = i;
		y = 0;
		reflection = 0;

		while (x >= 0 && x < d && y >= 0 && y < w) {
			if (mirror[x][y])
				++reflection;
			
			(reflection % 2) ? --x : ++y;
		}

		if (reflection % 2 == 0)
			printf("%d\n", (w + d - 1) - x);
		else
			printf("%d\n", (2 * w + d - 1) - y);
	}

	return 0;
}
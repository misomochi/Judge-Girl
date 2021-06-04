#include <stdio.h>
#include <stdbool.h>

int countLaticePoints1(double, double, double);
int countLaticePoints2(double, double, double, double, double, double);
int countLaticePoints3(double, double, double, double, double, double, double, double, double);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int x[3], y[3], r[3], points;

	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &x[0], &y[0], &r[0]);
		scanf("%d%d%d", &x[1], &y[1], &r[1]);
		scanf("%d%d%d", &x[2], &y[2], &r[2]);

		points = 0;

		// n(1) + n(2) + n (3) - n(1 && 2) - n(2 && 3) - n(3 && 1) + n(1 && 2 && 3) - (n(1 && 2) - n(1 && 2 && 3)) - (n(2 && 3) - n(1 && 2 && 3)) - (n(3 && 1) - n(1 && 2 && 3))
		for (int j = 0; j < 3; ++j)
			points += countLaticePoints1(x[j], y[j], r[j]);

		points -= 2 * (countLaticePoints2(x[0], y[0], r[0], x[1], y[1], r[1]) + countLaticePoints2(x[1], y[1], r[1], x[2], y[2], r[2]) + countLaticePoints2(x[0], y[0], r[0], x[2], y[2], r[2]));
		points += 4 * countLaticePoints3(x[0], y[0], r[0], x[1], y[1], r[1], x[2], y[2], r[2]);

		printf("%d\n", points);
	}

	return 0;
}


int countLaticePoints1(double x, double y, double r) {
	int num = 0;

	// calculate one quadrant
	for (int i = x; i <= x + r; ++i) {
		for (int j = y; j <= y + r; ++j) {
			if ((i - x) * (i - x) + (j - y) * (j - y) > r * r)
				continue;
			++num;
		}
	}

	// subtract repeated lattices
	num = 4 * num - 4 * r - 3;

	return num;
}

int countLaticePoints2(double x1, double y1, double r1, double x2, double y2, double r2) {
	int num = 0;

	for (int i = x1 - r1; i <= x1 + r1; ++i) {
		for (int j = y1 - r1; j <= y1 + r1; ++j) {
			if ((i - x1) * (i - x1) + (j - y1) * (j - y1) > r1 * r1 || (i - x2) * (i - x2) + (j - y2) * (j - y2) > r2 * r2)
				continue;
			++num;
		}
	}

	return num;
}

int countLaticePoints3(double x1, double y1, double r1, double x2, double y2, double r2, double x3, double y3, double r3) {
	int num = 0;

	for (int i = x1 - r1; i <= x1 + r1; ++i) {
		for (int j = y1 - r1; j <= y1 + r1; ++j) {
			if ((i - x1) * (i - x1) + (j - y1) * (j - y1) > r1 * r1 || (i - x2) * (i - x2) + (j - y2) * (j - y2) > r2 * r2 || (i - x3) * (i - x3) + (j - y3) * (j - y3) > r3 * r3)
				continue;
			++num;
		}
	}

	return num;
}
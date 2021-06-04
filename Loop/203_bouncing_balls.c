#include <stdio.h>

int main(int argc, char const *argv[])
{
	int X, Y, x1, y1, x2, y2, dx1, dy1, dx2, dy2, t;
	scanf("%d%d", &X, &Y);
	scanf("%d%d", &x1, &y1);
	scanf("%d%d", &x2, &y2);
	scanf("%d%d", &dx1, &dy1);
	scanf("%d%d", &dx2, &dy2);
	scanf("%d", &t);

	int tmp;

	for (int i = 0; i < t; ++i) {
		x1 += dx1;
		y1 += dy1;
		x2 += dx2;
		y2 += dy2;

		if (x1 == x2 && y1 == y2) {
			if (dx1 != dx2) {
				tmp = dx1;
				dx1 = dx2;
				dx2 = tmp;
			}

			if (dy1 != dy2) {
				tmp = dy1;
				dy1 = dy2;
				dy2 = tmp;
			}
		}

		if (x1 == 1 || x1 == X)
			dx1 = -dx1;
		if (y1 == 1 || y1 == Y)
			dy1 = -dy1;
		if (x2 == 1 || x2 == X)
			dx2 = -dx2;
		if (y2 == 1 || y2 == Y)
			dy2 = -dy2;
	}

	printf("%d\n", x1);
	printf("%d\n", y1);
	printf("%d\n", x2);
	printf("%d\n", y2);

	return 0;
}
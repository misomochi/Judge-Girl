#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int x1, y1, x2, y2, x3, y3, x4, y4;
	int a, b, c, d, e, f, tmp;

	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x1, &y1);
		scanf("%d%d", &x2, &y2);
		scanf("%d%d", &x3, &y3);
		scanf("%d%d", &x4, &y4);

		// (x2 - x1, y2 - y1) x (x3 - x1, y3 - y1)
		if ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) < 0) {
			tmp = x2;
			x2 = x3;
			x3 = tmp;

			tmp = y2;
			y2 = y3;
			y3 = tmp;
		}

		// v2 = (x2 - x1, y2 - y1) x (x4 - x1, y4 - y1)
		if ((x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1) < 0) {
			tmp = x2;
			x2 = x4;
			x4 = tmp;

			tmp = y2;
			y2 = y4;
			y4 = tmp;
		}

		// v3 = x3 - x1, y3 - y1) x (x4 - x1, y4 - y1)
		if ((x3 - x1) * (y4 - y1) - (y3 - y1) * (x4 - x1) < 0) {
			tmp = x3;
			x3 = x4;
			x4 = tmp;

			tmp = y3;
			y3 = y4;
			y4 = tmp;
		}

		a = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		b = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
		c = (x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4);
		d = (x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1);
		e = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
		f = (x2 - x4) * (x2 - x4) + (y2 - y4) * (y2 - y4);

		if (a == b && b == c && c == d && d == a) {
			if (e == f)
				printf("%s\n", "square");
			else
				printf("%s\n", "diamond");
		}
		else if (a == c && b == d && e == f)
			printf("%s\n", "rectangle");
		else
			printf("%s\n", "other");
	}

	return 0;
}
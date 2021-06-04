#include <stdio.h>

int main(int argc, char const *argv[])
{
	int M, N, x1, y1, e1, n1, f1, x2, y2, e2, n2, f2;
	scanf("%d%d", &M, &N);
	scanf("%d%d%d%d%d", &x1, &y1, &e1, &n1, &f1);
	scanf("%d%d%d%d%d", &x2, &y2, &e2, &n2, &f2);

	int t = (f1 > f2) ? f1 : f2;
	int dx1, dy1, dx2, dy2;

	for (int i = 1; i <= t; ++i) {
		//operation window of the 2 robots are independent
		if (i <= f1) {
			dx1 = (i % (n1 + e1) > 0 && i % (n1 + e1) <= n1) ? 0 : 1;
			dy1 = (i % (n1 + e1) > 0 && i % (n1 + e1) <= n1) ? 1 : 0;

			x1 = (x1 + dx1) % M;
			y1 = (y1 + dy1) % N;
		}

		if (i <= f2) {
			dx2 = (i % (n2 + e2) > 0 && i % (n2 + e2) <= e2) ? 1 : 0;
			dy2 = (i % (n2 + e2) > 0 && i % (n2 + e2) <= e2) ? 0 : 1;

			x2 = (x2 + dx2) % M;
			y2 = (y2 + dy2) % N;
		}

		if (x1 == x2 && y1 == y2) {
			printf("robots explode at time %d\n", i);
			break;
		}
	}

	if (x1 != x2 || y1 != y2)
		printf("robots will not explode\n");

	return 0;
}
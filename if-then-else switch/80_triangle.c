#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int x1, y1, x2, y2, x3, y3;
	int a, b, c;

	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x1, &y1);
		scanf("%d%d", &x2, &y2);
		scanf("%d%d", &x3, &y3);

		a = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		b = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
		c = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);

		if (a == b || b == c || c == a)
			printf("%s\n", "isosceles");
		else if (a + b == c || b + c == a || c + a == b)
			printf("%s\n", "right");
		else if (a + b < c || b + c < a || c + a < b)
			printf("%s\n", "obtuse");
		else
			printf("%s\n", "acute");
	}


	return 0;
}
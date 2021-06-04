#include <stdio.h>

void sortAndPrint(int, int, int);

int main(int argc, char const *argv[])
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	int d, e, f; // x^3 + a * x^2 + b * x + c = (x + d) * (x + e) * (x + f)

	if (c == 0)
		d = 0;
	else {
		for (int i = 1; i <= ((c > 0) ? c : -c); ++i) {
			if (i * i * i + a * i * i + b * i + c == 0)
				d = -i;
			else if (-i * i * i + a * i * i - b * i + c == 0)
				d = i;
			else
				continue;

			a -= d;
			b = c / d; // x^3 + a * x^2 + b * x + c = (x + d) * (x ^ 2 + (e + f) * x + e * f) = (x + d) * (x^2 + a' * x + b')
			break;
		}
	}

	if (b == 0) {
		e = 0;
		f = a;
	}
	else {
		for (int j = 0; j <= ((b > 0) ? b : -b); ++j) {
			if (j * j + a * j + b == 0)
				e = -j;
			else if (j * j - a * j + b == 0)
				e = j;
			else
				continue;

			f = a - e;
			break;
		}
	}

	sortAndPrint(d, e, f); // d <= e <= f

	return 0;
}

void sortAndPrint(int d, int e, int f) {
	int tmp;

	if (d > e) {
		tmp = d;
		d = e;
		e = tmp;
	}

	if (e > f) {
		tmp = e;
		e = f;
		f = tmp;

		if (d > e) {
			tmp = d;
			d = e;
			e = tmp;
		}
	}

	printf("%d %d %d\n", d, e, f);
}
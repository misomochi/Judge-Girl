#include <stdio.h>

int gcd(int, int);
void reduction(int *);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	if (n == 0)
		printf("1/1\n");

	int a, b, left[n * (n + 1) / 2][2], right[n * (n + 1) / 2][2];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			scanf("%d%d", &a, &b);

			if (a == b) {
				a = 1;
				b = 1;
			}

			a = (b == 0) ? 1 : a;
			b = (a == 0) ? 1 : b;

			left[i * (i + 1) / 2 + j][0] = a;
			left[i * (i + 1) / 2 + j][1] = a + b;
			right[i * (i + 1) / 2 + j][0] = b;
			right[i * (i + 1) / 2 + j][1] = a + b;
		}
	}

	int temp, numerator, denominator;
	for (int i = 1; i < n; ++i) {
		left[i * (i + 1) / 2][0] *= left[(i - 1) * i / 2][0];
		left[i * (i + 1) / 2][1] *= left[(i - 1) * i / 2][1];
		reduction(left[i * (i + 1) / 2]);

		right[i * (i + 1) / 2][0] *= left[(i - 1) * i / 2][0];
		right[i * (i + 1) / 2][1] *= left[(i - 1) * i / 2][1];
		reduction(right[i * (i + 1) / 2]);

		for (int j = 1; j < i; ++j) {
			numerator = right[(i - 1) * i / 2 + j - 1][0] * left[(i - 1) * i / 2 + j][1] + right[(i - 1) * i / 2 + j - 1][1] * left[(i - 1) * i / 2 + j][0];
			denominator = right[(i - 1) * i / 2 + j - 1][1] * left[(i - 1) * i / 2 + j][1];
			temp = gcd(numerator, denominator);
			numerator /= temp;
			denominator /= temp;

			left[i * (i + 1) / 2 + j][0] *= numerator;
			left[i * (i + 1) / 2 + j][1] *= denominator;
			reduction(left[i * (i + 1) / 2 + j]);

			right[i * (i + 1) / 2 + j][0] *= numerator;
			right[i * (i + 1) / 2 + j][1] *= denominator;
			reduction(right[i * (i + 1) / 2 + j]);
		}

		left[i * (i + 1) / 2 + i][0] *= right[(i - 1) * i / 2 + i - 1][0];
		left[i * (i + 1) / 2 + i][1] *= right[(i - 1) * i / 2 + i - 1][1];
		reduction(left[i * (i + 1) / 2 + i]);

		right[i * (i + 1) / 2 + i][0] *= right[(i - 1) * i / 2 + i - 1][0];
		right[i * (i + 1) / 2 + i][1] *= right[(i - 1) * i / 2 + i - 1][1];
		reduction(right[i * (i + 1) / 2 + i]);
	}

	int result[n + 1][2];
	for (int j = 0; j < n; ++j) {
		result[j][0] = (j == 0) ? left[(n - 1) * n / 2][0] : result[j][0] * left[(n - 1) * n / 2 + j][1] + result[j][1] * left[(n - 1) * n / 2 + j][0];
		result[j][1] = (j == 0) ? left[(n - 1) * n / 2][1] : result[j][1] * left[(n - 1) * n / 2 + j][1];
		reduction(result[j]);

		printf("%d/%d\n", result[j][0], result[j][1]);

		result[j + 1][0] = right[(n - 1) * n / 2 + j][0];
		result[j + 1][1] = right[(n - 1) * n / 2 + j][1];
		reduction(result[j + 1]);

		if (j == n - 1)
			printf("%d/%d\n", result[j + 1][0], result[j + 1][1]);
	}

	return 0;
}

// Euclidean Algorithm
int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b % a, a);
}

void reduction(int *a) {
	int temp = gcd(a[0], a[1]);

	a[0] /= temp;
	a[1] /= temp;

	return;
}
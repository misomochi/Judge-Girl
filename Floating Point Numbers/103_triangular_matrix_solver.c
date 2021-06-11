#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	double A[n][n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%lf", &(A[i][j]));

	double y[n];
	for (int i = 0; i < n; ++i)
		scanf("%lf", &(y[i]));

	// back distribution
	double x[n];
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			y[i] -= A[i][j] * x[j];
		}
		x[i] = y[i] / A[i][i];
	}

	for (int i = 0; i < n; ++i)
		printf("%f\n", x[i]);

	return 0;
}
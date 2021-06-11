#include <stdio.h>

#define PI 3.1415926

int main(int argc, char const *argv[])
{
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);

	double area = 0.75 * PI * c * c;

	area += (c > a) ? 0.25 * PI * (c - a) * (c - a) : 0;
	area += (c > b) ? 0.25 * PI * (c - b) * (c - b) : 0;

	printf("%f\n", area);

	return 0;
}
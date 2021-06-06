#include <stdio.h>

int min(int, int);
int max(int, int);
int min3(int, int, int);
int max3(int, int, int);

int main(int argc, char const *argv[])
{
	int r[3], t[3], l[3], b[3];
	for (int i = 0; i < 3; ++i)
		scanf("%d%d%d%d", &(l[i]), &(b[i]), &(r[i]), &(t[i]));

	int area = 0;
	for (int i = 0; i < 3; ++i)
		area += (r[i] - l[i]) * (t[i] - b[i]);

	area -= ((min(r[0], r[1]) > max(l[0], l[1])) && (min(t[0], t[1]) > max(b[0], b[1]))) ? (min(r[0], r[1]) - max(l[0], l[1])) * (min(t[0], t[1]) - max(b[0], b[1])) : 0;
	area -= ((min(r[1], r[2]) > max(l[1], l[2])) && (min(t[1], t[2]) > max(b[1], b[2]))) ? (min(r[1], r[2]) - max(l[1], l[2])) * (min(t[1], t[2]) - max(b[1], b[2])) : 0;
	area -= ((min(r[2], r[0]) > max(l[2], l[0])) && (min(t[2], t[0]) > max(b[2], b[0]))) ? (min(r[2], r[0]) - max(l[2], l[0])) * (min(t[2], t[0]) - max(b[2], b[0])) : 0;

	area += ((min3(r[0], r[1], r[2]) > max3(l[0], l[1], l[2])) && (min3(t[0], t[1], t[2]) > max3(b[0], b[1], b[2]))) ? (min3(r[0], r[1], r[2]) - max3(l[0], l[1], l[2])) * (min3(t[0], t[1], t[2]) - max3(b[0], b[1], b[2])) : 0;

	printf("%d\n", area);

	return 0;
}

int min(int a, int b) {
	return (a > b) ? b : a;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int min3(int a, int b, int c) {
	return min(min(a, b), min(b, c));
}

int max3 (int a, int b, int c) {
	return max(max(a, b), max(b, c));
}
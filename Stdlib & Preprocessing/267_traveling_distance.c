#include <stdio.h>
#include <stdlib.h>

#define MAXCITIES 100000

typedef struct city {
	int x;
	int y;
} City;

int compare(const void *, const void *);
int distance(City [], int);

int main(int argc, char const *argv[])
{
	City coordinates[MAXCITIES];
	int count = 0;

	while(scanf("%d%d", &(coordinates[count].x), &(coordinates[count].y)) != EOF)
		++count;

	qsort(coordinates, count, sizeof(City), compare);

	printf("%u\n", distance(coordinates, count));

	return 0;
}

int compare(const void *a, const void *b) {
	City *c1 = (City *)a;
	City *c2 = (City *)b;

	int d1 = c1 -> x * c1 -> x + c1 -> y * c1 -> y;
	int d2 = c2 -> x * c2 -> x + c2 -> y * c2 -> y;

	if (d1 != d2)
		return d1 - d2;
	else {
		if (c1 -> x != c2 -> x)
			return c1 -> x - c2 -> x;
		else
			return c1 -> y - c2 -> y;
	}
}

int distance(City coordinates[], int n) {
	int d = coordinates[0].x * coordinates[0].x + coordinates[0].y * coordinates[0].y;

	for (int i = 1; i < n; ++i)
		d += (coordinates[i].x - coordinates[i - 1].x) * (coordinates[i].x - coordinates[i - 1].x) + (coordinates[i].y - coordinates[i - 1].y) * (coordinates[i].y - coordinates[i - 1].y);

	return d;
}
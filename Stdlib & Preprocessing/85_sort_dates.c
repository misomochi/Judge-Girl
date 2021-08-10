#include <stdio.h>
#include <stdlib.h>

typedef struct date {
	unsigned int year;
	unsigned short month;
	unsigned short day;
} Date;

int compare(const void *, const void *);
void print(Date [], int);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	Date dates[n];
	for (int i = 0; i < n; ++i)
		scanf("%u%hu%hu", &(dates[i].year), &(dates[i].month), &(dates[i].day));

	qsort(dates, n, sizeof(Date), compare);
	print(dates, n);

	return 0;
}

int compare(const void *a, const void *b) {
	Date *d1 = (Date *)a;
	Date *d2 = (Date *)b;

	if (d1 -> year != d2 -> year)
		return (d1 -> year - d2 -> year);
	else
		return (d1 -> month != d2 -> month) ? (d1 -> month - d2 -> month) : (d1 -> day - d2 -> day);
}

void print(Date dates[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%u %u %u\n", dates[i].year, dates[i].month, dates[i].day);

	return;
}
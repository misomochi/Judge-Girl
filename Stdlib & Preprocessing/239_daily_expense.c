#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGLENGTH 32
#define EXPENSESCOUNT 10000

typedef struct expenses {
	unsigned short year;
	unsigned short month;
	unsigned short day;
	char category[32];
	unsigned int amount;
} Expenses;

int compare(const void *, const void *);
void compare_and_add(Expenses, Expenses[], int *);
void print(Expenses [], int);

int main(int argc, char const *argv[])
{	
	Expenses records[EXPENSESCOUNT], temp;
	int count = 0;

	while(scanf("%hu%hu%hu%s%u", &(temp.year), &(temp.month), &(temp.day), temp.category, &(temp.amount)) != EOF)
		compare_and_add(temp, records, &count);

	qsort(records, count, sizeof(Expenses), compare);
	print(records, count);

	return 0;
}

int compare(const void *a, const void *b) {
	Expenses *r1 = (Expenses *)a;
	Expenses *r2 = (Expenses *)b;

	if (r1 -> year != r2 -> year)
		return (r1 -> year - r2 -> year);
	else {
		if (r1 -> month != r2 -> month)
			return (r1 -> month - r2 -> month);
		else
			return (r1 -> day != r2 -> day) ? (r1 -> day - r2 -> day) : strncmp(r1 -> category, r2 -> category, STRINGLENGTH);
	}
}

void compare_and_add(Expenses e, Expenses records[], int *n) {
	for (int i = 0; i < *n; ++i) {
		if (e.year != records[i].year || e.month != records[i].month || e.day != records[i].day || strncmp(e.category, records[i].category, STRINGLENGTH) != 0)
			continue;

		records[i].amount += e.amount;
		return;
	}

	records[*n].year = e.year;
	records[*n].month = e.month;
	records[*n].day = e.day;
	strncpy(records[*n].category, e.category, STRINGLENGTH);
	records[*n].amount = e.amount;
	++*n;

	return;
}

void print(Expenses records[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%hu %hu %hu %s %u\n", records[i].year, records[i].month, records[i].day, records[i].category, records[i].amount);

	return;
}
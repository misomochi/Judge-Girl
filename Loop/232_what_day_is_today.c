#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int);

int main(int argc, char const *argv[])
{
	int year, day;
	scanf("%d%d", &year, &day);

	bool leap = isLeapYear(year);

	int n;
	scanf("%d", &n);

	int month, date, count;

	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &month, &date);

		switch (month) {
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				if (date < 1 || date > 31) {
					printf("%d\n", -2);
					continue;
				}
				break;
			case 4: case 6: case 9: case 11:
				if (date < 1 || date > 30) {
					printf("%d\n", -2);
					continue;
				}
				break;
			case 2:
				if (date < 1 || (date > 28 && !leap) || (date > 29 && leap)) {
					printf("%d\n", -2);
					continue;
				}
				break;
			default:
				printf("%d\n", -1);
				continue;
		}

		count = 0;

		for (int m = 0; m < month; ++m) {
			switch (m) {
				case 1: case 3: case 5: case 7: case 8: case 10: case 12:
					count += 31;
					break;
				case 4: case 6: case 9: case 11:
					count += 30;
					break;
				case 2:
					count += (leap) ? 29 : 28;
					break;
				default:
					count += 0;
			}
		}

		printf("%d\n", (day + (date - 1 + count) % 7) % 7);
	}

	return 0;
}

bool isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;

	return false;
}
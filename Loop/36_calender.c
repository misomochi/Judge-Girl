#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int);

int main(int argc, char const *argv[])
{
	int year, month, day;
	scanf("%d%d%d", &year, &month, &day);

	if (month < 1 || month > 12 || day < 0 || day > 7)
		printf("invalid\n");
	else {
		printf(" Su Mo Tu We Th Fr Sa\n");
		printf("=====================\n");

		int count = 0;

		for (int i = 0; i < day; ++i) {
			printf("   ");
			++count;
		}

		switch (month) {
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				for (int i = 1; i <= 31; ++i) {
					printf("%3d", i);
					++count;

					if (count % 7 == 0)
						printf("\n");
				}
				break;
			case 4: case 6: case 9: case 11:
				for (int i = 1; i <= 30; ++i) {
					printf("%3d", i);
					++count;

					if (count % 7 == 0)
						printf("\n");
				}
				break;
			case 2:
				for (int i = 1; i <= ((isLeapYear(year)) ? 29 : 28); ++i) {
					printf("%3d", i);
					++count;

					if (count % 7 == 0)
						printf("\n");
				}
				break;
			default:
				printf("invalid\n");
		}

		if (count % 7 != 0)
			printf("\n");

		printf("=====================\n");
	}
	return 0;
}

bool isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;

	return false;
}
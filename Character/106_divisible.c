#include <stdio.h>

#define ARRAYSIZE 1000

int main(int argc, char const *argv[])
{
	char num[ARRAYSIZE];
	int length, even_sum, odd_sum, difference;

	while (scanf("%s", num) != EOF) {
		if (num[0] == '-')
			break;

		length = 0;
		even_sum = 0;
		odd_sum = 0;

		while (num[length] != '\0')
			++length;

		if ((num[length - 1] - '0') % 2 == 0)
			printf("yes ");
		else
			printf("no ");

		for (int i = 0; i < length; ++i) {
			switch (i % 2) {
				case 0:
					even_sum += (num[i] - '0');
					break;
				case 1:
					odd_sum += (num[i] - '0');
					break;
				default:
					continue;
			}
		}

		if ((even_sum + odd_sum) % 3 == 0)
			printf("yes ");
		else
			printf("no ");

		if (num[length - 1] == '0' || num[length - 1] == '5')
			printf("yes ");
		else
			printf("no ");

		difference = (even_sum > odd_sum) ? (even_sum - odd_sum) : (odd_sum - even_sum);

		if (difference % 11 == 0)
			printf("yes\n");
		else
			printf("no\n");
		
	}

	return 0;
}
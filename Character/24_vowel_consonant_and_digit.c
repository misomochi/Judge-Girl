#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	char c;
	int digits = 0, letters = 0, vowels = 0, consonants = 0;

	while (scanf("%c", &c) != EOF) {
		if (!isalnum(c))
			continue;

		if (isdigit(c))
			++digits;

		if (isalpha(c)) {
			++letters;

			c = tolower(c);

			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				++vowels;
			else
				++consonants;
		}
	}

	printf("%d %d %d %d\n", digits, letters, vowels, consonants);

	return 0;
}
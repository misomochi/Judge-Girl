#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	char c, alpha[26] = {0};
	while (scanf("%c", &c) != EOF) {
		if (isalpha(c)) {
			c = tolower(c);
			++alpha[c - 'a'];
		}
	}

	for (int i = 0; i < 26; ++i)
		printf("%d\n", alpha[i]);

	return 0;
}
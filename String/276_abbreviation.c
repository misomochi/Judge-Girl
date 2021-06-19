#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRINGSIZE 128

int main(int argc, char const *argv[])
{
	char s[STRINGSIZE];

	while (scanf("%s", s) != EOF) {
		if (strcmp(s, "of") == 0 || strcmp(s, "and") == 0 || strcmp(s, "the") == 0 || strcmp(s, "at") == 0)
			continue;

		if (strcmp(s, "of.") == 0 || strcmp(s, "and.") == 0 || strcmp(s, "the.") == 0 || strcmp(s, "at.") == 0) {
			printf("\n");
			continue;
		}

		printf("%c", toupper(*s));

		if (strrchr(s, '.') != NULL)
			printf("\n");
	}

	return 0;
}
#include <stdio.h>
#include <ctype.h>

#define STRINGSIZE 100

int main(int argc, char const *argv[])
{
	char s[STRINGSIZE];
	char *start, *end;

	while (fgets(s, STRINGSIZE, stdin)) {
	    start = s;
	    end = s + strlen(s) - 1;
	    
		while (isspace(*start))
			++start;

		while (isspace(*end))
			--end;

		for (char *p = start; p <= end; ++p)
			printf("%c", *p);

		printf("\n");
	}

	return 0;
}

#include <stdio.h>
#include <string.h>

#define STRINGSIZE 128

int main(int argc, char const *argv[])
{
	char temp[STRINGSIZE], s[STRINGSIZE];

	scanf("%s", s);

	while (scanf("%s", temp) != EOF) {
		for (int i = strlen(temp); i >= 0; --i) {
			if (strncmp(s + strlen(s) - i, temp, i) != 0)
				continue;

			strcat(s, temp + i);
			break;
		}
	}

	printf("%s\n", s);

	return 0;
}
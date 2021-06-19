#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STRINGSIZE 80

bool sameLength(char*, char*);
bool diffLength(char*, char*);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	char s1[STRINGSIZE], s2[STRINGSIZE];
	for (int i = 0; i < n; ++i) {
		scanf("%s%s", s1, s2);

		if (strncmp(s1, s2, STRINGSIZE) == 0 || sameLength(s1, s2) || diffLength(s1, s2))
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}

bool sameLength(char *s1, char *s2) {
	int l = strlen(s1), count = 0;

	if (l != strlen(s2))
		return false;

	for (int i = 0; i < strlen(s1) - 1; ++i) {
		if (s1[i] == s2[i])
			continue;

		if (s1[i] == s2[i + 1] && s1[i + 1] == s2[i]) {
			++count;
			++i;
		}
		else
			return false;
	}

	return count == 1;
}

bool diffLength(char *s1, char *s2) {
	int l1 = strlen(s1), l2 = strlen(s2);

	if (l1 == l2)
		return false;

	if (l1 < l2) {
		if (l2 - l1 != 1)
			return false;

		for (int i = 0; i < l1; ++i) {
			if (s1[i] == s2[i])
				continue;

			// s1[i] != s2[i]
			if (s1[i] == s2[i + 1])
				continue;
			else
				return false;
		}
	} else {
		if (l1 - l2 != 1)
			return false;

		for (int i = 0; i < l2; ++i) {
			if (s1[i] == s2[i])
				continue;

			// s[i] != s2[i]
			if (s1[i + 1] == s2[i])
				continue;
			else
				return false;
		}
	}

	return true;
}
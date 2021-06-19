#include <stdio.h>
#include <stdlib.h> // qsort
#include <string.h>

#define MAX_INGREDIENTS 10
#define STRINGSIZE 65 // 64 characters + '\0'

int getIndex(char*, char [][STRINGSIZE], int);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	char food[n][STRINGSIZE], ingredients[n][MAX_INGREDIENTS][STRINGSIZE];
	int count[n];

	for (int i = 0; i < n; ++i) {
		scanf("%s", food[i]);
		scanf("%d", &(count[i]));

		for (int j = 0; j < count[i]; ++j)
			scanf("%s", ingredients[i][j]);
	}

	int m;
	scanf("%d", &m);

	char f1[STRINGSIZE], f2[STRINGSIZE], common[MAX_INGREDIENTS][STRINGSIZE];
	int i1, i2, size;

	for (int i = 0; i < m; ++i) {
		scanf("%s%s", f1, f2);

		i1 = getIndex(f1, food, n);
		i2 = getIndex(f2, food, n);
		size = 0;

		for (int j = 0; j < count[i1]; ++j) {
			for (int k = 0; k < count[i2]; ++k) {
				if (strncmp(ingredients[i1][j], ingredients[i2][k], STRINGSIZE) != 0)
					continue;

				strncpy(common[size], ingredients[i1][j], STRINGSIZE);
				++size;
				break;
			}
		}

		if (size == 0)
			printf("nothing\n");
		else {
			qsort(common, size, STRINGSIZE, strcmp);

			for (int i = 0; i < size; ++i) {
				printf("%s", common[i]);
				(i == size - 1) ? printf("\n") : printf(" ");
			}
		}
	}

	return 0;
}

int getIndex(char *f, char s[][STRINGSIZE], int n) {
	for (int i = 0; i < n; ++i) {
		if (strncmp(f, s[i], STRINGSIZE) != 0)
			continue;

		return i;
	}
}
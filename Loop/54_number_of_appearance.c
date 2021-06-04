#include <stdio.h>

int main(int argc, char const *argv[])
{
	char m[7], n[2];
	scanf("%s%s", &n, &m);

	int count = 0;

	for (int i = 0; i < 6; ++i) {
		if (m[i] != n[0])
			continue;
		else {
			if (m[i + 1] == n[1])
				++count;
		}
	}

	printf("%d\n", count);

	return 0;
}
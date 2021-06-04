#include <stdio.h>

int main(int argc, char const *argv[])
{
	char n1[4], n2[4];
	scanf("%s%s", &n1, &n2);

	int A = 0, B = 0;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (n1[i] != n2[j])
				continue;
			else {
				if (i == j)
					++A;
				else
					++B;
			}
		}
	}

	printf("%dA%dB\n", A, B);

	return 0;
}
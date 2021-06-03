#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x, score = 0;
	scanf("%d", &x);

	if (x <= 0)
		score = -100;
	else {
		if (x % 3 == 0)
			score += 3;

		if (x % 5 == 0)
			score += 5;

		score += (x > 100 && x <= 200) ? 50 : -50;
	}

	printf("%d\n", score);

	return 0;
}
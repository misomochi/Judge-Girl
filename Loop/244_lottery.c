#include <stdio.h>

int main(int argc, char const *argv[])
{
	int special[3], first[3];
	scanf("%d%d%d", &special[0], &special[1], &special[2]);
	scanf("%d%d%d", &first[0], &first[1], &first[2]);

	int lottery, sum = 0;

	while (scanf("%d", &lottery) != EOF) {
		if (lottery == special[0] || lottery == special[1] || lottery == special[2]) {
			sum += 2000000;
			continue;
		}

		if (lottery == first[0] || lottery == first[1] || lottery == first[2]) {
			sum += 200000;
			continue;
		}

		lottery %= 10000000;

		if (lottery == first[0] % 10000000 || lottery == first[1] % 10000000 || lottery == first[2] % 10000000) {
			sum += 40000;
			continue;
		}

		lottery %= 1000000;

		if (lottery == first[0] % 1000000 || lottery == first[1] % 1000000 || lottery == first[2] % 1000000) {
			sum += 10000;
			continue;
		}

		lottery %= 100000;

		if (lottery == first[0] % 100000 || lottery == first[1] % 100000 || lottery == first[2] % 100000) {
			sum += 4000;
			continue;
		}

		lottery %= 10000;

		if (lottery == first[0] % 10000 || lottery == first[1] % 10000 || lottery == first[2] % 10000) {
			sum += 1000;
			continue;
		}

		lottery %= 1000;

		if (lottery == first[0] % 1000 || lottery == first[1] % 1000 || lottery == first[2] % 1000) {
			sum += 200;
			continue;
		}
	}

	printf("%d\n", sum);

	return 0;
}
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int h, w, d;
	scanf("%d%d%d", &h, &w, &d);

	int area = 2 * (h * w + w * d + d * h);
	int volume = h * w * d;

	printf("%d\n", area);
	printf("%d\n", volume);

	return 0;
}
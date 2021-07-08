#include <stdio.h>

#define STRINGLENGTH 200
#define ARRAYSIZE 65536

int main(int argc, char const *argv[])
{
	char fileName[STRINGLENGTH];
	scanf("%s", fileName);

	FILE *fp = fopen(fileName, "rb");

	int n;
	fread(&n, sizeof(int), 1, fp);

	short num;
	int frequency[ARRAYSIZE] = {0};
	for (int i = 0; i < n; ++i) {
		fread(&num, sizeof(short), 1, fp);
		++frequency[num + 32768];
	}

	fclose(fp);

	short target;
	int count = 0;
	for (int i = 0; i < ARRAYSIZE; ++i) {
		if (frequency[i] == 0 || frequency[i] < count)
			continue;

		target = i - 32768;
		count = frequency[i];
	}

	printf("%d\n%d\n", target, count);

	return 0;
}
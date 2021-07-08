#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *in = fopen("test", "rb");
	FILE *out = fopen("test.enc", "wb");

	int fileLength;
	fseek(in, 0, SEEK_END);
	fileLength = ftell(in); // returns a positive integer indicating the byte offset from the beginning of an open file
	rewind(in); // fseek(in, 0, SEEK_SET);

	char buf[fileLength];
	fread(buf, sizeof(char), fileLength, in);

	int key;
	scanf("%d", &key);

	for (int i = 0; i < fileLength; ++i)
		buf[i] ^= key;

	fwrite(buf, sizeof(char), fileLength, out);

	fclose(out);
	fclose(in);

	return 0;
}
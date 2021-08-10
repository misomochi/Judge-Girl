#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTENCELENGTH 64
#define SENTENCECOUNT 64

typedef struct sentence {
	char string[SENTENCELENGTH];
} Sentence;

int compare(const void *, const void *);
void print(Sentence [], int);

int main(int argc, char const *argv[])
{
	Sentence sentences[SENTENCECOUNT];
	int count = 0;

	while (fgets(sentences[count].string, SENTENCELENGTH, stdin))
		++count;

	qsort(sentences, count, sizeof(Sentence), compare);
	print(sentences, count);

	return 0;
}

int compare(const void *a, const void *b) {
	Sentence *s1 = (Sentence *)a;
	Sentence *s2 = (Sentence *)b;

	return strncmp(s1 -> string, s2 -> string, SENTENCELENGTH);
}

void print(Sentence s[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%s", s[i].string);

	return;
}
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool isPalindrome(int, int, int *);

int main(int argc, char const *argv[])
{
	int seq[MAX_SIZE], index = 0;
	while (scanf("%d", &(seq[index])) != EOF)
		++index;

	int length = 0, start = 0, end = 0;
	for (int i = 0; i < index; ++i) {
		for (int j = i; j < index; ++j) {
			if (!isPalindrome(i, j, seq))
				continue;

			for (int k = j + 1; k < index; ++k) {
				if (!isPalindrome(j + 1, k, seq))
					continue;

				if ((k - i + 1) >= length) {
					length = k - i + 1;
					start = i;
					end = k;
				}
			}
		}
	}

	for (int i = start; i <= end; ++i) {
		printf("%d", seq[i]);
		(i == end) ? printf("\n") : printf(" ");
	}

	return 0;
}

bool isPalindrome(int start, int end, int *seq) {
	while(seq[start] == seq[end] && start < end) {
		++start;
		--end;
	}

	return (start >= end) ? true : false;
}
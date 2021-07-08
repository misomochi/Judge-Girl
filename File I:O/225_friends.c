#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NAMESIZE 32

typedef struct person {
    unsigned int id;
    char name[32];
} Person;

typedef struct friends {
    unsigned id1;
    unsigned id2;
} Friends;

int findID(char *, Person [], int);
bool areFriends(int, int, Friends [], int);

int main(int argc, char const *argv[])
{
	FILE *fp = fopen("friends", "rb");

	int p;
	fread(&p, sizeof(int), 1, fp);

	Person person[p];
	for (int i = 0; i < p; ++i)
		fread(&(person[i]), sizeof(Person), 1, fp);

	int f;
	fread(&f, sizeof(int), 1, fp);

	Friends friends[f];
	for (int i = 0; i < f; ++i)
		fread(&(friends[i]), sizeof(Friends), 1, fp);

	fclose(fp);

	char name1[NAMESIZE], name2[NAMESIZE];
	while (scanf("%s%s", name1, name2) == 2) {
		unsigned id1 = findID(name1, person, p);
		unsigned id2 = findID(name2, person, p);

		areFriends(id1, id2, friends, f) ? printf("yes\n") : printf("no\n");
	}

	return 0;
}

int findID(char *name, Person p[], int n) {
	for (int i = 0; i < n; ++i) {
		if (strncmp(name, p[i].name, NAMESIZE) != 0)
			continue;

		return p[i].id;
	}

	return -1;
}

bool areFriends(int id1, int id2, Friends f[], int n) {
	for (int i = 0; i < n; ++i) {
		if ((id1 == f[i].id1 && id2 == f[i].id2) || (id1 == f[i].id2 && id2 == f[i].id1))
			return true;
	}

	return false;
}
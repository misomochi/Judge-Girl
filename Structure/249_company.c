#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define NAMESIZE 32

typedef struct employee {
  int id;
  char first_name[NAMESIZE];
  char last_name[NAMESIZE];
  int boss_id;
} Employee;

int findID(Employee *[], int, char *, char *);
int findBoss(Employee *[], int, int);
int findLeader(Employee *[], int, int);
bool isBoss(Employee *[], int, int, int);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	Employee employees[n], *employees_ptr[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &(employees[i].id));
		scanf("%s", employees[i].first_name);
		scanf("%s", employees[i].last_name);
		scanf("%d", &(employees[i].boss_id));

		employees_ptr[i] = &employees[i];
	}

	int m;
	scanf("%d", &m);

	char f1[NAMESIZE], l1[NAMESIZE], f2[NAMESIZE], l2[NAMESIZE];
	int id1, id2;

	for (int i = 0; i < m; ++i) {
		scanf("%s%s%s%s", f1, l1, f2, l2);

		id1 = findID(employees_ptr, n, f1, l1);
		id2 = findID(employees_ptr, n, f2, l2);

		assert((id1 != -1) && (id2 != -1));

		if (isBoss(employees_ptr, n, id1, id2))
			printf("subordinate\n");
		else if (isBoss(employees_ptr, n, id2, id1))
			printf("supervisor\n");
		else if (findLeader(employees_ptr, n, id1) == findLeader(employees_ptr, n, id2))
			printf("colleague\n");
		else
			printf("unrelated\n");
	}

	return 0;
}

int findID (Employee *employees_ptr[], int size, char *first, char *last) {
	for (int i = 0; i < size; ++i) {
		if (strncmp(first, employees_ptr[i] -> first_name, NAMESIZE) != 0 || strncmp(last, employees_ptr[i] -> last_name, NAMESIZE) != 0)
			continue;

		return employees_ptr[i] -> id;
	}

	return -1;
}

int findBoss(Employee *employees_ptr[], int size, int id) {
	for (int i = 0; i < size; ++i) {
		if (employees_ptr[i] -> id != id)
			continue;

		return employees_ptr[i] -> boss_id;
	}
}

int findLeader(Employee *employees_ptr[], int size, int id) {
	int boss = findBoss(employees_ptr, size, id);

	return (id == boss) ? id : findLeader(employees_ptr, size, boss);
}

bool isBoss (Employee *employees_ptr[], int size, int id1, int id2) {
	int boss = findBoss(employees_ptr, size, id1);

	return (id1 == id2) ? true : ((id1 == boss) ? false : isBoss(employees_ptr, size, boss, id2));
}
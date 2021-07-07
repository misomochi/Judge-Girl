#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRINGSIZE 80
#define FIELDNUM 9
#define OPERATORSIZE 3

enum fields {LASTNAME, FIRSTNAME, ID, SALARY, AGE};
enum operators {EQL, NEQ, GREATER, LESS};

typedef struct data {
	char lastname[STRINGSIZE];
	char firstname[STRINGSIZE];
	char id[STRINGSIZE];
	int salary;
	int age;
} Data;

int stringToIndex(char *);
int operatorToIndex(char *);
void printField(Data *, int []);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	Data database[n], *database_ptr[n];
	for (int i = 0; i < n; ++i) {
		scanf("%s", database[i].lastname);
		scanf("%s", database[i].firstname);
		scanf("%s", database[i].id);
		scanf("%d", &(database[i].salary));
		scanf("%d", &(database[i].age));


		database_ptr[i] = &database[i];
	}

	int m;
	scanf("%d", &m);

	char temp[STRINGSIZE], operand1[STRINGSIZE], operator[OPERATORSIZE], operand2[STRINGSIZE];
	int field[FIELDNUM];

	for (int i = 0; i < m; ++i) {
		scanf("%s", temp); // select

		int count = 0;
		while (scanf("%s", temp) != EOF && strncmp(temp, "where", STRINGSIZE) != 0) {
			field[count] = stringToIndex(temp);
			++count;
		}

		field[count] = -1; //end of field

		scanf("%s%s%s", operand1, operator, operand2);

		switch (stringToIndex(operand1)) {
			case LASTNAME:
				switch (operatorToIndex(operator)) {
					case EQL:
						for (int i = 0; i < n; ++i) {
							if (strncmp(operand2, database_ptr[i] -> lastname, STRINGSIZE) != 0)
								continue;

							printField(database_ptr[i], field);
						}
						break;
					case NEQ:
						for (int i = 0; i < n; ++i) {
							if (strncmp(operand2, database_ptr[i] -> lastname, STRINGSIZE) == 0)
								continue;

							printField(database_ptr[i], field);
						}
						break;
					default:
						continue;
				}
				break;
			case FIRSTNAME:
				switch (operatorToIndex(operator)) {
					case EQL:
						for (int i = 0; i < n; ++i) {
							if (strncmp(operand2, database_ptr[i] -> firstname, STRINGSIZE) != 0)
								continue;

							printField(database_ptr[i], field);
						}
						break;
					case NEQ:
						for (int i = 0; i < n; ++i) {
							if (strncmp(operand2, database_ptr[i] -> firstname, STRINGSIZE) == 0)
								continue;

							printField(database_ptr[i], field);
						}
						break;
					default:
						continue;
				}
				break;
			case ID:
				switch (operatorToIndex(operator)) {
					case EQL:
						for (int i = 0; i < n; ++i) {
							if (strncmp(operand2, database_ptr[i] -> id, STRINGSIZE) != 0)
								continue;

							printField(database_ptr[i], field);
						}
						break;
					case NEQ:
						for (int i = 0; i < n; ++i) {
							if (strncmp(operand2, database_ptr[i] -> id, STRINGSIZE) == 0)
								continue;

							printField(database_ptr[i], field);
						}
						break;
					default:
						continue;
				}
				break;
			case SALARY:
				switch (operatorToIndex(operator)) {
					case EQL:
						for (int i = 0; i < n; ++i) {
							if (database_ptr[i] -> salary != atoi(operand2))
								continue;

							printField(database_ptr[i], field);
						}
						break;
					case GREATER:
						for (int i = 0; i < n; ++i) {
							if (database_ptr[i] -> salary <= atoi(operand2))
								continue;

							printField(database_ptr[i], field);
						}
						break;
					case LESS:
						for (int i = 0; i < n; ++i) {
							if (database_ptr[i] -> salary >= atoi(operand2))
								continue;

							printField(database_ptr[i], field);
						}
						break;
					default:
						continue;
				}
				break;
			case AGE:
				switch (operatorToIndex(operator)) {
					case EQL:
						for (int i = 0; i < n; ++i) {
							if (database_ptr[i] -> age != atoi(operand2))
								continue;

							printField(database_ptr[i], field);
						}
						break;
					case GREATER:
						for (int i = 0; i < n; ++i) {
							if (database_ptr[i] -> age <= atoi(operand2))
								continue;

							printField(database_ptr[i], field);
						}
						break;
					case LESS:
						for (int i = 0; i < n; ++i) {
							if (database_ptr[i] -> age >= atoi(operand2))
								continue;

							printField(database_ptr[i], field);
						}
						break;
					default:
						continue;
				}
				break;
			default:
				continue;
		}
	}

	return 0;
}

int stringToIndex(char *field) {
	if (!strncmp(field, "lastname", STRINGSIZE))
		return LASTNAME;
	else if (!strncmp(field, "firstname", STRINGSIZE))
		return FIRSTNAME;
	else if (!strncmp(field, "ID", STRINGSIZE))
		return ID;
	else if (!strncmp(field, "salary", STRINGSIZE))
		return SALARY;
	else if (!strncmp(field, "age", STRINGSIZE))
		return AGE;
	else
		return -1;
}

int operatorToIndex(char *operator) {
	if (!strncmp(operator, "==", OPERATORSIZE))
		return EQL;
	else if (!strncmp(operator, "!=", OPERATORSIZE))
		return NEQ;
	else if (!strncmp(operator, ">", OPERATORSIZE))
		return GREATER;
	else if (!strncmp(operator, "<", OPERATORSIZE))
		return LESS;
	else
		return -1;
}

void printField(Data *database_ptr, int field[]) {
	int *p = field;

	while (*p != -1) {
		switch (*p) {
			case LASTNAME:
				printf("%s", database_ptr -> lastname);
				break;
			case FIRSTNAME:
				printf("%s", database_ptr -> firstname);
				break;
			case ID:
				printf("%s", database_ptr -> id);
				break;
			case SALARY:
				printf("%d", database_ptr -> salary);
				break;
			case AGE:
				printf("%d", database_ptr -> age);
				break;
			default:
				continue;
		}

		(*(++p) != -1) ? printf(" ") : printf("\n");
	}
}
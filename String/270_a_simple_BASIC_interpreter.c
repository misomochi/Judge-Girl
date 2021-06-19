#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define STRINGSIZE 8
#define VAR 100
#define LINE 1000

enum keywords {GOTO, IF, PRINT, STOP, ASSIGN};
enum operators {EQL, NEQ, GRT, LSS, GEQ, LEQ, ADD, SUB, MULT, DIV, MOD};

int getIndex(char*, char* []);
int arithmetic(int, int, int);
bool logic(int, int, int);
void readVariable(char [][STRINGSIZE], int [], char* []);
void processCode(char* [], int [], int [], int [], int [], int [], int []);
void exeCode(int[], int [], int [], int [], int [], int [], int []);

int main(int argc, char const *argv[])
{
	char varName[VAR][STRINGSIZE], *varNameTable[VAR];
	int varValue[VAR];

	readVariable(varName, varValue, varNameTable); // Line 1

	int code[LINE], gotoLine[LINE], target[LINE], operand1[LINE], operand2[LINE], operator[LINE];

	processCode(varNameTable, code, gotoLine, target, operand1, operand2, operator);
	exeCode(varValue, code, gotoLine, target, operand1, operand2, operator);

	return 0;
}

int getIndex(char *f, char *s[]) {
	int index = 0;

	while (s[index] != NULL) {
		if (strncmp(f, s[index], STRINGSIZE) != 0) {
			++index;
			continue;
		}

		return index;
	}

	return -1;
}

int arithmetic(int a, int b, int operator) {
	switch (operator) {
		case ADD:
			return a + b;
		case SUB:
			return a - b;
		case MULT:
			return a * b;
		case DIV:
			return a / b;
		case MOD:
			return a % b;
		default:
			return 0;
	}
}

bool logic(int a, int b, int comparator) {
	switch (comparator) {
		case EQL:
			return a == b;
		case NEQ:
			return a != b;
		case GRT:
			return a > b;
		case LSS:
			return a < b;
		case GEQ:
			return a >= b;
		case LEQ:
			return a <= b;
		default:
			return false;
	}
}

void readVariable(char varName[][STRINGSIZE], int varValue[], char *varNameTable[]) {
	char name[STRINGSIZE], assign[STRINGSIZE];
	int count = 0;

	while (scanf("%s", name) != EOF && strncmp(name, "END", STRINGSIZE) != 0) {
		strncpy(varName[count], name, STRINGSIZE);
		varNameTable[count] = varName[count];

		scanf("%s", assign);
		assert(strncmp(assign, "=", STRINGSIZE) == 0);

		scanf("%d", &(varValue[count]));

		++count;
	}

	varNameTable[count] = NULL;
}

void processCode(char *varNameTable[], int code[], int gotoLine[], int target[], int operand1[], int operand2[], int operator[]) {
	char first[STRINGSIZE], var[STRINGSIZE], op[STRINGSIZE], assign[STRINGSIZE];
	char *firstTable[] = {"GOTO", "IF", "PRINT", "STOP"};
	char *opTable[] = {"==", "!=", ">", "<", ">=", "<=", "+", "-", "*", "/", "%", NULL};
	int line = 1;

	while (scanf("%s", first) != EOF) {
		switch (getIndex(first, firstTable)) {
			case GOTO: // GOTO line
				code[line] = GOTO;
				scanf("%d", &(gotoLine[line]));
				break;
			case IF: // IF OP1 COMPARATOR OP2 GOTO line
				code[line] = IF;
				scanf("%s", var);
				operand1[line] = getIndex(var, varNameTable);
				scanf("%s", op);
				operator[line] = getIndex(op, opTable);
				scanf("%s", var);
				operand2[line] = getIndex(var, varNameTable);
				scanf("%s", first);
				assert(strncmp(first, "GOTO", STRINGSIZE) == 0);
				scanf("%d", &(gotoLine[line]));
				break;
			case PRINT: // PRINT VAR
				code[line] = PRINT;
				scanf("%s", var);
				target[line] = getIndex(var, varNameTable);
				break;
			case STOP: // STOP
				code[line] = STOP;
				break;
			default: // TARGET = OP1 OPERATOR OP2
				code[line] = ASSIGN;
				target[line] = getIndex(first, varNameTable);
				scanf("%s", assign);
				assert(strncmp(assign, "=", STRINGSIZE) == 0);
				scanf("%s", var);
				operand1[line] = getIndex(var, varNameTable);
				scanf("%s", op);
				operator[line] = getIndex(op, opTable);
				scanf("%s", var);
				operand2[line] = getIndex(var, varNameTable);
		}

		++line;
	}
}

void exeCode(int varValue[], int code[], int gotoLine[], int target[], int operand1[], int operand2[], int operator[]) {
	int line = 1;

	while (code[line] != STOP) {
		switch (code[line]) {
			case GOTO:
				line = gotoLine[line];
				break;
			case IF:
				line = logic(varValue[operand1[line]], varValue[operand2[line]], operator[line]) ? gotoLine[line] : (line + 1);
				break;
			case PRINT:
				printf("%d\n", varValue[target[line]]);
				++line;
				break;
			case ASSIGN:
				varValue[target[line]] = arithmetic(varValue[operand1[line]], varValue[operand2[line]], operator[line]);
				++line;
				break;
			default:
				line = 1;
		}
	}
}
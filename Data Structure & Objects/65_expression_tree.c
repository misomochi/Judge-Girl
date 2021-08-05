#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGSIZE 1000
#define VARIABLELENGTH 33 // '\0'
#define VARIABLECOUNT 50

typedef enum type {ADD, SUB, MUL, DIV, CONST, VAR} Type;

typedef struct node {
	Type type;
	char variable[VARIABLELENGTH];
	int value;
	struct node *left_tree;
	struct node *right_tree;
} Node;

typedef struct variable {
	char variable[VARIABLELENGTH];
	int value;
} Variable;

Type operator(char);
Node *parser();
int variableValue(char [], Variable[]);
int compute(Node *, Variable[]);

int main(int argc, char const *argv[]) {
	Node *root = parser();

	Variable v[VARIABLECOUNT];
	int count = 0;

	while(scanf("%s = %d", v[count].variable, &(v[count].value)) != EOF)
		++count;

	printf("%d\n", compute(root, v));

	return 0;
}

Type operator(char c) {
	switch(c) {
		case '+':
			return ADD;
		case '-':
			return SUB;
		case '*':
			return MUL;
		case '/':
			return DIV;
	}
}

Node *parser(void) {
	Node *node = (Node *)malloc(sizeof(Node));
	int c = getchar();

	if (c == '(') {
		getchar(); // space
		node -> type = operator(getchar()); // operator
		getchar(); // space
		node -> left_tree = parser(); // left tree
		getchar(); // space
		node -> right_tree = parser(); // right tree
		getchar(); // space
		getchar(); // right parentheses
	} else {
		ungetc(c, stdin);

		if (c >= '0' && c <= '9') {
			node -> type = CONST;
			scanf("%d", &node -> value);
		} else {
			node -> type = VAR;
			scanf("%s", node -> variable);
		}

		node -> left_tree = NULL;
		node -> right_tree = NULL;
	}

	return node;
}

int variableValue(char variable[VARIABLELENGTH], Variable v[VARIABLECOUNT]) {
	Variable *ptr = v;

	while(ptr != NULL) {
		if (strncmp(variable, ptr -> variable, VARIABLELENGTH) != 0) {
			++ptr;
			continue;
		}

		return ptr -> value;
	}
}

int compute(Node *node, Variable v[VARIABLECOUNT]) {
	switch(node -> type) {
		case ADD:
			return compute(node -> left_tree, v) + compute(node -> right_tree, v);
		case SUB:
			return compute(node -> left_tree, v) - compute(node -> right_tree, v);
		case MUL:
			return compute(node -> left_tree, v) * compute(node -> right_tree, v);
		case DIV:
			return compute(node -> left_tree, v) / compute(node -> right_tree, v);
		case CONST:
			return node -> value;
		default:
			return variableValue(node -> variable, v);
	}
}
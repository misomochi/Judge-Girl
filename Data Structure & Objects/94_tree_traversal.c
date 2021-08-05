#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *left;
	struct node *right;
} Node;

Node *init_node(int, Node *, Node *);
Node *parser();
void HLHR(Node *);
void HRHL(Node *);

int main(int argc, char const *argv[])
{
	Node *root = parser();
	HLHR(root);

	return 0;
}

Node *init_node(int value, Node *left, Node *right) {
	Node *node = (Node *)malloc(sizeof(Node));

	node -> value = value;
	node -> left = left;
	node -> right = right;

	return node;
}

Node *parser(void) {
	int c = getchar();

	if (c == '(') // left parentheses
	{
		Node *left = parser();
		getchar(); // comma
		Node *right = parser();
		getchar(); // right parentheses

		return init_node(left -> value + right -> value, left, right);
	} else { // number
		ungetc(c, stdin);

		int num;
		scanf("%d", &num);

		return init_node(num, NULL, NULL);
	}
}

void HLHR(Node *root) {
	if (root == NULL)
		return;

	printf("%d\n", root -> value);
	HRHL(root -> left);
	printf("%d\n", root -> value);
	HRHL(root -> right);
}

void HRHL(Node *root) {
	if (root == NULL)
		return;

	printf("%d\n", root -> value);
	HLHR(root -> right);
	printf("%d\n", root -> value);
	HLHR(root -> left);
}
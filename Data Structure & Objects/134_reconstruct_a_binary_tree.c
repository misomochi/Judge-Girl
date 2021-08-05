#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	int level;
    struct node *left;
	struct node *right;
} Node;

int compare(const void *, const void *);
Node *constructTree(Node *[], int, int);
int findLevel(Node *, int);
Node *findLCA(Node *, int, int);
void findDistance(Node *, int, int);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	Node *nodes[n];
	for (int i = 0; i < n; ++i) {
	    nodes[i] = (Node *)malloc(sizeof(Node));
		scanf("%d%d", &(nodes[i] -> key), &(nodes[i] -> level));
		nodes[i] -> left = NULL;
		nodes[i] -> right = NULL;
	}

	qsort(nodes, n, sizeof(Node *), compare); // sort by key

	Node *root = constructTree(nodes, 0, n);

	int p;
	scanf("%d", &p);

	for (int i = 0; i < p; ++i) {
		int n1, n2;
		scanf("%d%d", &n1, &n2);
		findDistance(root, n1, n2);
	}

	return 0;
}

int compare (const void *a, const void *b) {
	// a, b are pointers pointing to an array of pointers
	const Node *nodeA = *(const Node **)a;
	const Node *nodeB = *(const Node **)b;

	return (nodeA -> key - nodeB -> key);
}

Node *constructTree(Node *nodes[], int start, int end) {
	if (start == end)
		return NULL;

	int temp = start;
	Node *root = nodes[start];

	for (int i = start; i < end; ++i) {
		if (nodes[i] -> level >= root -> level)
			continue;

		root = nodes[i];
		temp = i;
	}

	root -> left = constructTree(nodes, start, temp);
	root -> right = constructTree(nodes, temp + 1, end);

	return root;
}

int findLevel(Node *root, int n) {
	if (root == NULL)
		return 0;
	else if (root -> key == n)
		return root -> level;
	else if (root -> key < n)
		return findLevel(root -> right, n);
	else
		return findLevel(root -> left, n);
}

// lowest common ancestor
Node *findLCA(Node *root, int a, int b) {
	if (root == NULL)
		return NULL;

	if (root -> key == a || root -> key == b)
		return root;

	Node *leftLCA = findLCA(root -> left, a, b);
	Node *rightLCA = findLCA(root -> right, a, b);

	if (leftLCA && rightLCA) // both leftLCA and rightLCA are not NULL
		return root;
	else
		return (leftLCA != NULL) ? leftLCA : rightLCA;
}

void findDistance(Node *root, int a, int b) {
	Node *lca = findLCA(root, a, b);

	printf("%d\n", findLevel(root, a) + findLevel(root, b) - 2 * lca -> level);
}
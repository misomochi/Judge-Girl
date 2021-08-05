#include <stdio.h>
#include "node.h"

void printPath(struct node *root, int path[TREESIZE], int depth) {
	if (root == NULL)
		return;

	path[depth] = root -> data;

	// leaf node
	if (root -> left == NULL && root -> right == NULL)
	{
		for (int i = 0; i < depth; ++i)
			printf("%d ", path[i]);
		printf("%d\n", path[depth]);

		return;
	} else {
		printPath(root -> left, path, depth + 1);
		printPath(root -> right, path, depth + 1);
	}
}

void print_all_paths(struct node *root) {
	int path[TREESIZE];

	printPath(root, path, 0);

	return;
}
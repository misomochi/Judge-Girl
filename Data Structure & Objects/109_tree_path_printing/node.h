#ifndef _NODE_H
#define _NODE_H

#define TREESIZE 1000
 
struct node {
    struct node *left;
    struct node *right;
    int data;
};

void printPath(struct node *, int [], int);
void print_all_paths(struct node *);
 
#endif
#ifndef TREENODE_H
#define TREENODE_H

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Creates a new tree node with
// no childern
Node *make_node(int data);

// Builds a random tree
// max_height: the tallest the tree can get
// max_value: the largest possible node data value
Node *random_tree(int max_height, int max_value);

// Draw thes tree using ASCII text
void draw_tree(const Node *t);

// Returns the number of nodes in the tree
int size(const Node *t);


#endif

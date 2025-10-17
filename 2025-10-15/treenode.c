#include <stdio.h>
#include <stdlib.h>
#include "treenode.h"

// Creates a new tree node with
// no childern
Node *make_node(int data) {
    Node *result = malloc(sizeof *result);
    result->data = data;
    result->left = result->right = NULL;
    return result;
}

// Builds a random tree
// max_height: the tallest the tree can get
// max_value: the largest possible node data value
Node *random_tree(int max_height, int max_value) {
    Node *root = NULL;
    if (max_height > 0) {
        root = make_node(rand() % max_value);
        root->left = random_tree(rand() % max_height, max_value);
        root->right = random_tree(rand() % max_height, max_value);
    }
    return root;
}

// Returns the number of nodes in the tree
int size(const Node *t) {
    if (t) 
        return size(t->left) + 1 + size(t->right);
    else
        return 0;
}

// Deallocates the memory held by all the nodes in a tree
void dispose_tree(Node *t) {
    if (t) {
        dispose_tree(t->left);
        dispose_tree(t->right);
        free(t);
    }
}

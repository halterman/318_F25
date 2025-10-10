#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "treenode.h"

int main() {
    srand(time(NULL));
    Node *root = random_tree(10, 1000);
    draw_tree(root);
    printf("The tree contains %d nodes\n", size(root));
}

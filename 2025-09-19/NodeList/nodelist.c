#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

// Inserts new element n onto the back of the list
// to which p points. Uses recursion instead of iteration.
struct node *insert(struct node *p, int n) {
    //  Check that we are not at the end of the list
    if (p)
        p->next = insert(p->next, n); // Add to rest of list
    else {   //  Insert new item
        p = malloc(sizeof *p);
        p->data = n;
        p->next = NULL;
    }
    return p;
}

// Inserts new element n onto the back of the list
// to which p points. Uses iteration instead of recursion.
//Node *insert(Node *p, int n) {
//    // Make the new node
//    Node *nn = malloc(sizeof *nn);
//    nn->data = n;
//    nn->next = NULL;
//    // Find the last element in the list
//    struct node *cursor = p; 
//    while (cursor && cursor->next) 
//        cursor = cursor->next;
//    if (cursor) {   // Insert on back of nonempty list
//        cursor->next = nn;
//    } else {
//        p = nn; // List initially empty
//    }
//    return p;
//}

// Deallocates the memory held by the list to which
// p points.
void dispose_list(Node *p) {
    while (p) {
        Node *temp = p;
        p = p->next;
        free(temp);
    }
}


// Prints the elements in the list to which p points.
void print_list(const Node *p) {
    while (p) {
        printf("-> (%d   %p)", p->data, p->next);
        p = p->next;
    }
    printf("\n");
}


int main() {
    // Make a list containing one element.
    Node *p = malloc(sizeof *p);
    p->data = 4;
    p->next = NULL;
    print_list(p);
    printf("%d   %p\n", p->data, p->next);
    dispose_list(p);

    printf("------------------------------------\n");
    // Make a longer list.
    p = NULL;
    p = insert(p, 10);
    p = insert(p, 20);
    p = insert(p, 30);
    p = insert(p, 40);
    p = insert(p, 50);
    print_list(p);
    dispose_list(p);

    //printf("------------------------------------\n");
    // Make a really big list.
    //p = NULL;
    //for (int i = 1; i < 1000000000; i++)
    //    p = insert(p, i);
    ////print_list(p);
    //dispose_list(p);

    puts("Program execution complete>");
}

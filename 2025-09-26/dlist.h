#ifndef DLIST_H_
#define DLIST_H_


// Structure for holding a doubly-linked list
// element.
typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

// A doubly-linked list instance maintains
// pointers to the head and tail of the list
// and the list's size.
typedef struct list {
    Node *head;  // Front sentinel
    Node *tail;  // Rear sentinel
    int current_size;
} List;


// Creates a new, empty ordered doubly-linked list.
List make_list();

// Frees up the memory held by a list.
void list_dispose(List *lst);

// Returns the number of elements in list lst.
int list_length(const List *lst);

// Inserts item into its proper place in list lst.
void list_insert(List *lst, int item);

// Removes item from list, if possible. In case of
// duplicate elements, the function removes only
// matching element closest to the front of the list.
// Returns 1 if successful; returns 0 if the
// item to remove is not present in the list.
int list_remove(List *lst, int item);

// Prints the elements of the list in order from front
// to back.
void list_print(const List *lst);

// Prints the elements of the list in reverse order from 
// back to front.
void list_print_reverse(const List *lst);

#endif

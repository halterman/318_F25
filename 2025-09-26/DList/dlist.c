#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

// Creates a new, empty ordered doubly-linked list.
List make_list() {
    List result;
    result.head = malloc(sizeof *result.head);
    result.tail = malloc(sizeof *result.tail);
    result.head->next = result.tail;
    result.tail->prev = result.head;
    result.head->prev = result.tail->next = NULL;
    result.current_size = 0;
    return result;
}

// Frees up the memory held by a list.
void list_dispose(List *lst) {
    // Free up the space held by the list
    Node *p = lst->head;
    while (p) {
        Node *temp = p;
        p = p->next;
        free(temp);
    }
}

// Returns the number of elements in list lst.
int list_length(const List *lst) {
    return lst->current_size;
}

// Inserts item into its proper place in list lst.
void list_insert(List *lst, int item) {
    // Find location to insert the element
    Node *p = lst->head->next;
    while (p != lst->tail && p->data < item)
        p = p->next;
    // Make the new node
    Node *new_node = malloc(sizeof *new_node);
    new_node->data = item;
    // Link in the new node
    new_node->prev = p->prev;
    new_node->next = p;
    p->prev = new_node;
    new_node->prev->next = new_node;
    lst->current_size++;    // Adjust size
}

// Removes item from list, if possible. In case of
// duplicate elements, the function removes only
// matching element closest to the front of the list.
// Returns 1 if successful; returns 0 if the
// item to remove is not present in the list.
int list_remove(List *lst, int item) {
    // Find element to remove
    int result = 0;  //  Fail by default
    Node *p = lst->head->next;
    while (p != lst->tail && p->data != item)
        p = p->next;
    if (p != lst->tail) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
        lst->current_size--;  // Now one less
        result = 1;  // Found element and deleted it
    }
    return result;

}

// Prints the elements of the list in order from front
// to back.
void list_print(const List *lst) {
    printf("[");
    if (lst->head->next != lst->tail) { // List is non-empty
        Node *p = lst->head->next;
        printf("%d", p->data);
        for (p = p->next; p != lst->tail; p = p->next )
            printf("->%d", p->data);
    }
    printf("]");
}


// Prints the elements of the list in reverse order from 
// back to front.
void list_print_reverse(const List *lst) {
    printf("[");
    if (lst->tail->prev != lst->head) { // List is non-empty
        Node *p = lst->tail->prev;
        printf("%d", p->data);
        for (p = p->prev; p != lst->head; p = p->prev )
            printf("<-%d", p->data);
    }
    printf("]");

}


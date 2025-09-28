//  File testlist.cpp

#include <stdio.h>
#include "dlist.h"

int main() {
    List list = make_list();
    int done = 0;
    int value;
    char command;
    while (!done) {
        printf("=> ");
        scanf(" %c", &command);
        switch (command) {
            case 'I':
            case 'i':
            case '+':
                scanf("%d", &value);
                printf("Inserting %d\n", value);
                list_insert(&list, value);
                break;
            case 'D':
            case 'd':
            case '-':
                scanf("%d", &value);
                if (!list_remove(&list, value))
                    printf("Cannot remove %d\n", value);
                else
                    printf("Removed %d\n", value);
                break;
            case 'P':
            case 'p':
                list_print(&list);
                printf("\n");
                break;
            case 'R':
            case 'r':
                list_print_reverse(&list);
                printf("\n");
                break;
            case '?':
                printf("Insert (Ii+), Delete (Dd-), "
                       "Print (Pp), Reverse print (Rr), "
                       "Quit (Qq)\n");
                break;
            case 'Q':
            case 'q':
                done = 1;
                break;
        }
    }
    list_dispose(&list);
}

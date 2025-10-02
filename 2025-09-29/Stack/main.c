#include <stdio.h>
#include "int_stack.h"


int main() {
    IntStack s;
    s = make_int_stack(10);
    int_stk_push(&s, 10);
    int_stk_push(&s, 15);
    int_stk_push(&s, 20);
    int_stk_push(&s, 25);
    int_stk_push(&s, 30);
    while (!int_stk_empty(&s))
        printf("%d ", int_stk_pop(&s));
    printf("\n");
    dispose_int_stack(&s);
}

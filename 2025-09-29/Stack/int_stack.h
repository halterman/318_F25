#ifndef INT_STACK_H_
#define INT_STACK_H_

struct int_stack_impl;  // Forward reference

typedef struct int_stack {
    struct int_stack_impl *impl;
} IntStack;

IntStack make_int_stack(int size);
void int_stk_push(IntStack *stk, int item);
int int_stk_pop(IntStack *stk);
int int_stk_top(const IntStack *stk);
int int_stk_empty(const IntStack *stk);
void dispose_int_stack(IntStack *stk);

#endif


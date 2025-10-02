#include <assert.h>
#include <stdlib.h>
#include "int_stack.h"


struct int_stack_impl {
    int *stack;
    int size;
    int top;
};


IntStack make_int_stack(int size) {
    IntStack result;
    result.impl = malloc(sizeof *result.impl);
    result.impl->stack = malloc(size * sizeof *result.impl->stack);
    result.impl->size = size;
    result.impl->top = -1;
    return result;
}

void int_stk_push(IntStack *stk, int item) {
    assert(stk->impl->top < stk->impl->size);
    stk->impl->stack[++stk->impl->top] = item;
}

int int_stk_pop(IntStack *stk) {
    assert(stk->impl->top >= 0);
    return stk->impl->stack[stk->impl->top--];
}

int int_stk_top(const IntStack *stk) {
    return stk->impl->stack[stk->impl->top];
}

int int_stk_empty(const IntStack *stk) {
    return stk->impl->top < 0;
}


void dispose_int_stack(IntStack *stk) {
    free(stk->impl->stack);
    free(stk->impl);
}


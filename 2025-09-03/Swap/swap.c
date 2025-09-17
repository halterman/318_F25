#include <stdio.h>

void swap(int *a, int *b) {
    //printf("Before swap: a = %d, b = %d\n", a, b);
    int temp = *a;
    *a = *b;
    *b = temp;
    //printf("After swap: a = %d, b = %d\n", a, b);
}

int main() {
    int x = 10, y = 12;
    printf("x = %d, y = %d\n", x, y);
    printf("-----------------------------------\n");
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
}


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const int ITERATIONS = 1000000000;

int main() {
    srand(time(NULL));
    double sum = 0;
    for (int i = 0; i < ITERATIONS; i++)
        sum += rand() % 1000000;
    printf("Average value: %lf\n", sum / ITERATIONS);
}

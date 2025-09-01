// isascending.c

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "randrange.h"
#include "stopwatch.h"


// Creates and returns an array holding n elements.
// Each each element is a random integer
// in the range 0...max_element - 1, inclusive.
// The caller is responsible to deallocate the 
// array's storage.
static int *make_array(int n, int max_element) {
    int *result = malloc(n * sizeof *result);
    assert(result != NULL);
    for (int i = 0; i < n; i++)
        result[i] = randrange(0, max_element + 1);
    return result;
}


// Returns 1 if the array contains integer values
// appearing in non-descending order; otherwise,
// returns 0. The function does not disturb the
// contents of the array, nor does it allocate
// from the heap.
// a is the array, and n is the number of elements 
// in array a.
int is_ascending1(const int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j])
                return 0;
        }
    }
    return 1;
}

// Returns 1 if the array contains integer values
// appearing in non-descending order; otherwise,
// returns 0. The function does not disturb the
// contents of the array, nor does it allocate
// from the heap.
// a is the array, and n is the number of elements 
// in array a.
int is_ascending2(const int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return 0;
        }
    }
    return 1;
}

double count = 0;

// Document this function
static double time_it(const int *a, int n, int (*f)(const int *, int)) {
    Stopwatch timer;
    sw_reset(&timer);
    sw_start(&timer);
    count += f(a, n);
    f(a, n);
    sw_stop(&timer);
    return sw_elapsed(&timer);
}

// Print the contents of array a.
// Array a has size n.
static void print_array(const int *a, int n) {
    printf("{");
    if (n > 0) {
        printf("%d", a[0]);
        for (int i = 1; i < n; i++) {
            printf(", %d", a[i]);
        }
    }
    printf("}");
}

static void test_make_array() {
    for (int i = 0; i < 30; i++) {
        int *a = make_array(20, 100);
        print_array(a, 20);
        printf("\n");
        free(a);
    }
    printf("------------------\n");
}


int main(int argc, char* argv[]) {

    test_make_array();

    printf("%d\n", argc);
    if (argc < 2) {
        printf("-----------------------------------------------------------\n");
        printf("Array Size     is_ascending1   is_ascending2        Speedup\n");
        printf("-----------------------------------------------------------\n");
        for (int size = 10000; size < 200001; size += 10000) {
            int *arr = malloc(size * sizeof *arr);
            assert(arr != NULL);
            for (int i = 0; i < size; i++)
                arr[i] = i;
            double t1 = time_it(arr, size, is_ascending1);
            double t2 = time_it(arr, size, is_ascending2);
            printf("%7d   ", size);
            printf("%15.6f", t1); 
            printf("%15.6f", t2); 
            printf("%15.2f x\n", t1 / t2); 
            free(arr); // Deallocate array
        }
    }
    else {
        const int size = atoi(argv[1]);
        printf("Array size: %d\n", size);

		int *arr = malloc(size * sizeof *arr);
        assert(arr != NULL);
		for (int i = 0; i < size; i++) {
			arr[i] = i;
		}

        double t1 = time_it(arr, size, is_ascending1);
        double t2 = time_it(arr, size, is_ascending2);
        printf("Speed up: %10.2f x\n", t1 / t2);
		free(arr); // Deallocate array
    }
    printf("Count = %lf\n", count);

}




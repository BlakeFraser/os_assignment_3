#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "mergesort.h"

// Declare A and B from mergesort.c
extern int *A;
extern int *B;

int main() {
    int n = 16;
    int i;

    // Allocate arrays
    A = malloc(n * sizeof(int));
    B = malloc(n * sizeof(int));

    // Generate random numbers
    srand(42);  // fixed seed for reproducibility
    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        A[i] = rand() % 100;
        printf("%d ", A[i]);
    }
    printf("\n\n");

    // Create arguments for top-level call
    struct argument *args = buildArgs(0, n - 1, 3);  // 3 = recursion depth

    // Run parallel mergesort
    pthread_t rootThread;
    pthread_create(&rootThread, NULL, parallel_mergesort, (void *)args);
    pthread_join(rootThread, NULL);

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Verify sort correctness
    for (i = 1; i < n; i++) {
        if (A[i-1] > A[i]) {
            printf("Error: array not sorted!\n");
            free(A);
            free(B);
            return 1;
        }
    }
    printf(" Array sorted correctly!\n");

    free(A);
    free(B);
    return 0;
}

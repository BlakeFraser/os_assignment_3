#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

/* Define the extern globals here (one translation unit must define them) */
int *A = NULL;
int *B = NULL;

/* Helper function to print an array */
void print_array(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Helper function to run a test */
void run_test(int *input, int n, const char *test_name) {
    int i;

    /* Copy input into A */
    for (i = 0; i < n; i++)
        A[i] = input[i];

    printf("=== %s ===\n", test_name);
    printf("Before sort: ");
    print_array(A, n);

    if (n > 1) {
        my_mergesort(0, n - 1);
    }

    printf("After sort:  ");
    print_array(A, n);
    printf("\n");
}

int main(void) {
    int n = 100; /* capacity for largest test; increase if needed */

    A = malloc(n * sizeof(int));
    B = malloc(n * sizeof(int));
    if (!A || !B) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(A); free(B);
        return 1;
    }

    /* 1. Empty array */
    int *empty = NULL; /* n=0 implies we won't read input */
    run_test(empty, 0, "Empty array");

    /* 2. Single element */
    int single[] = {42};
    run_test(single, 1, "Single element");

    /* 3. Two elements */
    int two[] = {2, 1};
    run_test(two, 2, "Two elements");

    /* 4. Already sorted */
    int sorted[] = {1, 2, 3, 4, 5};
    run_test(sorted, 5, "Already sorted");

    /* 5. Reverse sorted */
    int reverse[] = {5, 4, 3, 2, 1};
    run_test(reverse, 5, "Reverse sorted");

    /* 6. All elements equal */
    int equal[] = {7, 7, 7, 7};
    run_test(equal, 4, "All elements equal");

    /* 7. Odd number of elements */
    int odd[] = {3, 1, 4, 2, 5};
    run_test(odd, 5, "Odd number of elements");

    /* 8. Negative numbers */
    int negative[] = {-3, -1, -7, 2, 0};
    run_test(negative, 5, "Negative numbers");

    /* 9. Mix of positives, negatives, duplicates */
    int mix[] = {5, -2, 3, 3, 0, -2};
    run_test(mix, 6, "Mix of positive, negative, duplicates");

    free(A);
    free(B);
    return 0;
}

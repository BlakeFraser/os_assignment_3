#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"


int main() {
    struct argument *testArgs = buildArgs(0, 33, 3);

    printf("Left: %d\n", testArgs->left);
    printf("Right: %d\n", testArgs->right);
    printf("Level: %d\n", testArgs->level);


    free(testArgs); 
    return 0;
}

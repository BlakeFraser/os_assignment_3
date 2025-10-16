/**
 * This file implements parallel mergesort.
 */


#include <stdio.h>
#include <string.h> /* for memcpy */
#include <stdlib.h> /* for malloc */
#include "mergesort.h"


int *A;
int *B;
/* this function will be called by mergesort() and also by parallel_mergesort(). */
void merge(int leftstart, int leftend, int rightstart, int rightend){
    int index_left = leftstart;
    int index_right = rightstart;
    int index_temp = leftstart;


    //Merge the left and right sorted halves in B[].
    while(index_left <= leftend && index_right <= rightend){
        if(A[index_left] <= A[index_right]){
            B[index_temp++] = A[index_left++];
        }else{
            B[index_temp++] = A[index_right++];
        }
    }
    //This copies any remaining elements from left side
    while(index_left <= leftend){
        B[index_temp++] = A[index_left++];
    }
    //This copies any remaining elements from right side
    while(index_right <= rightend){
        B[index_temp++] = A[index_right++];
    }
    //This copies the merged data from B[] back to A[]
    for(index_temp = leftstart; index_temp <= rightend; index_temp++){
        A[index_temp] = B[index_temp];
    }
}


/* this function will be called by parallel_mergesort() as its base case. */
void my_mergesort(int left, int right){
    if(left>=right)  {
    return; //base case
}


 int middpoint= (left+right)/2;


 //Recursively sort both halves
 my_mergesort(left,middpoint);
 my_mergesort(middpoint+1,right);


 //Merge the two sorted halves
 merge(left,middpoint,middpoint+1,right);
}


/* this function will be called by the testing program.
void * parallel_mergesort(void *arg){
        return NULL;
}
*/


/* we build the argument for the parallel_mergesort function.
struct argument * buildArgs(int left, int right, int level){
        return NULL;
}
*/


README.template

## Operating Systems - Assignment 3 Concurrency

* Authors: Sam Toohey (a1886287), Blake Fraser (a1886958), Tom Panopoulos (a1885511)

## Overview

This project implments a multi-threaded version of the merge sort algorithm (known as parallel merge sort) using the pthread (POSIX) 
library in C. The program is designed to recursively divide an array into smaller segments and sorts them concurrently, then merges 
into a fully ordered array. The goal of this assignment is to implement and test inter-thread synchronisation.

## Manifest

Makefile:
Builds the testing executable for compilation.

mergesort.c:
Implements the core mergesort and parallel logic, including the buildArgs logic for handing the input argument for the threads in the
parallel sort algorithm.

mergesort.h:
Header file for structure definitions, function prototypes and global variable declarations.

meresortttest.c:
Basic mergesort testing for my_mergesort function.

test_buildargs.c:
Tests the buildArgs() function to ensure threads are properly handed before being passed as arguments to parallel_mergesort().

test_parallel_mergesort.c:
Tests the multi-threaded functionality of the parallel_mergesort funciton, ensuring variables are handled properly.

test-mergesort.c:
Test all functionality thoroughly of the algorithm designed in this assignment, taking the input size (in bits), cutoff level and 
seed. It checks the sorting has been correctly done and the time it is completed in.

## Building the project

To build the project ensure gcc and pthreads library are installed and run "make", which compiles all necessary object files and 
produces the following executable "./test-mergesort". Use for example "./test-mergesort 10000000 3 50" which represents 
<input size>, <cutoff level> and <seed>, to clean up the object files use "make clean". Other testing files were used to debug 
and test code per iteration of the assignment.

## Features and usage

Main Features:
Parallel sorting and stable merging, with a thread safe design. Refer to building the project to see how to run it.

## Testing

Testing was conducted using multiple test files, firstly mergesorttest.c was used to verify the basic merge sorting algorithm for 
a variety of different array lengths with a wide range of values. Next the buildargs architecture was tested to ensure it could 
validate argument creation and memory allocation, this was tested in the file test_buildargs.c. parallel mergesort testing was 
conducted in test_parallel_mergesort.c which tested multi-threaded recursion, synchronisation and merge integrity. The overall 
test in teset-mergesort.c combined all functional test with large data arrays to evaluate runtime and correctness.

## Known Bugs

There are no known observable bugs in our code.

## Reflection and Self Assessment

A common problem was the reoccuring segmentation faults that were developed because of the incorrect use of thread synchronisation.
We noticed that global arrays A and B were not secured and were causing some of the issues, however, with correct management of the 
arrays in each of the files and correct memory mangement these issues were fixed. Threads also were out of sync as they were freed in 
the merge sort functions in mergesort.c causing race conditions. When the threads were only freed in the struct argument the issue 
was resolved. These issues were found through thorough testing at each stage as explained above.

Issues with thread synchronisation were researched using sites such as stackoverflow and geeksforgeeks where similar issues were 
resolved. Also understand how pthreads handle void pointers and struct agruments required some additional research, particularly on 
proper casting and memory allocation with malloc. The thorough testing process help substancially being able to incrementally develop 
features while ensuring that the backbone of the code was able to be functional.

## Sources Used

Used for studying the Parallel sort and mergesort algorithms with multi-threading support:
https://redixhumayun.github.io/systems/2023/12/29/parallel-merge-sort.html
https://www.geeksforgeeks.org/dsa/merge-sort/
https://www.geeksforgeeks.org/dsa/merge-sort-using-multi-threading/
https://stackoverflow.com/questions/63584950/how-to-multithread-the-merge-operation-in-merge-sort
https://www.geeksforgeeks.org/operating-systems/posix-threads-in-os/


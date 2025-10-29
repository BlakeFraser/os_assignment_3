README.template

## Operating Systems - Assignment 3 Concurrency

* Authors: Sam Toohey (a1886287), Blake Fraser (a1237912738912638), Tom Panopoulos (a12371283)

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
Parallel sorting and stable merging, with a thread safe design.


Summarise the main features of your program. It is also appropriate to
instruct the user how to use your program.

## Testing

Testing was conducted using multiple test files, firstly mergesorttest.c was used to verify the basic merge sorting algorithm for 
a variety of different array lengths with a wide range of values. Next the buildargs architecture was tested to ensure it could 
validate argument creation and memory allocation, this was tested in the file test_buildargs.c. parallel mergesort testing was 
conducted in test_parallel_mergesort.c which tested multi-threaded recursion, synchronisation and merge integrity. The overall 
test in teset-mergesort.c combined all functional test with large data arrays to evaluate runtime and correctness.

## Known Bugs

There are no known observable bugs in our code.

## Reflection and Self Assessment

A common problem was the reoccuring segmentation faults that were developed
Discuss the issues you encountered during development and testing. What
problems did you have? What did you have to research and learn on your own?
What kinds of errors did you get? How did you fix them?

What parts of the project did you find challenging? Is there anything that
finally "clicked" for you in the process of working on this project? How well
did the development and testing process go for you?

## Sources Used

Used for studying the Parallel sort and mergesort algorithms with multi-threading support:
https://redixhumayun.github.io/systems/2023/12/29/parallel-merge-sort.html
https://www.geeksforgeeks.org/dsa/merge-sort/
https://www.geeksforgeeks.org/dsa/merge-sort-using-multi-threading/
https://stackoverflow.com/questions/63584950/how-to-multithread-the-merge-operation-in-merge-sort

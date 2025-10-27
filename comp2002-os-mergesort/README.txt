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

## Building the project

This section should tell the user how to build your code.  If you are
delivering a library, where does it need to be installed, or how do you use
it? Is this an executable, if so, how can a user get up to speed as fast as
possible?

## Features and usage

Summarise the main features of your program. It is also appropriate to
instruct the user how to use your program.

## Testing

This section should detail how you tested your code. Simply stating "I ran
it a few times and it seems to work" is not sufficient. Your testing needs
to be detailed here.

## Known Bugs

List known bugs that you weren't able to fix (or ran out of time to fix).

## Reflection and Self Assessment

Discuss the issues you encountered during development and testing. What
problems did you have? What did you have to research and learn on your own?
What kinds of errors did you get? How did you fix them?

What parts of the project did you find challenging? Is there anything that
finally "clicked" for you in the process of working on this project? How well
did the development and testing process go for you?

## Sources Used

If you used any sources outside of the textbook, you should list them here. 
If you looked something up on stackoverflow.com or you use help from AI, and 
fail to cite it in this section, it will be considered plagiarism and dealt 
with accordingly. So be safe CITE!

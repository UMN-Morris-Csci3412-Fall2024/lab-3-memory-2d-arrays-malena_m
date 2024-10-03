#!/bin/bash

# Compile mergesort.c and test_mergesort.c
g++ -Wall -g -o mergesort_test mergesort.c mergesort_test.cpp -lgtest -pthread -std=c++0x

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable created: test_mergesort"
    # Run the executable
    ./mergesort_test
else
    echo "Compilation failed."
fi

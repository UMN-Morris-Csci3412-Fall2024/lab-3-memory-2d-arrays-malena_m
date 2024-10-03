#!/bin/bash

# Compile mergesort.c and test_mergesort.c
g++ -Wall -g -o array_merge_test array_merge.c array_merge_test.cpp -lgtest -pthread -std=c++0x

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful."
    # Run the executable
    ./mergesort_test
else
    echo "Compilation failed."
fi

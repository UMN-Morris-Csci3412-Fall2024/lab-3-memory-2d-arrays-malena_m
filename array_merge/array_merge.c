#include <stdlib.h>
#include <stdio.h>
#include "array_merge.h"
#include "../mergesort/mergesort.h"

// Helper function to compare integers for qsort
int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* array_merge(int num_arrays, int* sizes, int** values) {
    // Calculate the total number of elements
    int total_elements = 0;
    for (int i = 0; i < num_arrays; i++) {
        total_elements += sizes[i];
    }

    // Allocate memory for the merged array
    int* merged_array = (int*)malloc(total_elements * sizeof(int));
    int index = 0;

    // Merge all arrays into one
    for (int i = 0; i < num_arrays; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            merged_array[index++] = values[i][j];
        }
    }

    // Sort the merged array using mergesort
    mergesort(total_elements, merged_array);

    // Remove duplicates and count unique elements
    int unique_count = 0;
    for (int i = 0; i < total_elements; i++) {
        if (i == 0 || merged_array[i] != merged_array[i - 1]) {
            unique_count++;
        }
    }

    // Allocate memory for the result array
    int* result = (int*)malloc((unique_count + 1) * sizeof(int));
    result[0] = unique_count;

    // Fill the result array with unique elements
    int result_index = 1;
    for (int i = 0; i < total_elements; i++) {
        if (i == 0 || merged_array[i] != merged_array[i - 1]) {
            result[result_index++] = merged_array[i];
        }
    }

    // Free the merged array
    free(merged_array);

    return result;
}

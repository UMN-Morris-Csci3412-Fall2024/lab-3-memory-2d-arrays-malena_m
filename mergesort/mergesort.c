#include "mergesort.h"
#include <stdlib.h>

// Helper function to merge two sorted arrays
void merge(int values[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            values[k++] = left[i++];
        } else {
            values[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        values[k++] = left[i++];
    }

    while (j < rightSize) {
        values[k++] = right[j++];
    }
}

void mergesort(int size, int values[]) {
    if (size < 2) {
        return;
    }

    int mid = size / 2;

    // Allocate memory for left and right subarrays
    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((size - mid) * sizeof(int));

    // Insert the elements into the left and right subarrays
    for (int i = 0; i < mid; i++) {
        left[i] = values[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = values[i];
    }

    // Recursive call on left and right subarrays
    mergesort(mid, left);
    mergesort(size - mid, right);

    // Merge sorted subarrays back into original array
    merge(values, left, mid, right, size - mid);

    // Free the allocated memory for left and right subarrays
    free(left);
    free(right);
}

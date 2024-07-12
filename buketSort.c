#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void bucketSort(int arr[], int n) {
    int i, j;
    int max = arr[0];
    int min = arr[0];

    // Find max and min values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Create buckets
    int buckets[BUCKET_SIZE][n];
    int bucketCounts[BUCKET_SIZE] = {0};

    // Distribute elements into buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) * (BUCKET_SIZE - 1) / (max - min);
        buckets[bucketIndex][bucketCounts[bucketIndex]++] = arr[i];
    }

    // Sort each bucket individually
    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 0; j < bucketCounts[i] - 1; j++) {
            for (int k = j + 1; k < bucketCounts[i]; k++) {
                if (buckets[i][j] > buckets[i][k]) {
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
    }

    // Concatenate the sorted buckets
    int index = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 0; j < bucketCounts[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {897, 565, 656, 1234, 665, 3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
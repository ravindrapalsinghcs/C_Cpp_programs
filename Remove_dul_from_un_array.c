#include <stdio.h>
#include <stdlib.h>

// Hash table structure for tracking seen elements
#define HASH_SIZE 1000

int hashTable[HASH_SIZE] = {0}; // Initialize hash table

int removeDuplicatesUnsorted(int arr[], int n) {
    int uniqueIndex = 0;

    for (int i = 0; i < n; i++) {
        if (hashTable[arr[i]] == 0) { // If not seen before
            hashTable[arr[i]] = 1;   // Mark as seen
            arr[uniqueIndex] = arr[i]; // Place unique element in array
            uniqueIndex++;
        }
    }

    return uniqueIndex; // Return the new size of the array
}

int main() {
    int arr[] = {4, 2, 5, 2, 1, 4, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Remove duplicates
    int newSize = removeDuplicatesUnsorted(arr, size);

    // Print the unique elements
    printf("Array after removing duplicates:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

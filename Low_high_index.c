#include <stdio.h>

void findLowHigh(int arr[], int size, int key, int* low, int* high) {
    *low = -1;
    *high = -1;

    // Find the low index
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            *low = mid;
            right = mid - 1; // Search on the left
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Find the high index
    left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            *high = mid;
            left = mid + 1; // Search on the right
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // If the key is not found, reset low and high to -1
    if (*low == -1 || *high == -1) {
        *low = -1;
        *high = -1;
    }
}

int main() {
    int arr[] = {1, 2, 5, 5, 5, 5, 5, 5, 5, 5, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    int keys[] = {1, 2, 5, 20, 100}; // Test cases
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        int low, high;
        findLowHigh(arr, size, keys[i], &low, &high);
        printf("Key: %d, Low: %d, High: %d\n", keys[i], low, high);
    }

    return 0;
}

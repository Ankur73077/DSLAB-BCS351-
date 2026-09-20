#include <stdio.h>

// Function for binary search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key) {
            return mid; // Element found
        }
        
        if (arr[mid] < key) {
            low = mid + 1; // Search in right half
        } else {
            high = mid - 1; // Search in left half
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[100]; // Fixed size array, standard for lab programs
    int n, i, key, result;

    // Taking total number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements from user
    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking the element to be searched
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Calling the binary search function
    result = binarySearch(arr, 0, n - 1, key);
    
    // Printing final output
    if (result != -1) {
        printf("\nElement %d found at index %d.\n", key, result);
    } else {
        printf("\nElement %d is not present in the array.\n", key);
    }

    return 0;
}


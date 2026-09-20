#include <stdio.h>

// Function for linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; // Element found
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
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking the element to be searched
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Calling the linear search function
    result = linearSearch(arr, n, key);

    // Printing final output
    if (result != -1) {
        printf("\nElement %d found at index %d.\n", key, result);
    } else {
        printf("\nElement %d is not present in the array.\n", key);
    }

    return 0;
}
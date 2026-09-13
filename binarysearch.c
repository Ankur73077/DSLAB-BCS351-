#include <stdio.h>
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid; 
        }


        if (arr[mid] < target) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int sortedNumbers[] = {10, 11, 15, 23, 45, 70,99}; 
    int size = sizeof(sortedNumbers) / sizeof(sortedNumbers[0]);
    int targetValue = 99;

    int result = binarySearch(sortedNumbers, size, targetValue);

    if (result != -1) {
        printf("Element %d found at index: %d\n", targetValue, result);
    } else {
        printf("Element %d not found in the array.\n", targetValue);
    }

    return 0;
}
//user se array and key to implement binary search in C, you can modify the `main` function to take user input for the array elements and the target value. Here's an updated version of the code that allows the user to input the array and the key:
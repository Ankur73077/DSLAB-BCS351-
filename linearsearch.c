#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int numbers[] = {10, 23, 45, 70, 11, 15};
    
    
    int size = sizeof(numbers) / sizeof(numbers[0]); 
    int targetValue = 70;

    
    int result = linearSearch(numbers, size, targetValue);

    if (result != -1) {
        printf("Element %d found at index: %d\n", targetValue, result);
    } else {
        printf("Element %d not found in the array.\n", targetValue);
    }

    return 0;
}

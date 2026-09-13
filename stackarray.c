#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Stack ka maximum size

int stack[MAX];
int top = -1;

// 1. Overflow check karne ka function
int isFull() {
    return (top == MAX - 1);
}

// 2. Underflow check karne ka function
int isEmpty() {
    return (top == -1);
}

// Element ko stack me daalne ka function
void push(int value) {
    if (isFull()) { // Overflow check use kiya
        printf("Overflow! Stack full hai.\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d stack me push ho gaya.\n", value);
    }
}

// Element ko stack se nikalne ka function
void pop() {
    if (isEmpty()) { // Underflow check use kiya
        printf("Underflow! Stack khali hai.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}


// Top element dekhne ka function
void peek() {
    if (isEmpty()) { // Underflow check use kiya
        printf("Stack empty hai.\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

// Pura stack display karne ka function
void display() {
    if (isEmpty()) { // Underflow check use kiya
        printf("Stack empty hai.\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function menu driven execution ke liye
int main() {
    int choice, value;

    while (1) {
        printf("\n--- STACK OPERATIONS ---");
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value enter karein: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Fir se try karein.\n");
        }
    }
    return 0;
}

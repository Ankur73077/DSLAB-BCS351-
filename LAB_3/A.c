
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push element into stack
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = value;

        printf("%d pushed into stack\n", value);
    }
}

// Remove element from stack
void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

// Show top element
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element = %d\n", stack[top]);
    }
}

// Display stack
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
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
                printf("Program ended\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


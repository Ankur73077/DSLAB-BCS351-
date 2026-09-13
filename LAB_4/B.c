
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Check queue is full
int isFull()
{
    if ((rear + 1) % SIZE == front)
        return 1;
    else
        return 0;
}

// Check queue is empty
int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

// Insert element
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;

    printf("%d inserted\n", value);
}

// Delete element
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("%d deleted\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

// Show front element
void peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element = %d\n", queue[front]);
    }
}

// Display queue
void display()
{
    int i;

    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Circular Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
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
                enqueue(value);
                break;

            case 2:
                dequeue();
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


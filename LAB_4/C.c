
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

// Create new node
struct Node* createNode(int data, int priority)
{
    struct Node *newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;

    return newnode;
}

// Insert element
void enqueue(struct Node **head, int data, int priority)
{
    struct Node *newnode, *temp;

    newnode = createNode(data, priority);

    // Insert at beginning
    if (*head == NULL || priority < (*head)->priority)
    {
        newnode->next = *head;
        *head = newnode;
    }
    else
    {
        temp = *head;

        while (temp->next != NULL &&
               temp->next->priority <= priority)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    printf("%d inserted with priority %d\n", data, priority);
}

// Delete highest priority element
void dequeue(struct Node **head)
{
    struct Node *temp;

    if (*head == NULL)
    {
        printf("Priority queue is empty\n");
        return;
    }

    temp = *head;

    printf("%d deleted\n", temp->data);

    *head = (*head)->next;

    free(temp);
}

// Display queue
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Priority queue is empty\n");
        return;
    }

    printf("\nPriority Queue:\n");

    while (head != NULL)
    {
        printf("Data = %d, Priority = %d\n",
               head->data, head->priority);

        head = head->next;
    }
}

int main()
{
    struct Node *pq = NULL;

    int choice;
    int data, priority;

    while (1)
    {
        printf("\n--- Priority Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter priority: ");
                scanf("%d", &priority);

                enqueue(&pq, data, priority);
                break;

            case 2:
                dequeue(&pq);
                break;

            case 3:
                display(pq);
                break;

            case 4:
                printf("Program ended\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


#include <stdio.h>

#define SIZE 10

void insert(int hash[], int key)
{
    int index, index2, i;

    index = key % SIZE;
    index2 = 7 - (key % 7);

    i = 0;

    while (hash[(index + i * index2) % SIZE] != -1)
    {
        i++;
    }

    hash[(index + i * index2) % SIZE] = key;
}

int search(int hash[], int key)
{
    int index, index2, i, pos;

    index = key % SIZE;
    index2 = 7 - (key % 7);

    for (i = 0; i < SIZE; i++)
    {
        pos = (index + i * index2) % SIZE;

        if (hash[pos] == key)
        {
            return pos;
        }

        if (hash[pos] == -1)
        {
            return -1;
        }
    }

    return -1;
}

int main()
{
    int hash[SIZE];
    int n, key, result;

    for (int i = 0; i < SIZE; i++)
    {
        hash[i] = -1;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(hash, key);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = search(hash, key);

    if (result != -1)
    {
        printf("Element %d found at index %d.\n", key, result);
    }
    else
    {
        printf("Element %d not found.\n", key);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coef;
    int exp;
    struct Term *next;
};

// Create new node
struct Term* create(int c, int e)
{
    struct Term *newnode;

    newnode = (struct Term*)malloc(sizeof(struct Term));

    newnode->coef = c;
    newnode->exp = e;
    newnode->next = NULL;

    return newnode;
}

// Insert term
void insert(struct Term **p, int c, int e)
{
    struct Term *newnode, *temp, *prev;

    newnode = create(c, e);

    if (*p == NULL)
    {
        *p = newnode;
        return;
    }

    temp = *p;
    prev = NULL;

    while (temp != NULL && temp->exp > e)
    {
        prev = temp;
        temp = temp->next;
    }

    // Same exponent
    if (temp != NULL && temp->exp == e)
    {
        temp->coef = temp->coef + c;
        free(newnode);
    }
    else
    {
        newnode->next = temp;

        if (prev == NULL)
            *p = newnode;
        else
            prev->next = newnode;
    }
}

// Display polynomial
void display(struct Term *p)
{
    if (p == NULL)
    {
        printf("0\n");
        return;
    }

    while (p != NULL)
    {
        printf("%dx^%d", p->coef, p->exp);

        if (p->next != NULL)
            printf(" + ");

        p = p->next;
    }

    printf("\n");
}

// Add two polynomials
struct Term* add(struct Term *p1, struct Term *p2)
{
    struct Term *sum = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            insert(&sum, p1->coef + p2->coef, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            insert(&sum, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else
        {
            insert(&sum, p2->coef, p2->exp);
            p2 = p2->next;
        }
    }

    // Remaining terms of first polynomial
    while (p1 != NULL)
    {
        insert(&sum, p1->coef, p1->exp);
        p1 = p1->next;
    }

    // Remaining terms of second polynomial
    while (p2 != NULL)
    {
        insert(&sum, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return sum;
}

int main()
{
    struct Term *p1 = NULL;
    struct Term *p2 = NULL;
    struct Term *sum = NULL;

    int n, i, c, e;

    printf("Enter number of terms of first polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &c, &e);
        insert(&p1, c, e);
    }

    printf("\nEnter number of terms of second polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &c, &e);
        insert(&p2, c, e);
    }

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    sum = add(p1, p2);

    printf("Addition: ");
    display(sum);

    return 0;
}


#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push character into stack
void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

// Pop character from stack
char pop()
{
    if (top == -1)
        return -1;

    return stack[top--];
}

// Return top character
char peek()
{
    if (top == -1)
        return -1;

    return stack[top];
}

// Check priority of operator
int priority(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

// Convert infix to postfix
void convert(char infix[])
{
    char postfix[MAX];
    int i = 0;
    int j = 0;
    char ch;

    while (infix[i] != '\0')
    {
        ch = infix[i];

        // If it is an operand
        if (isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }

        // If opening bracket
        else if (ch == '(')
        {
            push(ch);
        }

        // If closing bracket
        else if (ch == ')')
        {
            while (peek() != '(')
            {
                postfix[j] = pop();
                j++;
            }

            pop();
        }

        // If it is an operator
        else
        {
            while (top != -1 &&
                   priority(peek()) >= priority(ch))
            {
                postfix[j] = pop();
                j++;
            }

            push(ch);
        }

        i++;
    }

    // Remove remaining operators
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main()
{
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    convert(infix);

    return 0;
}


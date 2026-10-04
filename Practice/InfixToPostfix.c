#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node *top = NULL;

void push(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // CHANGE: Check whether memory allocation was successful
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = top;
    top = newNode;

    printf("Data Pushed ...\n");
}

char pop()
{
    if (top == NULL)
    {
        return '\0';
    }

    struct Node *currNode = top;
    char data = currNode->data;

    top = top->next;
    free(currNode);

    return data;
}

void printStack()
{
    if (top == NULL)
    {
        printf("NULL\n");
        return;
    }

    struct Node *currNode = top;

    while (currNode != NULL)
    {
        printf("%c -> ", currNode->data);
        currNode = currNode->next;
    }

    printf("NULL\n");
}

/* 1. Check precedence of operator */
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

/* 2. Check associativity of expression */
char associativity(char ch)
{
    if (ch == '^')
    {
        return 'R'; // Right Associative
    }

    return 'L'; // Left Associative
}

/* 3. Check whether character is an operand */
int operand(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= '0' && ch <= '9'))
    {
        return 1;
    }

    return 0;
}

int main()
{
    // CHANGE: No need to initialize exp because scanf() will take input
    char exp[100];

    char postfix[100];

    int i = 0;
    int j = 0;

    printf("Enter your expression : ");

    // CHANGE: %99s prevents buffer overflow
    scanf("%99s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        /* If character is operand */
        if (operand(ch))
        {
            postfix[j++] = ch;
        }

        /* If opening parenthesis */
        else if (ch == '(')
        {
            push(ch);
        }

        /* If closing parenthesis */
        else if (ch == ')')
        {
            /*
               Pop operators until '(' is found.

               CHANGE: Condition checks for '(' instead of ')'
               because '(' is the opening bracket stored in stack.
            */
            while (top != NULL && top->data != '(')
            {
                postfix[j++] = pop();
            }

            if (top != NULL)
            {
                // Remove '(' from stack
                pop();
            }
        }

        /* If character is an operator */
        else
        {
            /*
               Pop operators having:
               1. Higher precedence
               OR
               2. Same precedence and current operator is
                  left associative.
            */
            while (top != NULL &&
                   top->data != '(' &&
                   (precedence(top->data) > precedence(ch) ||
                    (precedence(top->data) == precedence(ch) &&
                     associativity(ch) == 'L')))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    /*
       After scanning the complete expression,
       pop all remaining operators from stack.
    */
    while (top != NULL)
    {
        postfix[j++] = pop();
    }

    // Add string terminating character
    postfix[j] = '\0';

    printf("Postfix : %s\n", postfix);

    /*
       Stack should be empty after postfix conversion,
       so this will normally print NULL.
    */
    printStack();

    return 0;
}

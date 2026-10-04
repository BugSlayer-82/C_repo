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

    if (newNode == NULL)
    {
        printf("Memory allocation failed ...!\n"); // CHANGE: \n add kiya, taaki next output new line se aaye
        return;
    }

    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

char pop()
{
    if (top == NULL)
    {
        printf("Stack is empty ..!\n");
        return '\0';
    }

    struct Node *temp = top;
    char ch = temp->data;
    top = top->next;
    free(temp);

    return ch;
}

void printStack()
{
    if (top == NULL)
    {
        printf("empty\n");
        return;
    }

    struct Node *currNode = top;

    while (currNode != NULL)
    {
        printf("%c", currNode->data);
        currNode = currNode->next;
    }

    printf("\n");
}

/* 1. Reverse the expression */
void reverse(char exp[])
{
    int i = 0, j = 0;

    while (exp[i] != '\0')
    {
        i++;
    }

    i--;

    while (j < i)
    {
        char ch = exp[j];
        exp[j] = exp[i];
        exp[i] = ch;

        j++;
        i--;
    }
}

/* 2. Check precedence of Operator */
int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }

    return 0;
}

/* 3. Check associativity of Operator */
char associativity(char ch)
{
    if (ch == '^')
    {
        return 'R';
    }

    return 'L';
}

/* 4. Check if character is operand */
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
    char exp[100], prefix[100];
    int i, j = 0;

    printf("Enter your expression : ");
    scanf("%99s", exp); // CHANGE: %99s use kiya, taaki 100-size array me buffer overflow na ho

    reverse(exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        /* Case 1: Operand */
        if (operand(ch))
        {
            prefix[j++] = ch;
        }

        /* Case 2: Opening bracket */
        else if (ch == '(')
        {
            push(ch);
        }

        /* Case 3: Closing bracket */
        else if (ch == ')')
        {
            while (top != NULL && top->data != '(')
            {
                prefix[j++] = pop();
            }

            if (top != NULL)
            {
                pop(); // '(' ko stack se remove kar rahe hain
            }
        }

        /* Case 4: Operator */
        else
        {
            while (top != NULL &&
                   top->data != '(' &&
                   (precedence(top->data) > precedence(ch) ||
                    (precedence(top->data) == precedence(ch) &&
                     associativity(ch) == 'R'))) // CHANGE: 'L' -> 'R', kyunki expression reverse karke prefix bana rahe hain
            {
                prefix[j++] = pop();
            }

            push(ch);
        }
    }

    /* Stack me bache hue operators ko prefix array me daalo */
    while (top != NULL)
    {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    /* Reverse the postfix-like result to get prefix */
    reverse(prefix);

    printf("Prefix : %s\n", prefix);

    return 0;
}

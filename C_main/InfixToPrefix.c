#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node *top = NULL; // Top pointer of the stack

void push(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create a new node
    if (newNode == NULL) // Check whether memory allocation was successful
    {
        printf("Memory allocation failed ...!\n"); // Print error message
        return; // Stop push operation if memory allocation fails
    }
    newNode->data = data; // Store the character in the new node
    newNode->next = top; // Connect new node to the current top
    top = newNode; // Make new node the new top
}

char pop()
{
    if (top == NULL) // Check whether the stack is empty
    {
        printf("Stack is empty ..!\n");
        return '\0'; // Return null character if stack is empty
    }
    struct Node *temp = top; // Store the current top node
    char ch = temp->data; // Store the data before deleting the node
    top = top->next; // Move top to the next node
    free(temp); // Free the old top node from memory
    return ch; // Return the popped character
}

void printStack()
{
    if (top == NULL) // Check whether the stack is empty
    {
        printf("empty\n");
        return;
    }
    struct Node *currNode = top; // Start traversal from the top
    while (currNode != NULL) // Continue until the end of the stack
    {
        printf("%c", currNode->data); // Print current node's data
        currNode = currNode->next; // Move to the next node
    }
    printf("\n"); // Move cursor to the next line
}

/* 1. Reverse the expression */
void reverse(char exp[])
{
    int i = 0, j = 0; // i starts from end and j starts from beginning
    while (exp[i] != '\0') // Find the end of the string
    {
        i++;
    }
    i--; // Move i to the last character
    while (j < i) // Continue until both pointers meet
    {
        char ch = exp[j]; // Store character from the beginning
        exp[j] = exp[i]; // Put last character at beginning
        exp[i] = ch; // Put first character at the end
        j++; // Move j forward
        i--; // Move i backward
    }
}

/* 2. Check precedence of Operator */
int precedence(char ch)
{
    if (ch == '^')
    {
        return 3; // Highest precedence
    }
    else if (ch == '*' || ch == '/')
    {
        return 2; // Multiplication and division precedence
    }
    else if (ch == '+' || ch == '-')
    {
        return 1; // Addition and subtraction precedence
    }
    return 0; // Return 0 if character is not an operator
}

/* 3. Check associativity of Operator */
char associativity(char ch)
{
    if (ch == '^')
    {
        return 'R'; // ^ is Right Associative
    }
    return 'L'; // Other operators are Left Associative
}

/* 4. Check if character is operand */
int operand(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= '0' && ch <= '9'))
    {
        return 1; // Character is an operand
    }
    return 0; // Character is not an operand
}

int main()
{
    char exp[100], prefix[100]; // Arrays for input expression and prefix result
    int i, j = 0; // i for scanning expression, j for prefix index
    printf("Enter your expression : ");
    scanf("%99s", exp); // Read input and prevent buffer overflow
    reverse(exp); // Reverse the infix expression
    for (i = 0; exp[i] != '\0'; i++) // Scan the reversed expression
    {
        char ch = exp[i]; // Store the current character
        /* Case 1: Operand */
        if (operand(ch))
        {
            prefix[j++] = ch; // Directly add operand to prefix array
        }
        /* Case 2: Opening bracket */
        else if (ch == '(')
        {
            push(ch); // Push opening bracket into stack
        }
        /* Case 3: Closing bracket */
        else if (ch == ')')
        {
            // Pop operators until '(' is found
            while (top != NULL && top->data != '(')
            {
                prefix[j++] = pop(); // Remove operator and add it to prefix array
            }
            if (top != NULL)
            {
                pop(); // Remove '(' from the stack
            }
        }
        /* Case 4: Operator */
        else
        {
            // Pop operators with higher precedence
            // OR same precedence when current operator is right associative
            while (top != NULL &&
                   top->data != '(' &&
                   (precedence(top->data) > precedence(ch) ||
                    (precedence(top->data) == precedence(ch) &&
                     associativity(ch) == 'R')))
            {
                prefix[j++] = pop(); // Move stack operator to prefix array
            }
            push(ch); // Push current operator into the stack
        }
    }
    /* Stack me bache hue operators ko prefix array me daalo */
    while (top != NULL)
    {
        prefix[j++] = pop(); // Add remaining operators to prefix array
    }
    prefix[j] = '\0'; // Add string terminating character
    /* Reverse the postfix-like result to get prefix */
    reverse(prefix); // Reverse result to obtain final prefix expression
    printf("Prefix : %s\n", prefix);
    return 0; // End the program
}
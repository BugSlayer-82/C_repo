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
    if (newNode == NULL)                                               // Check whether memory allocation was successful
    {
        printf("Memory allocation failed\n");
        exit(1); // Stop the program if memory allocation fails
    }
    newNode->data = data; // Store the character in the new node
    newNode->next = top;  // Connect the new node to the current top
    top = newNode;        // Make the new node the new top
    printf("Data Pushed ...\n");
}

char pop()
{
    if (top == NULL) // Check whether the stack is empty
    {
        return '\0'; // Return null character if stack is empty
    }
    struct Node *currNode = top; // Store the current top node
    char data = currNode->data;  // Store the data before deleting the node
    top = top->next;             // Move top to the next node
    free(currNode);              // Free the old top node from memory
    return data;                 // Return the popped character
}

void printStack()
{
    if (top == NULL) // Check whether the stack is empty
    {
        printf("NULL\n");
        return;
    }
    struct Node *currNode = top; // Start traversal from the top
    while (currNode != NULL)     // Continue until the end of the stack
    {
        printf("%c -> ", currNode->data); // Print the current node's data
        currNode = currNode->next;        // Move to the next node
    }
    printf("NULL\n"); // Mark the end of the stack
}

/* 1. Check precedence of operator */
int precedence(char ch)
{
    if (ch == '^')
        return 3; // Highest precedence
    else if (ch == '*' || ch == '/')
        return 2; // Multiplication and division precedence
    else if (ch == '+' || ch == '-')
        return 1; // Addition and subtraction precedence
    return 0;     // Return 0 if character is not an operator
}

/* 2. Check associativity of expression */
char associativity(char ch)
{
    if (ch == '^')
    {
        return 'R'; // ^ is Right Associative
    }
    return 'L'; // Other operators are Left Associative
}

/* 3. Check whether character is an operand */
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
    char exp[100];     // Store the input infix expression
    char postfix[100]; // Store the converted postfix expression

    int i = 0; // Index for input expression
    int j = 0; // Index for postfix expression

    printf("Enter your expression : ");
    scanf("%99s", exp); // Read input and prevent buffer overflow

    for (i = 0; exp[i] != '\0'; i++) // Scan expression character by character
    {
        char ch = exp[i]; // Store the current character
        /* If character is operand */
        if (operand(ch))
        {
            postfix[j++] = ch; // Directly add operand to postfix
        }
        /* If opening parenthesis */
        else if (ch == '(')
        {
            push(ch); // Push opening parenthesis into stack
        }
        /* If closing parenthesis */
        else if (ch == ')')
        {
            // Pop operators until '(' is found
            while (top != NULL && top->data != '(')
            {
                postfix[j++] = pop(); // Remove operator from stack and add to postfix
            }
            if (top != NULL)
            {
                pop(); // Remove '(' from the stack
            }
        }
        /* If character is an operator */
        else
        {
            // Pop operators with higher precedence
            // OR same precedence when current operator is left associative
            while (top != NULL &&
                   top->data != '(' &&
                   (precedence(top->data) > precedence(ch) ||
                    (precedence(top->data) == precedence(ch) &&
                     associativity(ch) == 'L')))
            {
                postfix[j++] = pop(); // Move stack operator to postfix
            }
            push(ch); // Push current operator into the stack
        }
    }

    // After scanning the complete expression, pop all remaining operators
    while (top != NULL)
    {
        postfix[j++] = pop(); // Add remaining operators to postfix
    }
    postfix[j] = '\0'; // Add string terminating character
    printf("Postfix : %s\n", postfix);
    // Stack should be empty after postfix conversion, so this normally prints NULL
    printStack();

    return 0; // End the program
}
#include <stdio.h>  // Provides input/output functions like printf()
#include <stdlib.h> // Provides malloc() and NULL

struct Node // Define a node for the linked-list stack
{
    int data;          // Stores the value of the node
    struct Node *next; // Stores the address of the next node
};

struct Node *top = NULL; // top points to the top node of the stack

void push(int data) // Function to add an element to the stack
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = data;                                              // Store the given value in the new node
    newNode->next = top;                                               // Connect the new node to the current top node
    top = newNode;                                                     // Make the new node the new top
}

int pop() // Function to remove and return the top element
{
    if (top == NULL) // Check whether the stack is empty
    {
        printf("Stack is empty ...! \n"); // Print an empty-stack message
        return -1;                        // Return -1 when there is no element to remove
    }
    struct Node *temp = top; // Store the current top node temporarily
    int value = top->data;   // Store the top element before removing the node
    top = top->next;         // Move top to the next node
    free(temp);              // Free the memory of the removed node
    return value;            // Return the removed value
}

void printStack() // Function to display all stack elements
{
    if (top == NULL) // Check whether the stack is empty
    {
        printf("NULL \n"); // Print NULL when the stack is empty
        return;            // Stop the function
    }
    struct Node *currNode = top; // Start traversing from the top node
    while (currNode != NULL)     // Continue until the end of the linked list
    {
        printf("%d \n", currNode->data); // Print the current node's value
        currNode = currNode->next;       // Move to the next node
    }
}

int postFix(char ch[]) // Function to evalute postfix expression
{
    int i = 0;            // Start from the first character of the expression
    while (ch[i] != '\0') // Continue until the null character is reached
    {
        if (ch[i] >= '0' && ch[i] <= '9') // Check whether the current character is a digit
        {
            push(ch[i] - '0'); // Convert character digit to integer and push it onto the stack
        }
        else // Execute this block when the character is an operator
        {
            int a = pop(); // Pop the first operand from the stack
            int b = pop(); // Pop the second operand from the stack
            switch (ch[i]) // Check which operator is present
            {
            case '+':        // Addition operator
                push(a + b); // Add both operands and push the result
                break;       // Exit the switch
            case '-':        // Subtraction operator
                push(b - a); // Subtract a from b and push the result
                break;       // Exit the switch
            case '*':        // Multiplication operator
                push(a * b); // Multiply both operands and push the result
                break;       // Exit the switch
            case '/':        // Division operator
                if (a != 0)  // Check that the divisor is not zero
                {
                    push(b / a); // Divide b by a and push the result
                }
                else // Execute when the divisor is zero
                {
                    printf("Division by zero error \n"); // Print division-by-zero error
                }
                break;                   // Exit the switch
            default:                     // Execute when an unknown operator is found
                printf("Invalid ch \n"); // Print an invalid-character message
            }
        }
        i++; // Move to the next character
    }
    return pop(); // Pop and return the final result and End the program successfully
}

int main()
{                                            // Program execution starts here
    char ch[] = "724+*2/";                   // Store the postfix expression
    printf("Result ==> %d \n", postFix(ch)); // Print the final result of Postfix Evaluation

    return 0;
}

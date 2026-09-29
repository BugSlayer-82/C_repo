#include <stdio.h> // Provides input/output functions like printf()
#include <stdlib.h> // Provides malloc() and free()

struct Node // Define a node for the linked-list stack
{
    int data; // Stores the data of the node
    struct Node *next; // Stores the address of the next node
};
struct Node *top = NULL; // top points to the top node of the stack
void push(int data) // Function to add an element to the stack
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = data; // Store the given data in the new node
    newNode->next = top; // Connect the new node to the current top node
    top = newNode; // Make the new node the top of the stack
}

int pop() // Function to remove and return the top element
{
    if (top == NULL) // Check whether the stack is empty
    {
        printf("Stack is empty ...! \n"); // Print an empty-stack message
        return -1; // Return -1 when the stack is empty
    }
    struct Node *temp = top; // Store the current top node temporarily
    int value = top->data; // Store the top element before removing the node
    top = top->next; // Move top to the next node
    free(temp); // Free the memory of the removed node
    return value; // Return the removed value
}

int isOperator(char ch) // Function to check whether a character is an operator
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') // Check for valid operators
    {
        return 1; // Return 1 if the character is an operator
    }
    return 0; // Return 0 if the character is not an operator
}

int power(int a, int b) // Function to calculate a raised to the power b
{
    int result = 1; // Store the result and start with 1
    for (int i = 1; i <= b; i++) // Repeat multiplication b times
    {
        result *= a; // Multiply result by a
    }
    return result; // Return the calculated power
}

int preFix(char exp[]) // Function to evaluate a prefix expression
{
    int i; // Store the index used to traverse the expression
    for (i = 0; exp[i] != '\0'; i++) // Find the end of the expression
        ;
    i--; // Move i back to the last character
    while (i >= 0) // Traverse the expression from right to left
    {
        if (exp[i] >= '0' && exp[i] <= '9') // Check whether the current character is a digit
        {
            push(exp[i] - '0'); // Convert character digit to integer and push it onto the stack
        }
        else if (isOperator(exp[i])) // Check whether the current character is an operator
        {
            int a = pop(); // Pop the first operand from the stack
            int b = pop(); // Pop the second operand from the stack
            switch (exp[i]) // Check which operator is present
            {
                case '+': // Addition operator
                    push(a + b); // Add both operands and push the result
                    break; // Exit the switch
                case '-': // Subtraction operator
                    push(a - b); // Subtract b from a and push the result
                    break; // Exit the switch
                case '*': // Multiplication operator
                    push(a * b); // Multiply both operands and push the result
                    break; // Exit the switch
                case '/': // Division operator
                    if (b != 0) // Check that the divisor is not zero
                    {
                        push(a / b); // Divide a by b and push the result
                    }
                    else // Execute when the divisor is zero
                    {
                        printf("Division by 0 Error ...! \n"); // Print division-by-zero error
                    }
                    break; // Exit the switch
                case '^': // Power operator
                    push(power(a, b)); // Calculate a raised to b and push the result
                    break; // Exit the switch
                default: // Execute for an invalid operator
                    printf("Invalid operator / operand ... !"); // Print an invalid expression message
            }
        }
        i--; // Move to the previous character
    }
    return pop(); // Pop and return the final result
}

void printStack() // Function to display all elements of the stack
{
    if (top == NULL) // Check whether the stack is empty
    {
        printf("NULL \n"); // Print NULL when the stack is empty
        return; // Stop the function
    }
    struct Node *currNode = top; // Start traversing from the top node
    while (currNode != NULL) // Continue until the end of the linked list
    {
        printf("%d \n", currNode->data); // Print the current node's data
        currNode = currNode->next; // Move to the next node
    }
}

int main() // Program execution starts here
{
    char exp[] = "+*23*54"; // Store the prefix expression
    printf("Result : %d \n", preFix(exp)); // Evaluate the prefix expression and print the result
    return 0; // End the program successfully
}


#include <stdio.h>
#include <stdlib.h>

// // /* =============>>> Stack Implementation Using Array <<<================== */
// // Define the maximum number of elements that the stack can store.
// #define SIZE 5
// int stack[SIZE]; // Create an integer array to store the stack elements.
// int top = -1;    // top stores the index of the top element , -1 means the stack is currently empty.

// // /* =========>>> Function Prototype for Basic Operation on Stack <<<=========== */
// void push(int data); // Function prototype for adding an element to the stack.
// void pop();          // Function prototype for removing the top element from the stack.
// void peek();         // Function prototype for viewing the top element without removing it.
// void printStack();   // Function prototype for printing all elements of the stack.
// int size();          // Function prototype for returning the current number of elements.

// int main()
// {
//     push(1); // Add 1 to the stack.
//     push(2); // Add 2 to the stack.
//     push(3); // Add 3 to the stack.
//     push(4); // Add 4 to the stack.
//     push(5); // Add 5 to the stack.
//     push(6); // Try to add 6 when the stack is already full. This will cause Stack Overflow.
//     printStack();                     // Print all elements currently present in the stack.
//     peek();                           // Display the top element without removing it.
//     pop();                            // Remove the top element from the stack.
//     printf("Size --> %d \n", size()); // Find and print the current number of elements in the stack.
//     printStack();                     // Print the stack after removing one element.
//     return 0;                         // Return 0 to indicate successful execution.
// }

// // 1 =====>> Function to add an element to the top of the stack.
// void push(int data)
// {
//     if (top == SIZE - 1) // Check whether the stack is already full.
//     {
//         printf("Stack Overflow ! \n"); // Print an error message when there is no space for a new element.
//         return;                        // Stop the function because the element cannot be added.
//     }
//     top++;             // Increase top to point to the next empty position.
//     stack[top] = data; // Store the new data at the top position.
// }

// // 2 =====>> Function to remove the top element from the stack.
// void pop()
// {
//     if (top == -1) // Check whether the stack is empty.
//     {
//         printf("Stack Underflow ! \n"); // Print an error message because there is nothing to remove.
//         return;                         // Stop the function.
//     }
//     printf("Pop data --> %d \n", stack[top]); // Print the element that is going to be removed.
//     top--;                                    // Decrease top so that the current top element is removed logically.
// }

// // 3 =====>> Function to view the top element without removing it.
// void peek()
// {
//     if (top == -1) // Check whether the stack is empty.
//     {
//         printf("Stack Underflow ! \n"); // Print an error message because there is no top element.
//         return;                         // Stop the function.
//     }
//     printf("Peek data --> %d \n", stack[top]); // Print the element currently present at the top of the stack.
// }

// // 4 =====>>Function to print all elements of the stack.
// void printStack()
// {
//     if (top == -1) // Check whether the stack is empty.
//     {
//         printf("Stack is empty ! \n"); // Print a message when the stack contains no elements.
//         return;                        // Stop the function.
//     }
//     int temp = top;    // Create a temporary variable starting from the top index.
//     while (temp != -1) // Continue until temp reaches -1.
//     {
//         printf("Data : %d \n", stack[temp]); // Print the current stack element.
//         temp--;                              // Move to the next element below the current element.
//     }
// }

// // 5 =====>> Function to calculate and return the current size of the stack.
// int size()
// {
//     if (top == -1) // Check whether the stack is empty.
//     {
//         return 0; // Return 0 because there are no elements.
//     }
//     int count = 0;     // Variable used to count the number of elements.
//     int temp = top;    // Start counting from the top element.
//     while (temp != -1) // Continue until temp reaches -1.
//     {
//         count++; // Increase the count for every stack element.
//         temp--;  // Move to the next element below the current element.
//     }
//     return count; // Return the total number of elements in the stack.
// }

// /* =============>>> Stack Implementation Using Linked List <<<================== */
struct Node
{
    int data;          // Store the value of the stack element.
    struct Node *next; // Store the address of the next node.
};

struct Node *top = NULL; // Create the top pointer and initially set it to NULL because the stack is empty.

// /* =========>>> Function Prototype for Basic Operations on Stack <<<=========== */

void push(int data); // Function prototype for adding an element to the stack.
void pop();          // Function prototype for removing the top element from the stack.
int peek();          // Function prototype for viewing the top element without removing it.
void printStack();   // Function prototype for printing all elements of the stack.
int size();          // Function prototype for returning the current number of elements.

int main()
{
    push(1);                                   // Add 1 to the top of the stack.
    push(2);                                   // Add 2 to the top of the stack.
    push(3);                                   // Add 3 to the top of the stack.
    push(4);                                   // Add 4 to the top of the stack.
    push(5);                                   // Add 5 to the top of the stack.
    printStack();                              // Print all elements of the stack.
    pop();                                     // Remove the top element from the stack.
    printf("Peek data --> %d \n", peek());     // View and print the current top element.
    pop();                                     // Remove the current top element from the stack.
    printStack();                              // Print the stack after removing two elements.
    printf("Size of stack --> %d \n", size()); // Calculate and print the current size of the stack.
    return 0;                                  // Return 0 to indicate successful execution.
}

// 1 =====>> Function to add an element to the top of the stack.
void push(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create a new node dynamically in memory.
    newNode->data = data;                                              // Store the given data in the new node.
    newNode->next = top;                                               // Make the new node point to the current top node.
    top = newNode;                                                     // Make the new node the new top of the stack.
}

// 2 =====>> Function to remove the top element from the stack.
void pop()
{
    if (top == NULL) // Check whether the stack is empty.
    {
        printf("Stack is Underflow ..! \n"); // Print an error message because there is no element to remove.
        return;                              // Stop the function.
    }
    struct Node *temp = top;                      // Store the current top node in a temporary pointer.
    top = top->next;                              // Move top to the next node.
    printf("Deleted data ==> %d \n", temp->data); // Print the data of the node being deleted.
    free(temp);                                   // Free the memory occupied by the deleted node.
}

// 3 =====>> Function to view the top element without removing it.
int peek()
{
    if (top == NULL) // Check whether the stack is empty.
    {
        printf("Stack is Underflow ..! \n"); // Print an error message because there is no top element.
        return -1;                           // Return -1 to indicate that the stack is empty.
    }
    return top->data; // Return the data stored in the top node.
}

// 4 =====>>Function to print all elements of the stack.
void printStack()
{
    if (top == NULL) // Check whether the stack is empty.
    {
        printf("Stack is Empty ...!\n"); // Print a message because the stack has no elements.
        return;                          // Stop the function.
    }
    struct Node *currTop = top; // Create a temporary pointer starting from the top node.
    while (currTop != NULL)     // Continue traversing until the end of the linked list.
    {
        printf("Data --> %d \n", currTop->data); // Print the data of the current node.
        currTop = currTop->next;                 // Move to the next node.
    }
}

// 5 =====>> Function to calculate and return the current size of the stack.
int size()
{
    int count = 0;   // Create a variable to count the number of nodes.
    if (top == NULL) // Check whether the stack is empty.
    {
        return 0; // Return 0 because the stack contains no elements.
    }
    struct Node *currTop = top; // Create a temporary pointer starting from the top node.
    while (currTop != NULL)     // Continue traversing until the end of the stack.
    {
        count++;                 // Increase the count for the current node.
        currTop = currTop->next; // Move to the next node.
    }
    return count; // Return the total number of elements in the stack.
}
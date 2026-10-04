#include <stdio.h>  // Provides printf()
#include <stdlib.h> // Provides malloc() and free()

struct Node // Defines a node for the deque
{
    int data;          // Stores the data
    struct Node *prev; // Points to the previous node
    struct Node *next; // Points to the next node
};

struct Node *front = NULL; // Points to the first node
struct Node *rear = NULL;  // Points to the last node

int isEmpty() // Function to check whether the deque is empty
{
    if (rear == NULL && rear == NULL) // Check whether both pointers are NULL
    {
        return 1; // Return 1 if the deque is empty
    }
    return 0; // Return 0 if the deque is not empty
}

void insertFront(int data) // Function to insert a node at the front
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create a new node dynamically
    newNode->data = data;  // Store data in the new node
    newNode->prev = NULL;  // New front has no previous node
    newNode->next = front; // New node points to the current front
    if (isEmpty()) // Check whether the deque is empty
    {
        front = rear = newNode; // Make the new node both front and rear
        printf("Element inserted at front ...!\n"); // Print insertion message
        return; // Stop the function
    }
    front->prev = newNode; // Current front points back to the new node
    front = newNode;       // Make the new node the new front
    printf("Element inserted at front ...!\n"); // Print insertion message
}

void insertRear(int data) // Function to insert a node at the rear
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create a new node dynamically
    newNode->data = data; // Store data in the new node
    newNode->prev = rear; // New node points back to the current rear
    newNode->next = NULL; // New rear has no next node
    if (isEmpty()) // Check whether the deque is empty
    {
        front = rear = newNode; // Make the new node both front and rear
    }
    else
    {
        rear->next = newNode; // Current rear points to the new node
        rear = newNode;       // Make the new node the new rear
    }
    printf("Element inserted at rear...!\n"); // Print insertion message
}

void deleteFront() // Function to delete a node from the front
{
    if (isEmpty()) // Check whether the deque is empty
    {
        printf("Queue is Empty ..! \n"); // Print empty deque message
        return; // Stop the function
    }
    struct Node *temp = front; // Store the current front temporarily
    printf("Data deleted from front: %d \n", temp->data); // Print the data being deleted
    if (front == rear) // Check whether there is only one node
    {
        front = rear = NULL; // Reset both pointers because deque becomes empty
    }
    else
    {
        front = front->next; // Move front to the next node
        front->prev = NULL;  // New front has no previous node
    }
    free(temp); // Free the memory of the deleted node
}

void deleteRear() // Function to delete a node from the rear
{
    if (isEmpty()) // Check whether the deque is empty
    {
        printf("Queue is Empty ..! \n"); // Print empty deque message
        return; // Stop the function
    }
    struct Node *currNode = rear; // Store the current rear temporarily
    printf("Data deleted from rear : %d \n", rear->data); // Print the data being deleted
    if (front == rear) // Check whether there is only one node
    {
        front = rear = NULL; // Reset both pointers because deque becomes empty
    }
    else
    {
        rear = rear->prev; // Make the previous node the new rear
        rear->next = NULL; // Remove the link from the new rear to the deleted node
    }
    free(currNode); // Free the memory of the deleted node
}

void printFront() // Function to print the deque from front to rear
{
    if (isEmpty()) // Check whether the deque is empty
    {
        printf("NULL\n"); // Print NULL for an empty deque
        return; // Stop the function
    }

    struct Node *currNode = front; // Start traversal from the front node
    while (currNode != NULL) // Continue until the end of the deque
    {
        printf("%d -> ", currNode->data); // Print the current node's data
        currNode = currNode->next; // Move to the next node
    }
    printf("NULL\n"); // Print NULL after the last node
}

void printRear() // Function to print the deque from rear to front
{
    if (isEmpty()) // Check whether the deque is empty
    {
        printf("NULL\n"); // Print NULL for an empty deque

        return; // Stop the function
    }
    struct Node *currNode = rear; // Start traversal from the rear node

    while (currNode != NULL) // Continue until the beginning of the deque
    {
        printf("%d -> ", currNode->data); // Print the current node's data
        currNode = currNode->prev; // Move to the previous node
    }
    printf("NULL\n"); // Print NULL after the last node
}

int main() // Program execution starts here
{
    insertFront(30); // Insert 30 at the front
    insertFront(20); // Insert 20 at the front
    insertFront(10); // Insert 10 at the front
    insertRear(40); // Insert 40 at the rear
    insertRear(50); // Insert 50 at the rear
    insertRear(60); // Insert 60 at the rear
    printFront(); // Print the deque from front to rear
    printRear();  // Print the deque from rear to front
    deleteFront(); // Delete the front element (10)
    deleteRear();  // Delete the rear element (60)
    printFront(); // Print the deque from front to rear
    printRear();  // Print the deque from rear to front

    return 0; // End the program successfully
}
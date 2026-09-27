#include <stdio.h>                  // Provides printf()
#include <stdlib.h>                 // Provides malloc() and free()

struct Node                          // Define a node for the queue
{
    int data;                        // Stores the queue element
    struct Node *next;               // Stores the address of the next node
};
struct Node *front = NULL;           // Points to the first node of the queue
struct Node *rear = NULL;            // Points to the last node of the queue

int isEmpty()                        // Function to check whether the queue is empty
{
    if (front == NULL && rear == NULL) // Check if both front and rear are NULL
    {
        return 1;                    // Return 1 when the queue is empty
    }
    return 0;                        // Return 0 when the queue is not empty
}

void offer(int data)                 // Function to insert an element into the queue
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create a new node dynamically
    newNode->data = data;            // Store the given data in the new node
    newNode->next = NULL;            // New node is initially the last node
    if (isEmpty())                   // Check whether the queue is empty
    {
        front = rear = newNode;      // Make the new node both front and rear
        printf("Inserted\n");        // Print insertion message
        return;                      // Stop the function
    }
    rear->next = newNode;            // Connect the current rear node to the new node
    rear = newNode;                  // Move rear to the new node
    printf("Inserted\n");            // Print insertion message
}

void dequeue()                       // Function to remove the front element
{
    if (isEmpty())                   // Check whether the queue is empty
    {
        printf("Queue is empty ....! \n"); // Print empty queue message
        return;                      // Stop the function
    }
    struct Node *temp = front;        // Store the current front node temporarily
    printf("Data Deleted : %d  \n", front->data); // Print the data being deleted
    if (front == rear)               // Check whether there is only one node
    {
        front = rear = NULL;          // Reset both pointers because queue becomes empty
    }
    else
    {
        front = front->next;          // Move front to the next node
    }
    free(temp);                       // Free the memory of the deleted node
}

void printQueue()                     // Function to display all queue elements
{
    if (isEmpty())                    // Check whether the queue is empty
    {
        printf("NULL \n");            // Print NULL for an empty queue
        return;                       // Stop the function
    }
    struct Node *currNode = front;    // Start traversal from the front node
    while (currNode != NULL)          // Continue until the end of the queue
    {
        if (currNode->next != NULL)   // Check whether the current node is not the last node
        {
            printf("%d -> ", currNode->data); // Print data followed by an arrow
        }
        else
        {
            printf("%d \n", currNode->data);  // Print the last element and move to next line
        }
        currNode = currNode->next;    // Move to the next node
    }
}

int main()                            // Program execution starts here
{
    offer(10);                        // Insert 10 into the queue
    offer(20);                        // Insert 20 into the queue
    offer(30);                        // Insert 30 into the queue
    offer(40);                        // Insert 40 into the queue
    offer(50);                        // Insert 50 into the queue
    printQueue();                     // Display all queue elements
    dequeue();                        // Delete the front element (10)
    dequeue();                        // Delete the next front element (20)
    printQueue();                     // Display the remaining queue elements

    return 0;                         // End the program successfully
}
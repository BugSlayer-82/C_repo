#include <stdio.h>                  // Provides printf()
#include <stdlib.h>                 // Provides malloc() and free()

struct Node                         // Defines a node for the circular queue
{
    int data;                       // Stores the queue element
    struct Node *next;              // Points to the next node
};

struct Node *front = NULL;          // Points to the first node of the queue
struct Node *rear = NULL;           // Points to the last node of the queue

int isEmpty()                       // Function to check whether the queue is empty
{
    if (front == NULL && rear == NULL) // Check whether both front and rear are NULL
    {
        return 1;                   // Return 1 if the queue is empty
    }
    return 0;                       // Return 0 if the queue is not empty
}

void enqueue(int data)              // Function to insert an element into the queue
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create a new node dynamically
    if (newNode == NULL)            // Check whether memory allocation failed
    {   // case 1 -> newNode is empty
        printf("Memory allocation failed ...! \n"); // Print memory allocation error

        return;                     // Stop the function
    }
    newNode->data = data;            // Store the given data in the new node
    if (isEmpty())                  // Check whether the queue is empty
    {   // case 2 -> Queue is empty
        front = rear = newNode;     // Make the new node both front and rear
        newNode->next = front;      // Make the node point back to front and create circular link
        printf("Element inserted in Queue ...\n"); // Print insertion message
        return;                     // Stop the function
    }
    rear->next = newNode;           // Current rear points to the new node
    newNode->next = front;          // New node points back to front
    rear = newNode;                 // Make the new node the new rear
    printf("Element inserted in Queue ...\n"); // Print insertion message
}

void dequeue()                      // Function to delete the front element
{
    if (isEmpty())                  // Check whether the queue is empty
    {
        printf("Queue is empty ..! \n"); // Print empty queue message
        return;                     // Stop the function
    }
    struct Node *temp = front;      // Store the current front node temporarily
    printf("Data Deleted : %d \n", front->data); // Print the data being deleted
    if (front == rear)              // Check whether there is only one node
    {
        front = rear = NULL;        // Reset both pointers because queue becomes empty
    }
    else
    {
        front = front->next;        // Move front to the next node
        rear->next = front;         // Make rear point to the new front
    }
    free(temp);                     // Free the memory of the deleted node
}

void printQueue()                   // Function to display all queue elements
{
    if (isEmpty())                  // Check whether the queue is empty
    {
        printf("NULL \n");          // Print NULL for an empty queue
        return;                     // Stop the function
    }
    struct Node *currNode = front;  // Start traversal from the front node
    do                              // Execute the loop at least once
    {
        printf("%d -> ", currNode->data); // Print the current node's data
        currNode = currNode->next;  // Move to the next node
    }
    while (currNode != front);      // Stop when we reach the front again
    printf("NULL \n");              // Show the end of the circular traversal
}

int main()                          // Program execution starts here
{
    enqueue(10);                    // Insert 10 into the queue
    enqueue(20);                    // Insert 20 into the queue
    enqueue(30);                    // Insert 30 into the queue
    enqueue(40);                    // Insert 40 into the queue
    enqueue(50);                    // Insert 50 into the queue
    enqueue(60);                    // Insert 60 into the queue
    printQueue();                   // Display all queue elements
    dequeue();                      // Delete 10 from the fron
    printQueue();                   // Display the remaining queue
    dequeue();                      // Delete 20 from the front
    dequeue();                      // Delete 30 from the front
    printQueue();                   // Display the remaining queue

    return 0;                       // End the program successfully
}
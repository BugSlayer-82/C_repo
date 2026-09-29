#include <stdio.h>  // Provides printf()
#include <stdlib.h> // Provides standard library functions

#define SIZE 5 // Defines the maximum size of the queue as 5

int queue[SIZE]; // Creates an integer array to store queue elements
int front = -1;  // front = -1 means the queue is initially empty
int rear = -1;   // rear = -1 means no element has been inserted yet

void offer(int data)
{ // Function to insert an element into the queue
    if (rear == SIZE - 1)
    {                                   // Check whether the rear has reached the last index
        printf("Queue is full ...!\n"); // Print message when queue is full
        return;                         // Stop the function without inserting the element
    }
    rear++;             // Move rear to the next available position
    queue[rear] = data; // Store the new data at the rear position
    if (front == -1)
    {                                 // Check whether this is the first element
        front = 0;                    // Set front to index 0
        printf("Front shift to 0\n"); // Show that front is moved to index 0
    }
    printf("Data inserted\n"); // Print message after successful insertion
}

int delete()
{ // Function to remove and return the front element
    if (rear == -1 && front == -1)
    {                                    // Check whether the queue is empty
        printf("Queue is empty ...!\n"); // Print empty queue message
        return -1;                       // Return -1 because there is nothing to delete
    }
    int data = queue[front]; // Store the front element before deleting it
    front++;                 // Move front to the next element
    if (front > rear)
    {               // Check whether all elements have been deleted
        front = -1; // Reset front to indicate an empty queue
        rear = -1;  // Reset rear to indicate an empty queue
    }
    return data; // Return the deleted element
}

void printQueue()
{ // Function to display all queue elements
    if (rear == -1 && front == -1)
    {                                    // Check whether the queue is empty
        printf("Queue is empty ...!\n"); // Print empty queue message
        return;                          // Stop the function
    }

    for (int i = front; i <= rear; i++)
    {                             // Traverse from front to rear
        printf("%d\n", queue[i]); // Print each queue element
    }
}

int main()
{                                            // Program execution starts here
    offer(10);                               // Insert 10 into the queue
    offer(20);                               // Insert 20 into the queue
    offer(30);                               // Insert 30 into the queue
    offer(40);                               // Insert 40 into the queue
    offer(50);                               // Insert 50 into the queue
    printf("Deleted Data : %d\n", delete()); // Delete and print the front element
    // printf("%d \n", delete());          // Delete the next element if uncommented
    // printf("%d \n", delete());          // Delete the next element if uncommented
    // printf("%d \n", delete());          // Delete the next element if uncommented
    // printf("%d \n", delete());          // Delete the next element if uncommented
    printQueue(); // Display the remaining queue elements

    return 0; // End the program successfully
}
#include <stdio.h> // Provides printf()

#define MAX 5 // Defines the maximum queue size as 5

int Queue[MAX]; // Array used to store queue elements

int front = -1; // front = -1 means queue is empty
int rear = -1;  // rear = -1 means queue is empty

int isEmpty() // Function to check whether queue is empty
{
    return (rear == -1 && front == -1); // Returns 1 if both front and rear are -1
}

int isFull() // Function to check whether queue is full
{
    return ((rear + 1) % MAX == front); // Next position of rear is front means queue is full
}

void offer(int data) // Function to insert data into the circular queue
{
    if (isFull())                       // Check whether the queue is already full
    {                                   // Case for full
        printf("Queue is Full ...!\n"); // Print full queue message
        return;                         // Stop insertion
    }
    if (isEmpty())        // Check whether the queue is empty
    {                     // Case for empty
        front = rear = 0; // Set both front and rear to index 0
    }
    else // Queue already contains elements
    {
        rear = (rear + 1) % MAX; // Move rear forward and wrap around when needed
    }
    Queue[rear] = data; // Store the new element at the rear position
    printf("Data inserted ...! \n"); // Print insertion message
}

/*
void offer(int data)               // Alternative way to implement offer()
{
    if ((rear + 1) % MAX == front) // Check whether the circular queue is full
    {
        printf("Queue is full ...! \n"); // Print full queue message
        return;                    // Stop insertion
    }

    if (front == -1 && rear == -1) // Check whether the queue is empty
    {
        front = rear = 0;          // Set front and rear to index 0
        Queue[front] = data;       // Insert data at index 0
    }
    else if (rear == MAX - 1 && front != 0) // Check if rear is at last index but space exists at beginning
    {
        rear = 0;                  // Wrap rear around to index 0
        Queue[rear] = data;        // Insert data at index 0
    }
    else
    {
        rear++;                    // Move rear to the next index
        Queue[rear] = data;        // Insert data at the new rear position
    }

    printf("Data Inserted ...!\n"); // Print insertion message
}
*/

int poll() // Function to remove and return the front element
{
    if (isEmpty()) // Check whether the queue is empty
    {
        printf("Queue is Empty ...! \n"); // Print empty queue message
        return -1;                        // Return -1 because there is nothing to remove
    }
    int data = Queue[front]; // Store the front element before removing it
    if (front == rear) // Check whether there is only one element
    {
        front = rear = -1; // Reset queue to empty state
    }
    else
    {
        front = (front + 1) % MAX; // Move front forward and wrap around if necessary
    }
    return data; // Return the removed element
}

void printQueue() // Function to display all queue elements
{
    if (isEmpty()) // Check whether the queue is empty
    {
        printf("Queue is empty ...! \n"); // Print empty queue message
        return;                           // Stop the function
    }
    if (front <= rear) // Case where queue elements are in a normal continuous range
    {
        for (int i = front; i <= rear; i++) // Traverse from front to rear
        {
            printf("%d ", Queue[i]); // Print each queue element
        }
        printf("\n"); // Move to the next line
    }
    else // Case where queue has wrapped around
    {
        for (int i = front; i <= MAX - 1; i++) // Print elements from front to last index
        {
            printf("%d ", Queue[i]); // Print each element
        }
        for (int i = 0; i <= rear; i++) // Print elements from index 0 to rear
        {
            printf("%d ", Queue[i]); // Print each element
        }
        printf("\n"); // Move to the next line
    }
}

int main() // Program execution starts here
{
    offer(1); // Insert 1
    offer(2); // Insert 2
    offer(3); // Insert 3
    offer(4); // Insert 4
    offer(5); // Insert 5
    offer(6); // Try to insert 6; queue is full, so insertion fails
    printf("Deleted Data : %d \n", poll()); // Remove and print the front element (1)
    printf("Deleted Data : %d \n", poll()); // Remove and print the front element (2)
    printf("Deleted Data : %d \n", poll()); // Remove and print the front element (3)

    printQueue(); // Display the remaining queue elements

    return 0; // End the program successfully
}
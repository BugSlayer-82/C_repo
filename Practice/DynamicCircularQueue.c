#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty()
{
    if (front == NULL && rear == NULL)
    {
        return 1;
    }
    return 0;
}
void enqueue(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    { // case 1 -> newNode is empty
        printf("Memory allocation failed ...! \n");
        return;
    }
    newNode->data = data;
    if (isEmpty()) // case 2 -> Queue is empty
    {
        front = rear = newNode;
        newNode->next = front;
        printf("Element inserted in Queue ...\n");
        return;
    }
    rear->next = newNode;  // Rear points to newNode
    newNode->next = front; // newNode points to front
    rear = newNode;        // Rear become newNode
    printf("Element inserted in Queue ...\n");
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty ..! \n");
        return;
    }
    struct Node *temp = front;
    printf("Data Deleted : %d \n", front->data);
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next; // front moves to the next of front 
        rear -> next = front; // rear -> next points to front 
    }
    free(temp); // free the deleted memory
}

void printQueue()
{
    if (isEmpty())
    {
        printf("NULL \n");
        return;
    }
    struct Node *currNode = front;
    do
    {
        printf("%d -> ", currNode->data);
        currNode = currNode->next;
    } while (currNode != front);
    printf("NULL \n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    printQueue();
    dequeue();
    printQueue();
    dequeue();
    dequeue();
    printQueue();

    return 0;
}
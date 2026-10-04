#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty()
{
    if (rear == NULL && rear == NULL)
    {
        return 1;
    }
    return 0;
}

void insertFront(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;  // prev of newNode points to null
    newNode->next = front; // newNode points to front

    if (isEmpty())
    {
        front = rear = newNode;
        printf("Element inserted at front ...!\n");
        return;
    }
    front->prev = newNode; // prev of front points to newNode
    front = newNode;       // newNode become front
    printf("Element inserted at front ...!\n");
}

void insertRear(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = rear;
    newNode->next = NULL;
    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Element inserted at rear...!\n");
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("Queue is Empty ..! \n");
        return;
    }
    struct Node *temp = front;
    printf("Data deleted from front: %d \n", temp->data);
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next; // Front moves to next of front
        front->prev = NULL;  // Prev of front points to NULL
    }
    free(temp);
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("Queue is Empty ..! \n");
        return;
    }
    struct Node *currNode = rear;
    printf("Data deleted from rear : %d \n", rear->data);
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        rear->next = NULL;
    }
    free(currNode);
}

void printFront()
{
    if (isEmpty())
    {
        printf("NULL \n");
        return;
    }
    struct Node *currNode = front;
    while (currNode != NULL)
    {
        printf("%d -> ", currNode->data);
        currNode = currNode->next;
    }
    printf("NULL \n");
}

void printRear()
{
    if (isEmpty())
    {
        printf("NULL\n");
        return;
    }
    struct Node *currNode = rear;
    while (currNode != NULL)
    {
        printf("%d -> ", currNode->data);
        currNode = currNode->prev;
    }
    printf("NULL \n");
}

int main()
{
    insertFront(30);
    insertFront(20);
    insertFront(10);
    insertRear(40);
    insertRear(50);
    insertRear(60);
    printFront();
    printRear();
    deleteFront();
    deleteRear();
    printFront();
    printRear();

    return 0;
}
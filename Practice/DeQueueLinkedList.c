#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

void insertRear(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void deleteFront()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is Empty ..! \n");
        return;
    }
    struct Node *temp = front;
    printf("Data deleted : %d \n", front->data);
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
}

void insertFront(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = front;

    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
        return;
    }
    front = newNode;
}

void deleteRear()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is Empty ..! \n");
        return;
    }
    struct Node *temp = front;
    printf("Data deleted : %d \n", rear->data);
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        while (temp->next != rear)
        {
            temp = temp->next;
        }
        rear = temp;
        temp = temp->next;
        rear->next = NULL;
    }
    free(temp);
}

int main()
{

    return 0;
}
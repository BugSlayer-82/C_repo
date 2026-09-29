#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};
struct Node *top = NULL;

void push(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("Data Inserted ... \n");
}

char pop()
{
    if(top == NULL){
        return '1';
    }
    struct Node *currNode = top;
    char data = currNode->data;
    top = top->next;
    free(currNode);
    return data;
}

void printList()
{
    if (top == NULL)
    {
        printf("NULL \n");
        return;
    }
    struct Node *currNode = top;
    while (currNode != NULL)
    {
        printf("%c -> ", currNode->data);
        currNode = currNode->next;
    }
    printf("NULL \n");
}

int main()
{
    // push('a');
    // push('g');
    // push('r');
    // push('u');
    printList();

    return 0;
}
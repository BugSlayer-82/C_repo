#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node * front = NULL;
struct Node * rear = NULL;

int isEmpty(){
    if(front == NULL && rear == NULL)
    {
        return 1;
    }
    return 0;
}
void enqueue(int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = front;
    if(isEmpty()){
        front = rear = newNode;
        return;
    }
    rear -> next = newNode;
    rear = newNode;
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is empty ..! \n");
        return;
    }
    
    struct Node * temp = front;
    printf("Data Deleted : %d \n",front -> data);
    if(front == rear){
        front = rear = NULL;
    }else{
        front = front -> next;
    }
    free(temp);
}

void printQueue(){
    if(isEmpty()){
        printf("NULL \n");
        return;
    }
    struct Node *currNode = front;
    while(currNode != rear){
        printf("%d -> ",currNode -> data);
        currNode = currNode -> next;
    }
}

int main(){

    return 0;
}
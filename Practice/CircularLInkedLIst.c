#include <stdio.h>
#include <stdlib.h>

void addFirst(int data);
void addLast(int data);
void deleteFirst();
void deleteLast();
void printList();

struct Node {
    int data;
    struct Node *next;
};

struct Node * head = NULL;

int main(){
    addFirst(10);
    addFirst(20);
    addFirst(30);
    addFirst(40);
    addLast(50);
    addLast(60);
    addLast(70);
    addLast(80);    
    printList();

    return 0;
}

/* Add First */
void addFirst(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    if(head == NULL){
        head = newNode;
        head -> next = head;
        return;
    }  
    struct Node * currNode = head;
    while(currNode -> next != head){
        currNode = currNode -> next;
    }
    newNode->next = head;
    currNode -> next = newNode;
    head = newNode;
}

/* Add Last */
void addLast(int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = data;
    if(head == NULL){ 
        head = newNode;
        head -> next = head;
        return;
    }
    struct Node * currNode = head;
    do{
        currNode = currNode -> next;
    }while(currNode -> next != head);
    newNode -> next = head;
    currNode -> next = newNode;
}

/* Print List */
void printList(){
    if(head == NULL){
        printf("NULL \n");
        return ;
    }
    struct Node * currNode = head;
    do{
        printf("%d -> ",currNode -> data);
        currNode = currNode -> next;
    }while(currNode != head);
    printf("NULL \n");
}
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

    if(newNode == NULL){
        printf("Memory allocation failed ...!")
        ;
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

char pop()
{
    if (top == NULL)
    {
        printf("Stack is empty ..!\n");
        return '\0';
    }
    struct Node *temp = top;
    char ch = temp->data;
    top = top->next;
    free(temp);
    return ch;
}

void printStack()
{
    if (top == NULL)
    {
        printf("empty\n");
        return;
    }
    struct Node *currNode = top;
    while (currNode != NULL)
    {
        printf("%c", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

/* 1 Check precendence of Operator */
int precedence()
{

}

/* 2 Check associativity of Operator */
char associativity(char ch)
{
    if (ch == '^')
    {
        return 'R';
    }
    return 'L';
}

/* 3 Check is operand */
int operator(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= 0 && ch <= 9))
    {
        return 1;
    }
    return -1;
}

/* 4 Reverse  the expression*/
void reverse(char exp[])
{
    int i = 0, j = 0;
    while (exp[i] != '\0')
    {
        i++;
    }
    i--;
    while (j < i)
    {
        char ch = exp[j];
        exp[j] = exp[i];
        exp[i] = ch;
        j++;
        i--;
    }
}

int main()
{
    char exp[] = "4+5*(8/3)*4-2*3";
    reverse(exp);
    // int i = 0;
    // while (exp[i] != '\0')
    // {
    //     printf("%c ", exp[i]);
    //     i++;
    // }

    
    return 0;
}
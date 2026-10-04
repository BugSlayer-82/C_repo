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
    printf("Data Pushed ... \n");
}

char pop()
{
    if (top == NULL)
    {
        return '\0';
    }
    struct Node *currNode = top;
    char data = currNode->data;
    top = top->next;
    free(currNode);
    return data;
}

void printStack()
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

/* 1 Check precedence of operator */
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

/* 2 Check associativity of expression */
char associativity(char ch)
{
    if (ch == '^')
    {
        return 'R';
    }
    return 'L';
}

/* 3 Check operator */
int operand(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= 0 && ch <= 9))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char exp[100] = "2+4+5*(3/2)*3+7";
    // char postfix[100];
    printf("%s",exp);
    int i=0, j = 0;
    while(exp[i]!='\0'){
        push(exp[i]);
        i++;
    }
//     printf("Enter your expression : ");
//     scanf("%s", exp);
//     for (i = 0; exp[i] != '\0'; i++)
//     {
//         char ch = exp[i];
//         if (operand(ch))
//         {
//             postfix[j++] = ch;
//         }
//         else if (ch == '(')
//         {
//             push(ch);
//         }
//         else if (ch == ')')
//         {
//             while (top != NULL && top->data != ')')
//             {
//                 postfix[j++] = pop();
//             }
//             if (top != NULL)
//             {
//                 pop();
//             }
//         }
//         else
//         {
//             while (top != NULL && top->data != '(' && (precedence(top->data) > precedence(ch) || (precedence(top->data) == precedence(ch) && associativity(ch) == 'L')))
//             {
//                 postfix[j++] = pop();
//             }
//             push(ch);
//         }
//     }
//     while (top != NULL)
//     {
//         postfix[j++] = pop();
//     }
//     postfix[j] = '\0';
//     printf("Postfix : %s \n", postfix);

//     return 0;

    printStack();

    return 0;
}
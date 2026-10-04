#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int expo;
    struct Node *next;
};

/* Insert expression to list */
struct Node *insert(struct Node *head, int cof, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = cof;
    newNode->expo = exp;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *currNode = head;
        while (currNode->next != NULL)
        {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
    return head;
}

void freeList(struct Node *head)
{
    struct Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* Function to add two polynomial */
struct Node *addPoly(struct Node *poly1, struct Node *poly2)
{
    if (poly1 == NULL && poly2 == NULL) // case 1 : If both list are empty
    {
        printf("There is no expression for addition ..\n");
        return NULL;
    }
    struct Node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {                                   // case 2 : list contains some terms
        if (poly1->expo == poly2->expo) // case 3 : if the expo of list one is must be equal to list two
        {
            if (poly1->coeff + poly2->coeff != 0)
            { // case 4 : if the sum of list one and list two is not equal to zero
                result = insert(result, poly1->coeff + poly2->coeff, poly1->expo);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->expo > poly2->expo) // case 5 : if expo of list one is greater than list two then insert that term into result
        {
            result = insert(result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        }
        else // case 6 : if expo of list two is greater than list one then insert that term into result
        {
            result = insert(result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL)
    { // case 7 : if only the list is remaining term then add into result
        result = insert(result, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    { // case 8 : if only the list is remaining term then add into result
        result = insert(result, poly2->coeff, poly2->expo);
        poly2 = poly2->next;
    }
    return result;
}

/* Function to subtract two polynomial */
struct Node *subPoly(struct Node *poly1, struct Node *poly2)
{
    if (poly1 == NULL && poly2 == NULL) // case 1 : If both list are empty
    {
        printf("There is no expression for addition ..\n");
        return NULL;
    }
    struct Node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {                                   // case 2 : list contains some terms
        if (poly1->expo == poly2->expo) // case 3 : if the expo of list one is must be equal to list two
        {
            if (poly1->coeff - poly2->coeff != 0)
            { // case 4 : if the sum of list one and list two is not equal to zero
                result = insert(result, poly1->coeff - poly2->coeff, poly1->expo);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->expo > poly2->expo) // case 5 : if expo of list one is greater than list two then insert that term into result
        {
            result = insert(result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        }
        else // case 6 : if expo of list two is greater than list one then insert that term into result
        {
            result = insert(result, -(poly2->coeff), poly2->expo);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL)
    { // case 7 : if only the list is remaining term then add into result
        result = insert(result, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    { // case 8 : if only the list is remaining term then add into result
        result = insert(result, -(poly2->coeff), poly2->expo);
        poly2 = poly2->next;
    }
    return result;
}

/* Function to multiply two polynomial */
struct Node *mulPoly(struct Node *poly1, struct Node *poly2)
{
    if (poly1 == NULL || poly2 == NULL)
    {
        printf("There is no expression for multiplication..\n");
        return NULL;
    }
    struct Node *result = NULL;
    struct Node *temp_result = NULL;

    for (struct Node *temp1 = poly1; temp1 != NULL; temp1 = temp1->next)
    {
        for (struct Node *temp2 = poly2; temp2 != NULL; temp2 = temp2->next)
        {
            int c = temp1->coeff * temp2->coeff;
            int e = temp1->expo + temp2->expo;
            temp_result = insert(temp_result, c, e);
        }
        struct Node *newResult = addPoly(result, temp_result);
        freeList(result);
        freeList(temp_result);

        result = newResult;
        temp_result = NULL;
    }
    return result;
}

/* Function print the polynomial */
void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty ...! \n");
        return;
    }
    while (head != NULL)
    {
        if (head->next == NULL)
        {
            printf("(%dx^%d)", head->coeff, head->expo);
        }
        else
        {
            printf("(%dx^%d) + ", head->coeff, head->expo);
        }
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    int t1, t2;
    int c, e, i = 0;
    printf("****____*****____*****____*****____****\n");
    printf("Enter the number term in polynomial 1 : ");
    scanf("%d", &t1);
    while (i < t1)
    {
        printf("Enter your coeff of term %d : ", i + 1);
        scanf("%d", &c);
        printf("Enter your expo of term %d : ", i + 1);
        scanf("%d", &e);
        poly1 = insert(poly1, c, e);
        i++;
    }
    printf("Enter the number term in polynomial 2 : ");
    scanf("%d", &t2);
    i = 0;
    while (i < t2)
    {
        printf("Enter your coeff of term %d : ", i + 1);
        scanf("%d", &c);
        printf("Enter your expo of term %d : ", i + 1);
        scanf("%d", &e);
        poly2 = insert(poly2, c, e);
        i++;
    }

    printf("****____*****____*****____*****____****\n");
    printf("Polynomial 1 : ");
    printList(poly1);
    printf("Polynomial 2 : ");
    printList(poly2);
    printf("****____*****____*****____*****____****\n");
    struct Node *addResult = addPoly(poly1, poly2);
    struct Node *subResult = subPoly(poly1, poly2);
    struct Node *mulResult = mulPoly(poly1, poly2);

    printf("Addition of list one and two is : ");
    printList(addResult);

    printf("Subtraction of list one and two is : ");
    printList(subResult);

    printf("Multiplication of list one and two is : ");
    printList(mulResult);

    freeList(poly1);
    freeList(poly2);
    freeList(addResult);
    freeList(subResult);
    freeList(mulResult);
    return 0;
}
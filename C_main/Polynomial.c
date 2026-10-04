#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff; // Store the coefficient of the polynomial term
    int expo; // Store the exponent of the polynomial term
    struct Node *next; // Point to the next term
};

/* Insert expression to list */
struct Node *insert(struct Node *head, int cof, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create a new node
    newNode->coeff = cof; // Store coefficient in the new node
    newNode->expo = exp; // Store exponent in the new node
    newNode->next = NULL; // New node will be the last node
    if (head == NULL) // Check whether the list is empty
    {
        head = newNode; // Make new node the first node
    }
    else
    {
        struct Node *currNode = head; // Start from the first node
        while (currNode->next != NULL) // Move until the last node
        {
            currNode = currNode->next; // Move to the next node
        }
        currNode->next = newNode; // Attach new node at the end
    }
    return head; // Return the updated head
}

void freeList(struct Node *head)
{
    struct Node *temp; // Temporary pointer used to free nodes
    while (head != NULL) // Continue until all nodes are deleted
    {
        temp = head; // Store the current node
        head = head->next; // Move head to the next node
        free(temp); // Free the current node from memory
    }
}

/* Function to add two polynomial */
struct Node *addPoly(struct Node *poly1, struct Node *poly2)
{
    if (poly1 == NULL && poly2 == NULL) // Case 1: Both lists are empty
    {
        printf("There is no expression for addition ..\n");
        return NULL; // Return NULL because there is nothing to add
    }
    struct Node *result = NULL; // Store the addition result
    while (poly1 != NULL && poly2 != NULL) // Process both lists together
    {
        if (poly1->expo == poly2->expo) // Case 3: Both terms have the same exponent
        {
            if (poly1->coeff + poly2->coeff != 0) // Check whether coefficient sum is not zero
            {
                result = insert(result, poly1->coeff + poly2->coeff, poly1->expo); // Add coefficients and insert term
            }

            poly1 = poly1->next; // Move to the next term of polynomial 1
            poly2 = poly2->next; // Move to the next term of polynomial 2
        }
        else if (poly1->expo > poly2->expo) // Case 5: Polynomial 1 has greater exponent
        {
            result = insert(result, poly1->coeff, poly1->expo); // Copy polynomial 1 term to result
            poly1 = poly1->next; // Move to the next term of polynomial 1
        }
        else // Case 6: Polynomial 2 has greater exponent
        {
            result = insert(result, poly2->coeff, poly2->expo); // Copy polynomial 2 term to result
            poly2 = poly2->next; // Move to the next term of polynomial 2
        }
    }
    while (poly1 != NULL) // Case 7: Terms are still remaining in polynomial 1
    {
        result = insert(result, poly1->coeff, poly1->expo); // Add remaining term to result
        poly1 = poly1->next; // Move to the next term
    }
    while (poly2 != NULL) // Case 8: Terms are still remaining in polynomial 2
    {
        result = insert(result, poly2->coeff, poly2->expo); // Add remaining term to result
        poly2 = poly2->next; // Move to the next term
    }
    return result; // Return the addition result
}

/* Function to subtract two polynomial */
struct Node *subPoly(struct Node *poly1, struct Node *poly2)
{
    if (poly1 == NULL && poly2 == NULL) // Case 1: Both lists are empty
    {
        printf("There is no expression for addition ..\n");
        return NULL; // Return NULL because there is nothing to subtract
    }
    struct Node *result = NULL; // Store the subtraction result
    while (poly1 != NULL && poly2 != NULL) // Process both lists together
    {
        if (poly1->expo == poly2->expo) // Case 3: Both terms have the same exponent
        {
            if (poly1->coeff - poly2->coeff != 0) // Check whether coefficient difference is not zero
            {
                result = insert(result, poly1->coeff - poly2->coeff, poly1->expo); // Subtract coefficients and insert term
            }
            poly1 = poly1->next; // Move to the next term of polynomial 1
            poly2 = poly2->next; // Move to the next term of polynomial 2
        }
        else if (poly1->expo > poly2->expo) // Case 5: Polynomial 1 has greater exponent
        {
            result = insert(result, poly1->coeff, poly1->expo); // Copy polynomial 1 term to result
            poly1 = poly1->next; // Move to the next term of polynomial 1
        }
        else // Case 6: Polynomial 2 has greater exponent
        {
            result = insert(result, -(poly2->coeff), poly2->expo); // Add negative coefficient of polynomial 2
            poly2 = poly2->next; // Move to the next term of polynomial 2
        }
    }
    while (poly1 != NULL) // Case 7: Terms are still remaining in polynomial 1
    {
        result = insert(result, poly1->coeff, poly1->expo); // Add remaining term to result
        poly1 = poly1->next; // Move to the next term
    }
    while (poly2 != NULL) // Case 8: Terms are still remaining in polynomial 2
    {
        result = insert(result, -(poly2->coeff), poly2->expo); // Add negative of remaining term to result
        poly2 = poly2->next; // Move to the next term
    }
    return result; // Return the subtraction result
}

/* Function to multiply two polynomial */
struct Node *mulPoly(struct Node *poly1, struct Node *poly2)
{
    if (poly1 == NULL || poly2 == NULL) // Check whether either polynomial is empty
    {
        printf("There is no expression for multiplication..\n");
        return NULL; // Return NULL because multiplication is not possible
    }
    struct Node *result = NULL; // Store the final multiplication result
    struct Node *temp_result = NULL; // Store multiplication terms for one term of polynomial 1
    for (struct Node *temp1 = poly1; temp1 != NULL; temp1 = temp1->next) // Traverse polynomial 1
    {
        for (struct Node *temp2 = poly2; temp2 != NULL; temp2 = temp2->next) // Traverse polynomial 2
        {
            int c = temp1->coeff * temp2->coeff; // Multiply the coefficients
            int e = temp1->expo + temp2->expo; // Add the exponents
            temp_result = insert(temp_result, c, e); // Insert the multiplied term
        }
        struct Node *newResult = addPoly(result, temp_result); // Add temporary terms to the previous result
        freeList(result); // Free the old result list
        freeList(temp_result); // Free the temporary multiplication list
        result = newResult; // Make new result the current result
        temp_result = NULL; // Reset temporary result for the next iteration
    }
    return result; // Return the final multiplication result
}

/* Function print the polynomial */
void printList(struct Node *head)
{
    if (head == NULL) // Check whether the list is empty
    {
        printf("List is empty ...! \n");
        return; // Stop if the list is empty
    }
    while (head != NULL) // Traverse the complete polynomial list
    {
        if (head->next == NULL) // Check whether this is the last term
        {
            printf("(%dx^%d)", head->coeff, head->expo); // Print the last term without '+'
        }
        else
        {
            printf("(%dx^%d) + ", head->coeff, head->expo); // Print term followed by '+'
        }
        head = head->next; // Move to the next polynomial term
    }
    printf("\n"); // Move to the next line
}

int main()
{
    struct Node *poly1 = NULL; // Head pointer for polynomial 1
    struct Node *poly2 = NULL; // Head pointer for polynomial 2
    int t1, t2; // Store number of terms in both polynomials
    int c, e, i = 0; // Store coefficient, exponent, and loop counter
    printf("****____****____****____****____****\n");
    printf("Enter the number term in polynomial 1 : ");
    scanf("%d", &t1); // Read number of terms in polynomial 1
    while (i < t1) // Take input for all terms of polynomial 1
    {
        printf("Enter your coeff of term %d : ", i + 1);
        scanf("%d", &c); // Read coefficient
        printf("Enter your expo of term %d : ", i + 1);
        scanf("%d", &e); // Read exponent
        poly1 = insert(poly1, c, e); // Insert the term into polynomial 1
        i++; // Move to the next term
    }
    printf("Enter the number term in polynomial 2 : ");
    scanf("%d", &t2); // Read number of terms in polynomial 2
    i = 0; // Reset loop counter for polynomial 2
    while (i < t2) // Take input for all terms of polynomial 2
    {
        printf("Enter your coeff of term %d : ", i + 1);
        scanf("%d", &c); // Read coefficient
        printf("Enter your expo of term %d : ", i + 1);
        scanf("%d", &e); // Read exponent
        poly2 = insert(poly2, c, e); // Insert the term into polynomial 2
        i++; // Move to the next term
    }
    printf("****____****____****____****____****\n");
    printf("Polynomial 1 : ");
    printList(poly1); // Display polynomial 1
    printf("Polynomial 2 : ");
    printList(poly2); // Display polynomial 2
    printf("****____****____****____****____****\n");
    struct Node *addResult = addPoly(poly1, poly2); // Add the two polynomials
    struct Node *subResult = subPoly(poly1, poly2); // Subtract polynomial 2 from polynomial 1
    struct Node *mulResult = mulPoly(poly1, poly2); // Multiply the two polynomials
    printf("Addition of list one and two is : ");
    printList(addResult); // Display addition result
    printf("Subtraction of list one and two is : ");
    printList(subResult); // Display subtraction result
    printf("Multiplication of list one and two is : ");
    printList(mulResult); // Display multiplication result
    freeList(poly1); // Free memory used by polynomial 1
    freeList(poly2); // Free memory used by polynomial 2
    freeList(addResult); // Free memory used by addition result
    freeList(subResult); // Free memory used by subtraction result
    freeList(mulResult); // Free memory used by multiplication result

    return 0; // End the program
}
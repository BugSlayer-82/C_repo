#include <stdio.h>
void squarePattern();   // In this function there is only square based pattern
void anglePattern();    // In this function there is only angle type triangle based pattern
void trianglePattern(); // In this function there is only triangle based pattern

int main()
{
    // /* This section is for only calling the pattern function */
    // squarePattern();
    // anglePattern();
    // trianglePattern();

    return 0;
}

void squarePattern() // Function definition for print square pattern only
{
    // /* 1 ====> To print normal square || rectangle*/
    // int l, b, i, j; // Declare variable to store the inpur
    // printf("Enter the value of l & b ?\n");
    // scanf("%d %d", &l, &b);  // Take input from user
    // for (i = 0; i <= l; i++) // Iterate through each row
    // {
    //     for (j = 0; j <= b; j++) // Iterate through each column
    //     {
    //         printf("* "); // print star on the current line
    //     }
    //     printf("\n"); // Move to the next line
    // }

    // /* 2 ====> To print Hollow square || rectangle*/
    // int l, b, i, j; // Declare variable to store the inpur
    // printf("Enter the value of l & b ?\n");
    // scanf("%d %d", &l, &b);  // Take input from user
    // for (i = 0; i <= l; i++) // Iterate through each row
    // {
    //     for (j = 0; j <= b; j++) // Iterate through each column
    //     {
    //         if (i == 0 || j == 0 || i == l || j == b)
    //         { // If the condition satisfies then print the stars
    //             printf("* ");
    //         }
    //         else
    //         { // If the condition not satisfies then print the spaces
    //             printf("  ");
    //         }
    //     }
    //     printf("\n");  // Move to the new line
    // }

    // /* 3 ====> To print the rhombus*/
    // int i, j, k, n; // Declare the vaiables i,j,k,n
    // printf("Enter the value of x ?\n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = 1; i <= n; i++)
    // {    // Iterate through each rows
    //     for (j = 1; j <= n - i; j++)
    //     {    // Iterate through each columns
    //         printf("  "); // Print the spaces
    //     }
    //     for (k = 1; k <= n; k++)
    //     { // Iterate through each columns
    //         printf("* "); // Print the stars
    //     }
    //     printf("\n"); // Move to the new line
    // }

    // /* 4 ====> To print the hollow rhombus*/
    // int i, j, k, n;  // Declare the vaiables i,j,k,n
    // printf("Enter the value of x ?\n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = 1; i <= n; i++)
    // {    // Iterate through each rows
    //     for (j = 1; j <= n - i; j++)
    //     {    // Iterate through each columns
    //         printf("  ");
    //     }
    //     for (k = 1; k <= n; k++)
    //     {    // Iterate through each columns
    //         if (i == 1 || k == 1 || i == n || k == n)
    //         { // If the condition satisfies then print stars
    //             printf("* ");
    //         }
    //         else
    //         {    // If the condition not satisfies then print spaces
    //             printf("  ");
    //         }
    //     }
    //     printf("\n"); // Move to the next line
    // }
}

void anglePattern() // Function definition for print angle pattern only
{
    // /* 1 ====> To print the right angle triangle */
    // int i, j, n; // Declare the variables like i,j,n
    // printf("Enter the value of n ?\n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = 1; i <= n; i++)
    // {    // Iterate through each rows
    //     for (j = 1; j <= i; j++)
    //     {    // Iterate through each columns
    //         printf("* ");    // Print stars
    //     }
    //     printf("\n");     // Move to the new line
    // }

    // /* 2 ====> To print the Left angle triangle */
    // int i, j, k, n; // Declare the variables like i,j,k,n
    // printf("Enter the value of n ? \n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = 1; i <= n; i++)
    // {   // Iterate through each rows
    //     for (j = 1; j <= n - i; j++)
    //     {   // Iterate through each columns
    //         printf("  ");   // Print the spaces
    //     }
    //     for (k = 1; k <= i; k++)
    //     {   // Iterate through each columns
    //         printf("* ");   // Print the stars
    //     }
    //     printf("\n");    // Move to the new line
    // }

    // /* 3 ====> To print the right angle hollow triangle */
    // int i, j, n; // Declare the variables like i,j,n
    // printf("Enter the value of n ?\n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = 1; i <= n; i++)
    // { // Iterate through each rows
    //     for (j = 1; j <= i; j++)
    //     { // Iterate through each columns
    //         if (i == 1 || j == 1 || i == n || j == i)
    //         {                 // If the conditin satisfies then print the pattern
    //             printf("* "); // Print stars
    //         }
    //         else
    //         { // If the conditin not satisfies then print the spaces
    //             printf("  ");
    //         }
    //     }
    //     printf("\n"); // Move to the new line
    // }

    // /* 4 ====> To print the Left angle hollow triangle */
    // int i, j, k, n; // Declare the variables like i,j,k,n
    // printf("Enter the value of n ? \n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = 1; i <= n; i++)
    // { // Iterate through each rows
    //     for (j = 1; j <= n - i; j++)
    //     {                 // Iterate through each columns
    //         printf("  "); // Print the spaces
    //     }
    //     for (k = 1; k <= i; k++)
    //     { // Iterate through each columns
    //         if (i == 1 || k == 1 || i == n || k == i)
    //         { // If the condition satisfies then print the star
    //             printf("* "); // Print the stars
    //         }
    //         else
    //         {   // If the condition not statisfies then print the spaces
    //             printf("  "); // Print the space
    //         }
    //     }
    //     printf("\n"); // Move to the new line
    // }

    // /* 5 ====> To print the right angle number triangle */
    // int i, j, n; // Declare the variables like i,j,n
    // printf("Enter the value of n ?\n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = 1; i <= n; i++)
    // { // Iterate through each rows
    //     for (j = 1; j <= i; j++)
    //     {                     // Iterate through each columns
    //         printf("%d ", j); // Print the number
    //     }
    //     printf("\n"); // Move to the new line
    // }

    // /* 6 ====> To print the right angle number triangle */
    // int i, j, n; // Declare the variables like i,j,n
    // printf("Enter the value of n ?\n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = 1; i <= n; i++)
    // { // Iterate through each rows
    //     for (j = 1; j <= i; j++)
    //     {                     // Iterate through each columns
    //         printf("%d ", i); // Print the number
    //     }
    //     printf("\n"); // Move to the new line
    // }

    // /* 7 ====> To print the right angle reverse triangle */
    // int i, j, n; // Declare the variables like i,j,n
    // printf("Enter the value of n ?\n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = n; i >= 1; i--)
    // { // Iterate through each rows
    //     for (j = 1; j <= i; j++)
    //     {                 // Iterate through each columns
    //         printf("* "); // Print stars
    //     }
    //     printf("\n"); // Move to the new line
    // }

    // /* 8 ====> To print the Left angle reverse triangle */
    // int i, j, k, n; // Declare the variables like i,j,k,n
    // printf("Enter the value of n ? \n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = n; i >= 1; i--)
    // { // Iterate through each rows
    //     for (j = 1; j <= n - i; j++)
    //     {                 // Iterate through each columns
    //         printf("  "); // Print the spaces
    //     }
    //     for (k = 1; k <= i; k++)
    //     {                 // Iterate through each columns
    //         printf("* "); // Print the stars
    //     }
    //     printf("\n"); // Move to the new line
    // }

    // /* 9 ====> To print the right angle reverse hollow triangle */
    // int i, j, n; // Declare the variables like i,j,n
    // printf("Enter the value of n ?\n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = n; i >= 1; i--)
    // { // Iterate through each rows
    //     for (j = 1; j <= i; j++)
    //     { // Iterate through each columns
    //         if (i == 1 || j == 1 || i == n || j == i)
    //         {                 // If the conditin satisfies then print the pattern
    //             printf("* "); // Print stars
    //         }
    //         else
    //         { // If the conditin not satisfies then print the spaces
    //             printf("  ");
    //         }
    //     }
    //     printf("\n"); // Move to the new line
    // }

    // /* 10 ====> To print the Left angle hollow triangle */
    // int i, j, k, n; // Declare the variables like i,j,k,n
    // printf("Enter the value of n ? \n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = n; i >= 1; i--)
    // { // Iterate through each rows
    //     for (j = 1; j <= n - i; j++)
    //     {                 // Iterate through each columns
    //         printf("  "); // Print the spaces
    //     }
    //     for (k = 1; k <= i; k++)
    //     { // Iterate through each columns
    //         if (i == 1 || k == 1 || i == n || k == i)
    //         {                 // If the condition satisfies then print the star
    //             printf("* "); // Print the stars
    //         }
    //         else
    //         {                 // If the condition not statisfies then print the spaces
    //             printf("  "); // Print the space
    //         }
    //     }
    //     printf("\n"); // Move to the new line
    // }

    // /* 11 ====> To print the right angle triangle with character */
    // char ch; // Declare a char variable
    // int i, j; // Declare variable like i,j
    // printf("Enter the last character you want ?\n");
    // scanf(" %c", &ch); // Take input character
    // for (i = 'a'; i <= ch; i++)
    // {    // Iterate through each rows
    //     for (j = 'a'; j <= i; j++)
    //     {    // Iterate through each columns
    //         printf("%c ", i);    // Print the character
    //     }
    //     printf("\n");   // Move to the new line
    // }
}

void trianglePattern() // Fuction definition for print triangle pattern only
{
    // /* 1 ====> To print the normal triangle */
    // int i, j, k, n; // Declare the variables like i,j,n
    // printf("Enter the value of n ?\n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = 1; i <= n; i++)
    // { // Iterate through each rows
    //     int space = 2 * i - 1;
    //     for (k = 1; k <= n - i; k++)
    //     {                 // Iterate through each columns
    //         printf("  "); // Print spaces
    //     }
    //     for (j = 1; j <= space; j++)
    //     {                 // Iterate through each columns
    //         printf("* "); // Print stars
    //     }
    //     printf("\n"); // Move to the new line
    // }

    // /* 2 ====> To print the hollow triangle */
    // int i, j, k, n; // Declare the variables like i,j,n
    // printf("Enter the value of n ?\n");
    // scanf("%d", &n); // Take input the value of n
    // for (i = 1; i <= n; i++)
    // { // Iterate through each rows
    //     int space = 2 * i - 1;
    //     for (k = 1; k <= n - i; k++)
    //     {                 // Iterate through each columns
    //         printf("  "); // Print spaces
    //     }
    //     for (j = 1; j <= space; j++)
    //     { // Iterate through each columns
    //         if (j == 1 || j == space || i == n)
    //         { // If the condition satisfies then print the star
    //             printf("* "); // Print stars
    //         }
    //         else
    //         { // If the condition not satisfies then print the spaces
    //             printf("  "); // Print space
    //         }
    //     }
    //     printf("\n"); // Move to the new line
    // }
}

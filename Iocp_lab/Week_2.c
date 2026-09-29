#include <stdio.h>

// void pascalTriangle(int n); // Pascal's Triangle with number
// void floydsTriangle(int n);      // Floyd's triangle with number
// void diamondPattern(int n);      // Diamond pattern with star
// void characterTriangle(char ch); // Triangle with character
// void numberTriangle(int n);      // Triangle with number
// void triangle(int n); // Triangle with star
// void rightAngle_3(char ch); // Right angle triangle with character
// void rightAngle_2(int n); // Right angle triangle with number
// void rightAngle_1(int n); // Right angle triangle with star

int main()
{
    // int n;
    // char ch;
    // printf("Enter the value of n : ");
    // scanf("%d", &n);
    // printf("Enter the character in Capital : ");
    // scanf("%c", &ch);
    // rightAngle_1(n);
    // rightAngle_2(n);
    // rightAngle_3(ch);
    // triangle(n);
    // numberTriangle(n);
    // characterTriangle(ch);
    // diamondPattern(n);
    // floydsTriangle(n);
    // pascalTriangle(n);

    return 0;
}

// Question 1 --> Right angle triangle with star
// void rightAngle_1(int n){
//     for(int i = 1; i <= n ; i++){
//         for(int j = 1; j <= i; j++){
//             printf("* ");
//         }
//         printf("\n");
//     }
// }

// Question 2 --> Right angle triangle with number
// void rightAngle_2(int n){
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= i; j++){
//             printf("%d ",j);
//         }
//         printf("\n");
//     }
// }

// Question 3 --> Right angle triangle with character
// void rightAngle_3(char ch){
//     for(int i = 'A'; i <= ch; i++){
//         for(int j = 'A'; j <= i; j++){
//             printf("%c ",j);
//         }
//         printf("\n");
//     }
// }

// Question 4 --> Traingle with star
// void triangle(int n){
//     for(int i = 1; i <= n; i++){
//         for(int j  = 1; j <= n - i; j++){
//             printf("  ");
//         }
//         for(int j = 1; j <= 2*i -1 ; j++){
//             printf("* ");
//         }
//         printf("\n");
//     }
// }

// Question 5 --> Triangle with number
// void numberTriangle(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= n - i; j ++){
//             printf("  ");
//         }
//         for (int j = 1; j <= i; j++)
//         {
//             printf("%d ", j);
//         }
//         for(int j = i-1; j >= 1; j--){
//             printf("%d ",j);
//         }
//         printf("\n");
//     }
// }

// Question 6 --> Triangle with character
// void characterTriangle(char ch)
// {
//     for (int i = 'A'; i <= ch; i++)
//     {
//         // This inner loop print the spaces
//         for (int j = 1; j <= ch - i; j++)
//         {
//             printf("  ");
//         }
//         // This inner loop print the element first pyramid in increasing order
//         for (int j = 'A'; j <= i; j++)
//         {
//             printf("%c ", j);
//         }
//         // This inner loop print the element second pyramid in decreasing order
//         for (int j = i - 1; j >= 'A'; j--)
//         {
//             printf("%c ", j);
//         }
//         printf("\n");
//     }
// }

// Question 7 --> Diamond pattern with star
// void diamondPattern(int n){
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= n - i; j++){
//             printf("  ");
//         }
//         for(int j = 1; j<= 2*i-1; j++){
//             printf("* ");
//         }
//         printf("\n");
//     }
//      for(int i = n-1; i >= 1; i--){
//         for(int j = 1; j <= n - i; j++){
//             printf("  ");
//         }
//         for(int j = 1; j<= 2*i-1; j++){
//             printf("* ");
//         }
//         printf("\n");
//     }
// }

// Question 8 --> Floyd's triangle with number
// void floydsTriangle(int n){
//     int sum = 0;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= i; j++){
//             sum ++;
//             printf("%d ", sum);
//         }
//         printf("\n");
//     }
// }

// Question 9 --> Pascal's triangle with number
// void pascalTriangle(int n){
//     for(int i = 1; i <= n; i ++){
//         for(int j = 1; j <= n - i; j++){
//             printf(" ");
//         }
//         int value = 1;
//         for(int j = 1; j <= i; j++){
//             printf("%d ",value);
//             value = value * (i - j) / j;
//         }
//         printf("\n");
//     }
// }
#include <stdio.h>
#include <math.h>

// /* Question 9 --> Fizz and Buzz problem */


// /* Question  8 --> Find the nth Fibonacci Number */
// int fibonacci(int num)
// {
//     if (num <= 1)
//     {
//         return num;
//     }
//     int a = 0, b = 1, c;
//     for (int i = 2; i <= num; i++)
//     {
//         c = a + b;
//         a = b;
//         b = c;
//     }
//     return b;
// }

// /* Question 7 --> Find the gcd of two number */
// int gcd(int a, int b)
// {
//     if (b == 0)
//     {
//         return a;
//     }
//     return gcd(b, a % b);
// }

// /* Question 6 --> Find the last non-zero digit in Factorial */
// int nonZeroInFactorial(int n)
// {
//     long long result = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         result *= i;
//         while (result % 10 == 0)
//         {
//             result /= 10;
//         }
//         result %= 100000;
//     }
//     return result % 10;
// }

// /* Question 5 --> Find the last non zero digit */
// int nonZero(int num){
//     while(num % 10 == 0){
//         num /= 10;
//     }
//     return num % 10;
// }

// /* Question 4 --> Count the trailing zero's in factorial of number */
// int trailingInFactorial(int num){
//     int count = 0;
//     for(int i = 5; num /i >= 1; i*= 5){
//         count += num/i;
//     }
//     return count;
// }

// /* Question 3 --> Count the trailing zero's in an number */
// int countTrailingZero(int num)
// {
//     int count = 0;
//     while (num % 10 == 0 && num != 0)
//     {
//         count++;
//         num /= 10;
//     }
//     return count;
// }

// /* Question 2 --> Count the total digit in factorial of a number problem */
// int countDigitInFact(int n)
// {
//     if (n == 0 || n == 1)
//     {
//         return 1;
//     }
//     double sum = 0;
//     for (int i = 2; i <= n; i++)
//     {
//         sum += log10(i);
//     }
//     return (int)sum + 1;
// }

// /* Question 1 --> Count the total digit of number (Optimised approach) */
// int countOfDigit(int num){
//     if(num == 0){ // If number is 0 so return 1
//         return 1;
//     }
//     return (int)log10(num) + 1;// Count the number of digit
// }
// /* ====> Brute Force Approach <====== */
// int countOfDigit(int num){
//     if(num == 0){
//         return 1;
//     }
//     int count = 0;
//     while(num != 0){
//         num /= 10;
//         count ++;
//     }
//     return count;
// }

int main()
{
    // // /* Question --> 1 */
    // int num;  // To declare a varible that store number
    // printf("Enter your number : ");
    // scanf("%d",&num); // Take input from user
    // printf("Count : %d \n",countOfDigit(num)); // Print and call the count Digit function
    // printf("Count : %d \n",countOfDigit(num));

    // // /* Question --> 2 */
    // int num; // To declare a variable that store number
    // printf("Enter your number : ");
    // scanf("%d", &num); // Take input from user
    // printf("Count of factorial digit : %d \n", countDigitInFact(num));

    // // /* Question --> 3 */
    // int num; // To declare a variable that store number
    // printf("Enter your number : ");
    // // scanf("%d", &num); // Take input from user
    // printf("Trailing Zero : %d \n", countTrailingZero(num));

    // // /* Question --> 4 */
    // int num;
    // printf("Enter your number : ");
    // scanf("%d",&num);
    // printf("Trailing Zero : %d \n",trailingInFactorial(num));

    // // /* Question --> 5 */
    // int num;
    // printf("Enter your number : ");
    // scanf("%d", &num);
    // printf("Last Non-Zero : %d \n", nonZero(num));

    // // /* Question --> 6 */
    // int num;
    // printf("Enter your number : ");
    // scanf("%d", &num);
    // printf("Non-Zero in factorial : %d \n", nonZeroInFactorial(num));

    // // /* Question --> 7 */
    // int x, y;
    // printf("Enter your number X : ");
    // scanf("%d", &x);
    // printf("Enter your number Y : ");
    // scanf("%d", &y);
    // printf("GCD of X : %d ,Y : %d Is : %d \n",x,y, gcd(x, y));

    // // /* Question --> 8 */
    // int num;
    // printf("Enter your number of term : ");
    // scanf("%d", &num);
    // printf("%dth term Fibonacci number is :  %d \n", num, fibonacci(num));

    // // /* Question --> 9 */
    
    return 0;
}
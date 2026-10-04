#include <stdio.h>
int factorial(int);         // function prototype for recursive for find factorial
int fibonacci(int);         // function prototype for recursive for find fibonacci
void swapVal(int, int);     // function prototype for swapping two value by call by value
void swapRef(int *, int *); // function prototype for swapping two value by call by reference
void isPrime(int);          // function prototype for checking number is prime or not
void isPalindrome(int);     // function prototype for checking number is palindrome or not
int main()
{
    // /* 1 ===> Factorial recursive function */
    // int x;
    // printf("Enter the number ?\n");
    // scanf("%d", &x);
    // long int result = factorial(x);
    // printf("%ld \n", result);

    // /* 2 ===> Fibonacci recursive funtion*/
    // int i, x;
    // printf("Enter the limit ?\n");
    // scanf("%d", &x);
    // for (i = 0; i < x; i++)
    // {
    //     int result = fibonacci(i);
    //     printf("%d ", result);
    // }
    // printf("\n");

    // /* 3 ===> Swapping using call by value method*/
    // int a, b; // Declare variable to store the value of a,b
    // printf("Enter two values ? \n");
    // scanf("%d %d", &a, &b); // Take input the value of a,b
    // printf("Before swapping ==> a : %d and b : %d \n", a, b);
    // swapVal(a, b); // Calling the swap by value function by passing the value of value
    // printf("After swapping ==> a : %d and b : %d\n", a, b);

    // /* 4 ===> Swapping using call by reference method*/
    // int a, b; // Declare variable to store the value of a,b
    // printf("Enter two values ? \n");
    // scanf("%d %d", &a, &b); // Take input the value of a,b
    // printf("Before swapping ==> a : %d and b : %d \n", a, b);
    // swapRef(&a, &b); // Calling the swap by reference function by passing the address of value
    // printf("After swapping ==> a : %d and b : %d\n", a, b);

    // /* 5 ===> Prime function to check is number prime or not*/
    // int n;// Declare a variable that store the value
    // printf("Enter number to check prime or not ? \n");
    // scanf("%d", &n); // Take input the value of n
    // isPrime(n); // Calling the prime checking function

    // /* 6 ===> Palindrome function to check is number palindrome or not*/
    // int n; // Declare a variable that store the value
    // printf("Enter number to check palindrome or not ? \n");
    // scanf("%d", &n); // Take input the value of n
    // isPalindrome(n); // Calling the palindrome checking funtion

    return 0;
}
int factorial(int n) // Function definition for calculate the factorial
{
    // if (n <= 1) // Base of recursive function
    // {
    //     return 1;
    // }
    // return n * factorial(n - 1); // Recursive call
}

int fibonacci(int n) // Function definition for calculate the fibonacci series
{
    // if (n <= 0)// Base case 1 of recursive function
    // {
    //     return 0;
    // }
    // if (n == 1) // Base case 2 of recursive funtion
    // {
    //     return 1;
    // }
    // return fibonacci(n - 1) + fibonacci(n - 2); //  Recursive call
}

void swapVal(int x, int y) // Function definition for print the swapped value
{
    // int t = x; // Initalized a temporary variable that store the value of x
    // x = y; // To assign the value of y to x
    // y = t; // To assign the value of temp to y
    // printf("By using call by value method \n");
}

void swapRef(int *x, int *y) // Function definition for print the swapped value
{
    // int t = *x; // Initalized a temporary variable that store the value of x
    // *x = *y;    // To assign the value of y to x
    // *y = t;     // To assign the value of temp to y
    // printf("By using call by reference method \n");
}

void isPrime(int n) // Function definition for checking is number prime or not
{
    // int i, flag = 1; // 'i' is the divisor, 'flag' tracks if the number is prime (1 = true)
    // // Check if the number is 1 or less, as these are not prime numbers
    // if (n <= 1)
    // {
    //     printf("%d ==> is neither prime nor composite\n", n);
    //     return; // Exit the function early
    // }
    // // Loop from 2 up to half of n to look for potential factors
    // for (i = 2; i <= n / 2; i++)
    // {
    //     // If n is divisible by any value of i, it is not a prime number
    //     if (n % i == 0)
    //     {
    //         flag = 0; // Set flag to 0 indicating it is not prime
    //         break;    // Stop the loop immediately once a factor is found
    //     }
    // }
    // // After the loop, check the flag value to determine the final result
    // if (flag == 1)
    // {
    //     printf("%d ==> is a prime number \n", n);
    // }
    // else
    // {
    //     printf("%d ==> is not a prime number \n", n);
    // }
}

void isPalindrome(int n) // Function definition for checking is number palindrome or not
{
    // int reverse = 0; // To store the reversed version of the number
    // int temp = n;    // Create a temporary copy to preserve the original value of n
    // // Loop until all digits are extracted from the temporary variable
    // while (temp != 0)
    // {
    //     // Get the last digit of the current number using the modulo operator
    //     int currDig = temp % 10;
    //     // Build the reversed number by shifting existing digits left and adding the new one
    //     reverse = reverse * 10 + currDig;
    //     // Remove the last digit from temp by performing integer division by 10
    //     temp = temp / 10;
    // }
    // // Compare the fully reversed number with the original input n
    // if (reverse == n)
    // {
    //     printf("%d ==> is a palindrome number \n", n);
    //     return; // Exit function
    // }
    // else
    // {
    //     printf("%d ==> is not a palindrome number \n", n);
    //     return; // Exit function
    // }
}

#include <stdio.h>
#include <limits.h>

// /* Question 15 --> To Calculate the sum of array element */
// int sumOfArray(int n, int arr[n], int sum)
// {
//     if (n <= 0)
//     {
//         return sum;
//     }
//     return sumOfArray(n - 1, arr, sum + arr[n - 1]);
// }

// /* Question 14 --> To transpose a matrix */
// void transposeMatrix(int m,int n){
//     int matA[m][n];
//     printf("Matrix Input of %d X %d \n",m,n);
//     for(int i = 0; i < m; i ++){
//         for(int j = 0; j < n; j++){
//             printf("Enter matrix element : ");
//             scanf("%d",&matA[i][j]);
//         }
//     }
//     // Matrix Output
//     for(int i = 0; i < m; i ++){
//         for(int j = 0; j < n; j++){
//             printf("%d \t",matA[i][j]);
//         }
//         printf("\n");
//     }
//     // Tanspose perform
//     int matB[m][n];
//     for(int i = 0; i < m; i ++){
//         for(int j = 0; j < n; j++){
//             matB[i][j] = matA[j][i];
//         }
//     }
//     printf("Transpose of matrix is :- \n");
//     for(int i = 0; i < m; i ++){
//         for(int j = 0; j < n; j++){
//             printf("%d \t",matB[i][j]);
//         }
//         printf("\n");
//     }
// }

// /* Question  13 --> To remove duplicates from array */
// void removeDuplicates(int n, int arr[n])
// {
//     printf("Actual array \n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\nUnique elemets\n");
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 arr[j] = arr[j + 1];
//                 n--;
//                 j--;
//             }
//         }
//     }
//     for(int i = 0; i < n; i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }

// /* Question 12 --> To find the second largest element in array */
// int secondLargest(int n, int arr[n])
// {
//     int max = INT_MIN;
//     int secMax = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         if (max < arr[i])
//         {
//             secMax = max;
//             max = arr[i];
//         }
//         else if (max >= arr[i] && secMax < arr[i])
//         {
//             secMax = arr[i];
//         }
//     }
//     return secMax;
// }

// /* Question 11 --> To swap to number */
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// /* Question 10 --> To reverse an string */
// void reverse(int n ,char str[n])
// {
//     int first = 0;
//     int last = n - 1 ;
//     while (first < last)
//     {
//         char ch = str[first];
//         str[first] = str[last];
//         str[last] = ch;
//         first++;
//         last--;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         printf("%c", str[i]);
//     }
//     printf("\n");
// }

// /* Question 9 --> To count Vowels, consonants, digits  and spaces in a string */
// void countOfVowel(int n, char str[n])
// {
//     int vowels, consonant, digit, spaces;
//     vowels = 0, consonant = 0, digit = 0, spaces = 0;
//     for (int i = 0; i < n; i++)
//     {
//         char ch = str[i];
//         if ((ch >= 'A') && (ch <= 'Z') || (ch >= 'a') && (ch <= 'z'))
//         {
//             if ((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ||
//                 (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'))
//             { // Count vowels
//                 vowels++;
//             }
//             else
//             { // Count consonant
//                 consonant++;
//             }
//         }
//         else if ((ch >= '0') && (ch <= '9'))
//         { // Count digits
//             digit++;
//         }
//         else
//         {
//             if (ch == ' ')
//             { // Count spaces
//                 spaces++;
//             }
//         }
//     }
//     printf("Vowels are : %d \n", vowels);
//     printf("Consonants are : %d \n", consonant);
//     printf("Digits are : %d \n", digit);
//     printf("Spaces are : %d \n", spaces);
// }

// /* Question 8(a) --> To search for element in array using linear search */
// int linearSearch(int n, int x,int arr[n]){
//     for(int i = 0; i < n; i++){
//         if(arr[i] == x){ // Search for element x in array
//             return arr[i]; // return the element
//         }
//     }
//     return -1; // element not found
// }

// /* Question 8(b) --> To search for element in array using Binary Search */
// int binarySearch(int n, int x, int arr[n])
// {
//     int first = 0;
//     int last = n - 1;
//     while (first <= last)
//     {
//         int mid = first + (last - first) / 2;
//         if (arr[mid] == x)
//         {
//             return arr[mid];
//         }
//         else if (arr[mid] > x)
//         {
//             last = mid - 1;
//         }
//         else
//         {
//             first = mid + 1;
//         }
//     }
//     return -1;
// }

// /* Question 7 --> To an array using Bubble Sort */
// void bubbleSort(int n, int arr[])
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
//     printf("Sorted array \n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// /* Question 6 --> To print the Fibonacci Series */
// void printFibonacci(int n){
//     int first = 0;
//     int second = 1;
//     for(int i = 0 ; i < n; i++){
//         printf("%d ",first);
//         int third = first + second;
//         first = second;
//         second = third;
//     }
// }

// /* Question 5(a) --> To find the factorial of a number n (Through Iterative) */
//  long int factorial(int n){
//     long int fact = 1;
//     if(n == 0 || n == 1){
//         return fact;
//     }
//     for(int i = 1; i <= n; i ++){
//         fact = fact * i;
//     }
//     return fact;
//  }

// /* Question 5(b) --> To find the factorial of a number n (Through Recursive) */
// long int factorial(int n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }
//     return n * factorial(n - 1);
// }

// /* Question 4 --> To check a number is palindrome or not */
// int isPalindrome(int n)
// {
//     int temp = n;
//     int reverse = 0;
//     while (temp != 0)
//     {
//         int curr = temp % 10;
//         temp /= 10;
//         reverse = reverse * 10 + curr;
//     }
//     if (reverse == n)
//     {
//         return 1;
//     }
//     return 0;
// }

// /* Question 3 --> To reverse a number */
// int reverse(int num)
// {
//     if(num < 10){
//         return num;
//     }
//     int reverse = 0;
//     while(num != 0){
//         int curr = num % 10;
//         num /= 10;
//         reverse = reverse*10+curr;
//     }
//     return reverse;
// }

// /* Question 2 --> To check whether a number is prime or not */
// int isPrime(int n)
// {
//     if (n <= 1)
//     {
//         return 0;
//     }
//     else
//     {
//         for (int i = 2; i <= n / 2; i++)
//         {
//             if (n % i == 0)
//             {
//                 return 0;
//             }
//         }
//         return 1;
//     }
// }

// /* Question 1 --> Find the largest of three */
// int largestOfThree(int a, int b, int c)
// {
//     if(a > b){
//         if(a > c){
//             return a;
//         }
//     }else{
//         if(b > c){
//             return b;
//         }
//     }
//     return c;
// }

int main()
{
    // /* Question 1 --> Find the largest of three */
    // int a,b,c,largest;
    // printf("Enter your number a : ");
    // scanf(" %d", &a);
    // printf("Enter your number b: ");
    // scanf("%d", &b);
    // printf("Enter your number c :");
    // scanf("%d", &c);
    // largest = largestOfThree(a,b,c);
    // printf("Largest of three is : %d \n",largest);

    // /* Question 2 --> To check whether a number is prime or not */
    // int n, result;
    // printf("Enter your number : ");
    // scanf("%d",&n);
    // result = isPrime(n);
    // if(result == 0){
    //     printf("%d : is not a prime number .\n", n);
    // }else{
    //     printf("%d : is a prime number .\n", n);
    // }

    // /* Question 3 --> To reverse a number */
    // int n,result;
    // printf("Enter your number : ");
    // scanf("%d",&n);
    // result = reverse(n);
    // printf("Reversed number : %d\n",result);

    // /* Question 4 --> To check a number is palindrome or not */
    // int n;
    // printf("Enter your number : ");
    // scanf("%d",&n);
    // if(isPalindrome(n)){
    //     printf("%d : is Palindrome number .\n",n);
    // }else{
    //     printf("%d : is not Palindrome number . \n",n);
    // }

    // /* Question 5(a) --> To find the factorial of a number n (Through iterative) */
    // int n;
    // printf("Enter your number : ");
    // scanf("%d",&n);
    // printf("%ld : is a factorial of : %d\n",result,n);

    // /* Question 5(b) --> To find the factorial of a number n (Through Recursive) */
    // int n;
    // printf("Enter your number : ");
    // scanf("%d", &n);
    // printf("%ld : is a factorial of : %d \n", factorial(n), n);

    // /* Question 6 --> To print the Fibonacci Series */
    // int n;
    // printf("Enter your number of term : ");
    // scanf("%d",&n);
    // printFibonacci(n);
    // printf("\n");

    // /* Question 7 --> To an array using Bubble Sort */
    // int n;
    // printf("Enter size of array : ");
    // scanf("%d", &n);
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter array element : ");
    //     scanf("%d", &arr[i]);
    // }
    // bubbleSort(n, arr);

    // /* Question 8(a) --> To search for element in array using linear search */
    // int x,n,ans;
    // printf("Enter the size of array : ");
    // scanf("%d",&n);
    // int arr[n];
    // for(int i = 0; i < n; i++){
    //     printf("Enter array element : ");
    //     scanf("%d",&arr[i]);
    // }
    // printf("Enter your element do you want ? \n");
    // scanf("%d",&x);
    // ans = linearSearch(n,x,arr);
    // if(ans != -1){
    //     printf("Element is found : %d \n",ans);
    // }else{
    //     printf("Element is not found : %d \n",x);
    // }

    // /* Question 8(b) --> To search for element in array using Binary search */
    // int x, n, ans;
    // printf("Enter the size of array : ");
    // scanf("%d", &n);
    // int arr[n];
    // printf("Please enter sorted array .... \n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter array element : ");
    //     scanf("%d", &arr[i]);
    // }
    // printf("Enter your element do you want ? \n");
    // scanf("%d", &x);
    // ans = binarySearch(n, x, arr);
    // if (ans != -1)
    // {
    //     printf("Element is found : %d \n", ans);
    // }
    // else
    // {
    //     printf("Element is not found : %d \n", x);
    // }

    // /* Question 9 --> To count Vowels, consonants, digits  and spaces in a string */
    // char str[] = "This is vowel and are consonant 345034 digit";
    // int n = sizeof(str) / sizeof(str[0]);
    // countOfVowel(n, str);

    // /* Question 10 --> To reverse an string */
    // char str[] = "This is a program to reverse a string";
    // int n = sizeof(str)/sizeof(str[0]);
    // reverse(n,str);

    // /* Question 11 --> To swap two number */
    // int a, b;
    // printf("Enter your number a : ");
    // scanf("%d", &a);
    // printf("Enter your number b : ");
    // scanf("%d",&b);
    // swap(&a, &b);
    // printf("Value of a : %d, b: %d \n", a, b);

    // /* Question 12 --> To find the second largest element in array */
    // int n;
    // printf("Enter the array size : ");
    // scanf("%d", &n);
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter array element : ");
    //     scanf("%d", &arr[i]);
    // }
    // printf("Second largest == > %d \n", secondLargest(n, arr));

    // /* Question  13 --> To remove duplicates from array */
    // int n;
    // printf("Enter the size of array \n");
    // scanf("%d", &n);
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter array element : ");
    //     scanf("%d", &arr[i]);
    // }
    // removeDuplicates(n, arr);

    // /* Question 14 --> To transpose a matrix */
    // int m, n;
    // printf("Enter the size of matrix ? \n");
    // printf("Enter the value of m : ");
    // scanf("%d", &m);
    // printf("Enter the value of n : ");
    // scanf("%d", &n);
    // transposeMatrix(m, n);

    // /* Question 15 --> To Calculate the sum of array elemetn */
    // int n;
    // printf("Enter the size of Array : ");
    // scanf("%d", &n);
    // int arr[n];
    // for(int i = 0; i < n; i++){
    //     printf("Enter array element : ");
    //     scanf("%d",&arr[i]);
    // }
    // int result = sumOfArray(n, arr, 0);
    // printf("Sum is : %d \n", result);

    return 0;
}

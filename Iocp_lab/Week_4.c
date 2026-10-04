#include <stdio.h>
#include <limits.h>

// /* Question 2 ===> Find Second largest element in array */
int secondLargest(int arr[],int length)
{
    int max = INT_MIN;
    int secMax = INT_MIN;

    for (int i = 0; i < length; i++)
    {
        if (max < arr[i])
        {
            secMax = max;
            max = arr[i];
        }
        else if ((max != arr[i]) && (secMax < arr[i]))
        {
            secMax = arr[i];
        }
    }

    return secMax;
}

// /* Question 1 ===> Find largest element in array */ 
int largest(int arr[],int length){
    int max =  INT_MIN; 
    for(int i = 0; i < length; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int arr[] = {8,8,8,9,8};
    int length = sizeof(arr) / sizeof(arr[0]);
    printf("Largest : %d \n",largest(arr,length));
    printf("Second largest : %d\n",secondLargest(arr,length));

    return 0;
}
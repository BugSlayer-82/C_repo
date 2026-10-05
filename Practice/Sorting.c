/* Sorting Algorithm's */
#include <stdio.h>

/* 1 ===> Bubble Sort */
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int main()
{
    int arr[] = {5, 12, 14, 6, 7, 8, 9, 10, 2, 3, 4, 11, 18, 19, 20};
    int n = sizeof(arr) / sizeof(int);
    printf("Array Before Sorting  : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    bubbleSort(arr, n);
    printf("\nArray After Sorting  : ");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
    return 0;
}
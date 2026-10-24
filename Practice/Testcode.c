#include <stdio.h>

/* BubbleSort */
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
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

/* Insertion Sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* Selection Sort */
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - i - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            int t = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = t;
        }
    }
}


/* Quick Sort */



int main()
{

    int arr[] = {5, 2, 4, 3, 1, 6};
    int n = sizeof(arr) / sizeof(int);
    printf("Array before Sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // bubbleSort(arr, n);
    // insertionSort(arr, n);
    selectionSort(arr,n);

    printf("\nArray after Sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

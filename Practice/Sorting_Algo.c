#include <stdio.h>

/* Bubble Sort */
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

/* Selection Sort */
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - i - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIdx] > arr[j])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

/* Insertion Sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n - 1; i++)
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

/* Quick Sort */
void swap(int arr[], int x, int y)
{
    int t = arr[x];
    arr[x] = arr[y];
    arr[y] = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (i <= high && arr[i] < pivot)
        {
            i++;
        }
        while (j > low && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr, i, j);
        }
    }
    swap(arr, low, j);
    return j;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


/* Merge Sort */
void merge(int arr[],int p,int q, int r){

}
void mergeSort(int arr[],int n){

}

/* Radix Sort*/
void radixSort(int arr[],int n){

}
int main()
{
    int arr[] = {3, 2, 1, 6, 4, 8, 5, 7, 9};
    int n = sizeof(arr) / sizeof(int);
    // bubbleSort(arr, n);
    // selectionSort(arr,n);
    // insertionSort(arr,n);
    // quickSort(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
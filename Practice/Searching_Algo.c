#include <stdio.h>

/* Linear Search */
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
}

/* Binary Search (Iterative Approach) */
int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
/* Binary Search ( Recursive approach ) */
int binarySearchRec(int arr[], int key, int low, int high)
{
    int mid = low + (high - low) / 2;
    if (key == arr[mid])
    {
        return mid;
    }
    else if (key < arr[mid])
    {
        return binarySearchRec(arr, key, low, mid - 1);
    }
    else
    {
        return binarySearchRec(arr, key, mid + 1, high);
    }
    return -1;
}

/* Index Sequential Search */
int indexSequentialSearch(int arr[], int size, int key, int gs)
{
    if(gs > size || size <= 0){
        return -1;
    }

    int N, start = 0, end = 0, val_idx = 0, flag = 0;
    if (size % gs == 0)
    {
        N = size / gs;
    }
    else
    {
        N = size / gs + 1;
    }

    int idx[N], val[N];
    for (int i = 0; i < size; i += gs)
    {
        idx[val_idx] = i;
        val[val_idx] = arr[i];
        val_idx++;
    }

    if (key < val[0])
    {
        return -1;
    }

    for (int i = 0; i < N; i++)
    {
        if (key == val[i])
        {
            return idx[i];
        }
        if (key < val[i])
        {
            start = idx[i - 1];
            end = idx[i] - 1;
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        for (int i = start; i <= end; i++)
        {
            if (key == arr[i])
            {
                return i;
            }
        }
        return -1;
    }
    else
    {
        start = idx[N - 1];
        for (int i = start; i < size; i++)
        {
            if (key == arr[i])
            {
                return i;
            }
        }
        return -1;
    }
}

int main()
{
    int arr[] = {1, 3, 5, 6, 7, 8, 9, 10, 12, 15, 16};
    int n = sizeof(arr) / sizeof(int);
    // int result = linearSearch(arr,n,16);
    // int result = binarySearch(arr, n, 16);
    // int result = binarySearchRec(arr,15,0,n);
    int result = indexSequentialSearch(arr, n, 16, 3);
    if (result != -1)
    {
        printf("Element found at Index : %d \n", result);
    }
    else
    {
        printf("Element not found ...! \n");
    }
    return 0;
}

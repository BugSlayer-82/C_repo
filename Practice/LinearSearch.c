/* Searching Algorithm's*/

#include <stdio.h>

/* 1 ===> Linear Search */
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

/* 2 ===> Binary Search (Iterative approach) */
int binarySearchIter(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
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

/* 3 ===> Binary Search (Recursive approach) */
int binarySearchRec(int arr[], int low, int high, int key)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] > key)
    {
        binarySearchRec(arr, low, mid - 1, key);
    }
    else
    {
        binarySearchRec(arr, mid + 1, high, key);
    }
}

/* 4 ===> Index Sequential Search */
int indexSequentialSearch(int arr[], int size, int key)
{
    int gs, n, val_index = 0, flag = 0;
    printf("Enter group size : ");
    scanf("%d", &gs);
    if (size % gs == 0)
    {
        n = size / gs;
    }
    else
    {
        n = size / gs + 1;
    }

    int value[n], idx[n];
    for (int i = 0; i < size; i += gs)
    {
        value[val_index] = arr[i];
        idx[val_index] = i;
        val_index++;
    }
    if (key < 0)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        if(key == value[i]){
            return idx[i];
        }
        if(key < value[i]){
            start = idx[i - 1];
            end= idx[i] -1;
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        for(int i = start; i <=end; i++){
            if(key== arr[i]){
                return i;
            }
        }
        return -1;
    }else{
        
    }
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 18, 19, 20};
    int n = sizeof(arr) / sizeof(int);
    int key;
    printf("Enter your number do you want in array : ");
    scanf("%d", &key);
    // int result = linearSearch(arr, n, key);
    // int result = binarySearchIter(arr,n,key);
    // int result = binarySearchRec(arr,0,n-1,key);
    int result = indexSequentialSearch(arr, n, key);
    if (result == -1)
    {
        printf("Element not found ...! \n");
    }
    else
    {
        printf("Element Found at index : %d \n", result);
    }

    return 0;
}
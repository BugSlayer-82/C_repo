#include <stdio.h>

int indexSequentialSearch(int arr[], int size, int k, int key)
{
    int N, val_idx = 0, start, end, flag = 0;
    if (size % k == 0)
    {
        N = size / k;
    }
    else
    {
        N = size / k + 1;
    }
    int idx[N], val[N];
    for (int i = 0; i < size; i += k)
    {
        idx[val_idx] = i;
        val[val_idx] = arr[i];
        val_idx++;
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
        return - 1;
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(arr) / sizeof(int);
    int target, k;
    printf("Enter your target element : ");
    scanf("%d", &target);
    printf("Enter group size : ");
    scanf("%d", &k);
    int result = indexSequentialSearch(arr, n, k, target);
    if (result == 1)
    {
        printf("Element is found at : %d\n", result);
    }
    else
    {
        printf("Element is not found ...!\n");
    }
    return 0;
}
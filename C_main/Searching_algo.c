#include <stdio.h>
// void linear(int[], int, int);
void binary(int[], int, int);
int main()
{
    int n, i, x;
    printf("Enter size of array ?\n");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter array element  %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter element x to search : ");
    scanf("%d", &x);
    // linear(arr, n, x);
    binary(arr, n, x);
    return 0;
}
// void linear(int arr[], int n, int x)
// {
//     int i, isfound = 0;
//     for (i = 0; i < n; i++)
//     {
//         if (arr[i] == x)
//         {
//             isfound = 1;
//             break;
//         }
//     }
//     if (isfound)
//     {
//         printf("The number x = %d, is found at index : %d \n", x, i + 1);
//     }
//     else
//     {
//         printf("The number x = %d, is not found in array ...!\n", x);
//     }
// }

void binary(int arr[], int n, int x)
{
    int i, l, h, mid, found = 0;
    l = 0;
    h = n - 1;
    mid = l + (h - l) / 2;
    printf("%d\n", mid);
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == x)
        {
            found = 1;
            break;
        }
        else if (x > arr[mid])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    if (found)
    {
        printf("Element X = %d, is found at index = %d \n", arr[mid], mid + 1);
    }
    else
    {
        printf("Element X = %d, doesn't found ....!\n", x);
    }
}
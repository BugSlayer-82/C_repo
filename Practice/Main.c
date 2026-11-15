#include <stdio.h>

void removeDuplicate(int arr[], int n)
{
    int k = 0;
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < k; j++)
        {
            if (arr[i] == temp[j])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            temp[k] = arr[i];
            k++;
        }
    }

    printf("After removing \n");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", temp[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {1, 1, 2, 3, 2, 4, 4};
    int n = sizeof(arr) / sizeof(int);
    removeDuplicate(arr, n);

    return 0;
}
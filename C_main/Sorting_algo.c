#include <stdio.h>
// void bubble_sort(int[], int); // Declare bubble sort funcion
// void insertion_sort(int[], int); // Declare insertion sort function
void selection_sort(int[], int);
int main()
{
    int x, i; // Declare two vaiable of name x,i
    printf("Enter size of array ? \n");
    scanf("%d", &x);        // Input the size of array or number of elements in array
    int arr[x];             // Declare an array of size x
    for (i = 0; i < x; i++) // Iterate till x - 1
    {
        printf("enter array element : ");
        scanf("%d", &arr[i]); // Input the array elements
    }
    // bubble_sort(arr, x); // Call the bubble sort funtion
    // insertion_sort(arr, x); // Call the insertion sort function
    selection_sort(arr, x); // Call the selecion sort function
    for (i = 0; i < x; i++) // Iterate through each element
    {
        printf("%d ", arr[i]); // Print elements of array
    }
    printf("\n"); // Print the next line

    return 0;
}

// void bubble_sort(int arr[], int n) // Define the bubble sort funtion
// {
//     int i, j;                   // Declare two variable for loop
//     for (i = 0; i < n - 1; i++) // Iterate through current element
//     {
//         int sorted = 0;                 // False when array is sorted already
//         for (j = 0; j < n - i - 1; j++) // Iterate through each element
//         {
//             if (arr[j] > arr[j + 1]) // Compare the adjacent
//             {
//                 int temp = arr[j];   // Assign the value of jth index ---> temp
//                 arr[j] = arr[j + 1]; // Assign the value of jth + 1 index ---> jth
//                 arr[j + 1] = temp;   // Assign the value of temp ---> jth + 1
//                 sorted = 1;          // True when array is unsorted
//             }
//         }
//         if (sorted == 0) // Is array was sorted then break and loop
//             break;
//     }
// }

// void insertion_sort(int arr[], int n)
// {
//     int i, j, key;
//     for (i = 1; i < n; i++)
//     {
//         key = arr[i];
//         j = i - 1;
//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;
//     }
// }

void selection_sort(int arr[], int n)
{
    int i, j, min, currIdx;
    for (i = 0; i < n; i++)
    {
        min = arr[i];
        currIdx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                currIdx = j;
                min = arr[j];
            }
        }
        int temp = arr[i];
        arr[i] = arr[currIdx];
        arr[currIdx] = temp;
    }
}
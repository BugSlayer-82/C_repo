#include<stdio.h>

int indexSequentialSearch(int arr[], int group, int target){
    // To divide the array into grounps
    return -1;
}

int main(){
    int arr[] = {2,3,4,5,6,7,8,9,10,11, 12,14,15,18,19,20};
    int target = 8;
    int indx = indexSequentialSearch(arr,target);

    if(indx == -1){
    printf("Element not found \n");
    }
    printf("Element not found : %d \n",indx);


    return 0;
}
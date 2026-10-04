 #include<stdio.h>

int indexSequentialSearch(int arr[], int grpSize, int target){
    // To divide the array into groups
    
    return -1;
}

int main(){
    int arr[] = {2,3,4,5,6,7,8,9,10,11, 12,14,15,18,19,20};
    int target = 8;
    int grpSize = 3;
    int indx = indexSequentialSearch(arr,0,target);

    if(indx == -1){
    printf("Element not found \n");
    }
    printf("Element not found : %d \n",indx);


    return 0;
}
#include<stdio.h>

int slidingWin(int arr[],int n,int k){
    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += arr[i];
    }
    int maxSum = sum;
    for(int i = k; i < n; i++){
        sum+= arr[i] - arr[i - k];
        if(maxSum < sum){
            maxSum = sum;
        }
    }
    return maxSum;
}

int main(){
    int arr[] = {2,3,5,6,8,9};
    int  n = sizeof(arr)/sizeof(int);
    int k = 3;
    int result = slidingWin(arr,n,k);
    printf("Maximum : %d \n",result);
    
    return 0;
}
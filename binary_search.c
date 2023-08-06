#include<stdio.h>
int binary_search(int arr[],int n,int value){
    int left,right,mid;
    left = 0;
    right = n-1;
    while(left <= right){
        mid = (left+right)/2;
        if(arr[mid]==value){
            return mid;
        }
        if(value>arr[mid]){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}
int main(){
    int n ,i , value;
    scanf("%d",&n);
    int arr[n];
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&value);
    int result = binary_search(arr,n,value);
    if(result == -1){
        printf("value not found.");
    }
    else{
        printf("value found at index %d\n",result);
    }
}
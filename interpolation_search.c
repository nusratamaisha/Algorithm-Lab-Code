#include<stdio.h>
int interpolation_search(int arr[],int n,int value){
    int low=0,high=n-1,mid;
    while(low <= high){
        mid = low + ((high-low)/(arr[high]-arr[low]))*(value-arr[low]);
        if(arr[mid]==value){
            return mid;
        }
        if(value>arr[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
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
    int result = interpolation_search(arr,n,value);
    if(result == -1){
        printf("value not found.");
    }
    else{
        printf("value found at index %d\n",result);
    }
}
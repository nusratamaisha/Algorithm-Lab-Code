#include<stdio.h>
void linear_search(int arr[],int n,int value){
    int i,found = 0;
    for(i=0; i<n; i++){
        if(arr[i]==value){
            printf("value found at index %d\n",i);
            found=1;
        }
    }
    if(!found){
        printf("value not found.");
    }
}
int main(){
    int n,i,value;
    scanf("%d",&n);
    int arr[n];
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&value);
    linear_search(arr,n,value);
}
#include<iostream>
using namespace std;
int main(){
    int n,i,j,index_min,temp;
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    for(i=0; i<n-1; i++){
        index_min = i;
        for(j=i+1; j<n;j++){
            if(arr[j]<arr[index_min]){
                index_min = j;
            }
        }
        if(index_min != i){
            temp = arr[i];
            arr[i]=arr[index_min];
            arr[index_min]=temp;
        }
    }
    for(i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
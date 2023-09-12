#include<iostream>
using namespace std;
int main(){
    int n,i,j,item;
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    for(i=1; i<n; i++){
        item = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > item){
            arr[j+1] = arr[j];
            j = j-1;
            arr[j+1] = item;
        }
    }
    for(i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
}
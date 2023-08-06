#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,1,1,1,1,1};
    int i,j;
    int length = sizeof(arr)/sizeof(arr[0]);
    for(i=0; i<length; i++){
        for(j=i+1; j<length; j++){
            if(arr[i]==arr[j]){
                cout<<arr[j];
            }
        }
    }
}
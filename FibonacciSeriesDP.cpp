#include<iostream>
#define MAX 100
using namespace std; 
long long memo[MAX];
long long fibonacci(int n){
    if(memo[n] != -100){
        return memo[n];
    }
    if(n<=1){
        return n;
    }
    else{
        memo[n] = fibonacci(n-2)+fibonacci(n-1);
        return memo[n];
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<MAX; i++){
        memo[i] = -100;
    }
    cout<<"Fibonacci number : "<<fibonacci(n)<<endl;
}
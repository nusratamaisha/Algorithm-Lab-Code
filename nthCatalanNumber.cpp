#include<iostream>
#define MAX 100
using namespace std;
long long c[MAX];

//dp approach -- time complexity O(n^2)
long long catalan(int n){
    c[0] = c[1] = 1;
    int i,j;
    for(i=2; i<=n; i++){
        c[i] = 0;
        for(j=0; j<i; j++){
            c[i] += c[j] * c[i-j-1];
        }
    }
    return c[n];
}
/*
//recursive approach -- time complexity O(2^n)
long long catalan(int n){
    int i;
    long long result = 0;
    if(n<=1){
        return 1;
    }

    for(i=0; i<n; i++){
        result += catalan(i) * catalan(n-i-1);
    }
    return result;
}
*/
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cout << catalan(i) << " ";
    }
        
}
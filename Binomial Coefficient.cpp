#include<iostream>
using namespace std;

// time complexity -- O(n*r)
long long binomial_coefficient(int n,int r){
    long long bc[100][100];
    int i,j;
    for (i = 0; i <= n; i++) {
        bc[i][0] = 1;
    }
    for (j = 0; j <= n; j++) {
        bc[j][j] = 1; 
    }
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i && j <= r; j++) {
            bc[i][j] = bc[i - 1][j - 1] + bc[i - 1][j];
        }
    }
    return bc[n][r];
}
int main(){
    int n,r;
    cin>>n>>r;
    if(n<r){
        cout<<"n should be greater than r to calculate binomial coefficient"<<endl;
    }
    else {
        cout<<"Binomial coefficient for "<<n<<" and "<<r<<" is: "<<binomial_coefficient(n,r);
    }
}
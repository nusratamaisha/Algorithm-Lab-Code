#include<iostream>
using namespace std;
int cutting_rod(int price[],int length){
    int dp[length+1][length+1];
    int i,j;
    for(i=0;i<=length; i++){
        dp[i][0] = 0;
    }
    for(j=1;j<=length; j++){
        dp[0][j] = 0;
    }
    for(i=1; i<=length;i++){
        for(j=1; j<=length; j++){
            if (i <= j) {
                dp[i][j] = max(dp[i][j], price[i] + dp[i][j - i]); // Update the maximum value for length i and cut j
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    return dp[length][length];
}
int main(){
    int length,i;
    cin>>length;
    int price[length];
    for(i=0; i<length; i++){
        cin>>price[i];
    }
    cout<<"Maximum Profit: "<<cutting_rod(price,length);
}
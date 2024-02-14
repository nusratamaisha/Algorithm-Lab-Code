#include<iostream>
using namespace std;

int coin_change(int coins[], int n, int target){
    int dp[n + 1][target + 1];
    
    // Initialization
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int j = 1; j <= target; j++){
        dp[0][j] = j;
    }
    
    // DP computation
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= target; j++){
            if(coins[i - 1] > j){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
    }
    
    return dp[n][target]; 
}

int main(){
    int n, target;
    cin >> n >> target;
    
    int coins[n];
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    
    cout << "Minimum coins required: " << coin_change(coins, n, target) << endl;
}

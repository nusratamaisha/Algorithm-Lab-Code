#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, value, i, count = 0;
    cout<<"Enter the value of change(Money): ";
    cin>>value;
    cout<<"Enter the number of total coins: ";
    cin >> n;
    
    int coins[n],coinSequence[n];
    cout<<"Enter the values for "<<n<<" coins:";
    for (i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins, coins+n, greater<int>());
    cout<<"Sorted Coins are:"<<endl;
    for(i=0; i<n; i++){
        cout<<coins[i]<<" ";
    }
    cout<<endl;

    for (i = 0; i < n && value != 0; i++) {
        if (coins[i] <= value) {
            int numCoins = value / coins[i];
            coinSequence[i] = numCoins;
            count += numCoins; 
            value -= numCoins * coins[i];
        }
        else{
            coinSequence[i] = 0;
        }
    }
    
    cout << "Total coins needed: " << count<<endl;

    for(i=0; i<n; i++){
        cout << coins[i] <<" paisa = "<< coinSequence[i]<<endl;
    }
    return 0;
}

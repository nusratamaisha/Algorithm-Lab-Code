#include<iostream>
using namespace std;

int cutting_rod(int price[], int length) {
    int dp[length + 1];
    dp[0] = 0; // Base case

    // Bottom-up DP approach
    for (int i = 1; i <= length; i++) {
        int maxProfit = -1; // Initialize maximum profit for current length i
        for (int j = 0; j < i; j++) {
            maxProfit = max(maxProfit, price[j] + dp[i - j - 1]); // Consider all possible cuts for length i
        }
        dp[i] = maxProfit; // Store the maximum profit for length i
    }
    return dp[length]; // Return the maximum profit for the entire rod
}

int main() {
    int length;
    cout << "Enter the length of the rod: ";
    cin >> length;

    int price[length];
    cout << "Enter the price for each length from 1 to " << length << ":\n";
    for (int i = 0; i < length; i++) {
        cin >> price[i];
    }

    cout << "Maximum Profit: " << cutting_rod(price, length) << endl;
    return 0;
}

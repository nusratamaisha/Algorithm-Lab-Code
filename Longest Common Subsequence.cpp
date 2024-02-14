/*

For Video explanation of this and all other porblems please visit to youtube cannel - Hindi Tutorials Darashan.
https://www.youtube.com/hinditutorialsdarshan
*/
#include <iostream>
using namespace std;

int longestcommonsubsequence(int a, int b, string s1, string s2)
{
    int lcs = 0;
    int dp[a+1][b+1];
    for(int i = 0; i <= a; i++) {
        for(int j = 0; j <= b; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if(s1[i] == s2[j]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[a][b];
}

int main() {
    
    int a, b;
    cin >> a >> b;
    string s1;
    string s2;
    cin >> s1 >> s2;
    
    cout << longestcommonsubsequence(a, b, s1, s2) << endl;

	return 0;
}

/*
INPUT:
6 6
ABCDGH
AEDFHR

OUTPUT:
3
*/
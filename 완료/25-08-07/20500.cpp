#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    dp = vector<vector<int>>(n+1, vector<int>(3, 0));

    dp[1][2] = 1;
    for(int i = 2; i <= n; i++){
        dp[i][0] = (dp[i-1][1]+dp[i-1][2])%1000000007;
        dp[i][1] = (dp[i-1][2]+dp[i-1][0])%1000000007;
        dp[i][2] = (dp[i-1][0]+dp[i-1][1])%1000000007;
        
    }
    cout << dp[n][0];

    return 0;
}

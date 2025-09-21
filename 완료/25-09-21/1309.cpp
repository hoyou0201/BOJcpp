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
    dp = vector<vector<int>>(n, vector<int>(4));
    dp[0] = {1,1,1};
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
        dp[i][1] = dp[i-1][0]+dp[i-1][2];
        dp[i][2] = dp[i-1][0]+dp[i-1][1];
        dp[i][0] %= 9901;
        dp[i][1] %= 9901;
        dp[i][2] %= 9901;
    }
    cout << (dp[n-1][0]+dp[n-1][1]+dp[n-1][2])%9901;

    return 0;
}

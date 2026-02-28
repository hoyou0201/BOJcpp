#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9+7;

int n;
string s;
vector<vector<long long>> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;
    dp = vector<vector<long long>>(n+1, vector<long long>(4));

    dp[0] = {0,0,0,0};
    
    for (int i = 1; i < n+1; i++) {
        char c = s[i-1];
        dp[i] = dp[i-1];
        if(c == 'W'){
            dp[i][0] += 1;
        }
        else if(c == 'H'){
            dp[i][1] += dp[i-1][0];
        }
        else if(c == 'E'){
            dp[i][2] += dp[i-1][1];
            dp[i][3] += dp[i-1][2]+dp[i-1][3];
        }
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        dp[i][2] %= MOD;
        dp[i][3] %= MOD;
    }

    cout << dp[n][3]%MOD;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, k;
vector<int> coins;
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    coins = vector<int>(n);
    dp = vector<int>(k+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            dp[j] += dp[j-coins[i]];
        }
    }
    cout << dp[k];
    return 0;
}

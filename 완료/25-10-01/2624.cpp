#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, k;
vector<pair<int,int>> coins;
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t >> k;

    coins = vector<pair<int,int>>(k);
    dp = vector<int>(t+1);
    dp[0] = 1;

    for(int i = 0; i < k; i++){
        int p, n;
        cin >> p >> n;
        coins[i].first = p;
        coins[i].second = n;
    }
    for (int i = 0; i < k; i++) {
        for (int j = t; j >= 0; j--) {
            for (int u = 1; u <= coins[i].second; u++) {
                if(j-coins[i].first*u < 0) break;
                dp[j] += dp[j-coins[i].first*u];
            }
        }
    }
    cout << dp[t];
    return 0;
}

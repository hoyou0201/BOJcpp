#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> wine;
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    wine = vector<int>(n, 0);
    dp = vector<int>(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> wine[i];
    }

    dp[1] = wine[0];
    dp[2] = wine[0]+wine[1];
    m = dp[2];
    for(int i = 3; i <= n; i++){
        dp[i] = max(dp[i-2], dp[i-3]+wine[i-2])+wine[i-1];
        m = max(dp[i], m);
        dp[i] = m;
    }
    cout << m;
    return 0;
}

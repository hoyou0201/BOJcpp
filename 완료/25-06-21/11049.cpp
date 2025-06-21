#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> a;
int dp[510][510];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    a = vector<pair<int,int>>(n, {0,0});
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 1; i < n; i++) { // i는 length
        for (int j = 0; j < n-i; j++) {
            for (int k = j+1; k <= j+i; k++) {
                if(dp[j][j+i] == 0) dp[j][j+i] = a[j].first*a[k].first*a[j+i].second+dp[j][k-1]+dp[k][j+i];
                dp[j][j+i] = min(dp[j][j+i], a[j].first*a[k].first*a[j+i].second+dp[j][k-1]+dp[k][j+i]);
            }
        }
    }

    cout << dp[0][n-1];
    return 0;
}

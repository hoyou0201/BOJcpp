#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, h, d, k;
vector<vector<pair<int,int>>> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> h >> d >> k;
    dp = vector<vector<pair<int,int>>>(n+2);
    dp[0] = {{h,h}};
    dp[1] = vector<pair<int,int>>(2);

    for(int i = 1; i < n+1; i++){
        int t;
        cin >> t;

        dp[i+1] = vector<pair<int,int>>(i+2);
        //웅크리기
        for(int j = 0; j < i; j++){
            int dist = d+j*k;
            int damage = max(0, t-dist);
            dp[i][j].first = max(dp[i][j].first, dp[i-1][j].first-damage/2);
            dp[i][j].second = max(dp[i][j].second, dp[i-1][j].second-damage/2);
            dp[i+1][j+1].second = max(dp[i+1][j+1].second, dp[i-1][j].first-damage);
            damage = max(0, damage-k);
            dp[i][j+1].first = max(dp[i][j+1].first, dp[i-1][j].first-damage);
            dp[i][j+1].second = max(dp[i][j+1].second, dp[i-1][j].second-damage);
        }
    }
    int overall_max = 0;
    for (auto &p : dp[n]) {
        overall_max = max({overall_max, p.first, p.second});
    }
    if(overall_max == 0) overall_max = -1;
    cout << overall_max;

    return 0;
}

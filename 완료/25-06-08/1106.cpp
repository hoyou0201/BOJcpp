#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, m, mm;
vector<int> dp;
vector<pair<int,int>> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    dp = vector<int>(2000, 1000000);
    dp[0] = 0;

    cin >> c >> n;

    a = vector<pair<int,int>>(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        m = max(m, a[i].second);
    }

    for (int i = 1; i <= c+m; i++) {
        for (int j = 0; j < n; j++) {
            if(i-a[j].second >= 0){
                dp[i] = min(dp[i], dp[i-a[j].second]+a[j].first);
            }
        }
        if(i >= c){
            if(mm == 0){
                mm = dp[i];
            }
            else{
                mm = min(dp[i], mm);
            }
        }
    }
    cout << mm;
    

    return 0;
}
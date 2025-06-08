#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
int dp[1005];
vector<pair<int,int>> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> c >> n;

    a = vector<pair<int,int>>(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 1; i <= c; i++) {
        for (int j = 0; j < n; j++) {
            if(i-a[j].second >= 0){
                if(dp[i] == 0){
                    dp[i] = dp[i-a[j].second]+a[j].first;
                }
                else{
                    dp[i] = min(dp[i], dp[i-a[j].second]+a[j].first);
                }
            }
        }
    }
    cout << dp[c];
    

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for(int _ = 0; _ < T; _++){
        cin >> n >> m;
        long long s = 0l;
        vector<vector<long long>> dp(m+1, vector<long long>(n));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i < n; i++){
            vector<long long> sss(m+1);
            sss[m] = dp[m][i-1];
            for(int j = m-1; j > 0; j--){
                sss[j] = sss[j+1] + dp[j][i-1];
                if(j*2 <= m){
                    dp[j][i] = sss[j*2];
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            s += dp[i][n-1];
        }
        cout << s << '\n';
    }

    return 0;
}

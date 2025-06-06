#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int n, ans;
int a[1005][3];
int dp[1005][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    ans = 1000*10000;
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            if(j == i){
                dp[0][j] = a[0][j];
            }
            else{
                dp[0][j] = 2000;
            }
        }
        for (int j = 1; j < n; j++) {
            dp[j][0] = a[j][0] + min(dp[j-1][1], dp[j-1][2]);
            dp[j][1] = a[j][1] + min(dp[j-1][0], dp[j-1][2]);
            dp[j][2] = a[j][2] + min(dp[j-1][0], dp[j-1][1]);
        }
        for (int j = 0; j < 3; j++) {
            if(j!=i){
                ans = min(ans, dp[n-1][j]);
            }
        }
        
    }
    cout << ans;
    

    return 0;
}
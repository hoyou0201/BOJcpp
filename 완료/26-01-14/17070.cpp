#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[17][17][3]; //0가로, 1세로, 2 대각선
int map[17][17];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }
    dp[1][2][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            //가로
            if(j < n && map[i][j+1] != 1){
                dp[i][j+1][0] += dp[i][j][0] + dp[i][j][2];
            }
            //세로
            if(i < n && map[i+1][j] != 1){
                dp[i+1][j][1] += dp[i][j][1] + dp[i][j][2];
            }
            //대각
            if(i < n && j < n && map[i][j+1] != 1 && map[i+1][j] != 1 && map[i+1][j+1] != 1){
                dp[i+1][j+1][2] += dp[i][j][0]+dp[i][j][1] + dp[i][j][2];
            }
        }
    }
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    return 0;
}

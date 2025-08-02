#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<char>> info_island;
vector<vector<int>> dp;
int carrot;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    info_island = vector<vector<char>>(n, vector<char>(m));
    carrot = -1;
    dp = vector<vector<int>>(n, vector<int>(m, -1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> info_island[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if(info_island[i][j] == 'R'){
                if(j == m-1){
                    break;
                }
                dp[i][j+1] = 0;
                if(i!=0){
                    dp[i-1][j+1] = 0;
                }
                if(i!=n-1){
                    dp[i+1][j+1] = 0;
                }
            }
            if(dp[i][j] != -1){
                if(info_island[i][j] == '.'){
                    if(j == m-1){
                        continue;
                    }
                    dp[i][j+1] = max(dp[i][j], dp[i][j+1]);
                    if(i!=0){
                        dp[i-1][j+1] = max(dp[i][j], dp[i-1][j+1]);
                    }
                    if(i!=n-1){
                        dp[i+1][j+1] = max(dp[i][j], dp[i+1][j+1]);
                    }
                }
                else if(info_island[i][j] == 'C'){
                    if(j == m-1){
                        continue;
                    }
                    dp[i][j+1] = max(dp[i][j]+1, dp[i][j+1]);
                    if(i!=0){
                        dp[i-1][j+1] = max(dp[i][j]+1, dp[i-1][j+1]);
                    }
                    if(i!=n-1){
                        dp[i+1][j+1] = max(dp[i][j]+1, dp[i+1][j+1]);
                    }
                }
                else if(info_island[i][j] == 'O'){
                    carrot = max(carrot, dp[i][j]);
                    if(j == m-1){
                        continue;
                    }
                    dp[i][j+1] = max(dp[i][j], dp[i][j+1]);
                    if(i!=0){
                        dp[i-1][j+1] = max(dp[i][j], dp[i-1][j+1]);
                    }
                    if(i!=n-1){
                        dp[i+1][j+1] = max(dp[i][j], dp[i+1][j+1]);
                    }
                }
            }
        }
    }
    cout << carrot;
    return 0;
}

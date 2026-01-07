#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[101][10][1<<10];

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    //dp초기값
    for (int i = 1; i < 10; i++) {
        dp[1][i][1<<i] = 1;
    }


    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            for(int k = 1; k < 1<<10; k+= 1){
                if(j < 9){
                    dp[i+1][j][k|1<<j] += dp[i][j+1][k];
                    dp[i+1][j][k|1<<j] %= 1000000000;
                }
                if(j > 0){
                    dp[i+1][j][k|1<<j] += dp[i][j-1][k];
                    dp[i+1][j][k|1<<j] %= 1000000000;
                }
            }
        }
        
    }
    long long r = 0;
    for(int j = 0; j < 10; j++){
        r += dp[n][j][(1<<10)-1];
        r %= 1000000000;
    }
    cout << r;


    return 0;
}

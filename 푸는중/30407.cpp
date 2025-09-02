#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, h, d, k;
vector<map<int, int>> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> h >> d >> k;
    dp = vector<map<int, int>>(n+1);
    dp[0][d] = h;
    for(int i = 0; i < n; i++){
        int r;
        cin >> r;
        for(auto [key, value] : dp[i]){
            r -= key;
            if(r < 0) r = 0;
            dp[i+1][key] = value-r/2;
            r -= k;
            if(r < 0) r = 0;
            dp[i+1][key+k] = value-r/2;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    int k = 2;
    int t = 1;
    int s = 1;
    dp = {1};
    while(dp[dp.size()-1] < n){
        t += k;
        s += t;
        dp.push_back(s);
        k++;
    }
    int g = 0;
    int im = dp.size();
    while(n > 0){
        int m= 0;
        for(int i = 0; i < im; i++){
            if(dp[i] > n){
                im = i;
                break;
            }
            m = dp[i];
        }
        if(m == 0) break;
        n -= m;
        g++;
    }
    cout << g;
    

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e18
using namespace std;
struct ans{
    long long t;
    vector<int> j;
};

long long maxd, n;
vector<long long> jungbi;
vector<long long> times;
vector<ans> dp;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> maxd >> n;
    jungbi = vector<long long>(n+2);
    dp = vector<ans>(n+2, {(long long)INF, vector<int>()});
    times = vector<long long>(n+1);
    dp[0] = {0ll, {}};
    jungbi[n+1] = 0ll;
    for(int i = 0; i < n+1; i++){
        cin >> times[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> jungbi[i];
    }
    for(int i = 0; i <= n+1; i++){
        long long t = 0ll;
        for(int j = i+1; j <= n+1; j++){
            t += times[j-1];
            if(t > maxd){
                break;
            }
            if(dp[j].t > dp[i].t+jungbi[j]){
                dp[j].t = dp[i].t+jungbi[j];
                dp[j].j = dp[i].j;
                if(j != n+1)
                    dp[j].j.push_back(j);
            }
        }
    }
    cout << dp[n+1].t << '\n';
    cout << dp[n+1].j.size() << '\n';
    for(int i : dp[n+1].j){
        cout << i << ' ';
    }

    return 0;
}

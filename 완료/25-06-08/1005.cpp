#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T, n, k;
vector<int> pre;
vector<vector<int>> graph;
vector<int> times;
vector<long> dp;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for(int _=0; _<T; _++){
        cin >> n >> k;
        times = vector<int>(n+1);
        pre = vector<int>(n+1);
        dp = vector<long>(n+1);
        graph = vector<vector<int>>(n+1,vector<int>());
        q = queue<int>();
        for(int i = 0; i < n; i++){
            cin >> times[i+1];
        }
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            pre[b]++;
        }
        for (int i = 1; i <= n; i++) {
            if(pre[i] == 0){
                q.push(i);
                dp[i] = times[i];
            }
        }
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for (int i = 0; i < graph[t].size(); i++) {
                int g = graph[t][i];
                dp[g] = max(dp[g], dp[t]+times[g]);
                pre[g]--;
                if(pre[g] == 0){
                    q.push(g);
                }
            }
        }
        int w;
        cin >> w;
        cout << dp[w] << '\n';


    }

    return 0;
}

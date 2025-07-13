#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> graph;
vector<vector<int>> dp;
vector<bool> visit;

void dfs(int node, int parent){
    visit[node] = true;
    dp[node][1] = 1;
    if(graph[node].size() == 1 && graph[node][0] == parent){
        return;
    }
    else{
        for (int child : graph[node]) {
            if(!visit[child]){
                dfs(child, node);
                dp[node][0] += dp[child][1];
                dp[node][1] += min(dp[child][1], dp[child][0]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    graph = vector<vector<int>>(n+1, vector<int>());
    dp = vector<vector<int>>(n+1, vector<int>(2, 0));
    visit = vector<bool>(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cout << min(dp[1][1], dp[1][0]);

    return 0;
}

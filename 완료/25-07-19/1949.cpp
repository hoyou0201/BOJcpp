#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> people;
vector<vector<int>> graph;
vector<pair<int, int>> dp;

void dfs(int node, int parent){
    dp[node].first = people[node];
    dp[node].second = 0;
    for(int g : graph[node]){
        if(g == parent){
            continue;
        }
        dfs(g, node);
        dp[node].first += dp[g].second;
        dp[node].second += max(dp[g].first, dp[g].second);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    people = vector<int>(n+1);
    dp = vector<pair<int, int>>(n+1);
    graph = vector<vector<int>>(n+1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> people[i];
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    cout << max(dp[1].first, dp[1].second);
    return 0;
}

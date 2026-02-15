#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, s, t;

vector<vector<pair<int,int>>> graph;

vector<int> dist;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    graph = vector<vector<pair<int,int>>>(n+1);
    dist = vector<int>(n+1, INF);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    cin >> s >> t;

    q.emplace(0, s);
    while(!q.empty()){
        auto [w, node] = q.top();
        q.pop();

        if(dist[node] <= w) continue;
        dist[node] = w;
        if(node == t) break;

        for(auto [_node, _w] : graph[node]){
            q.emplace(_w+w, _node);
        }
    }

    cout << dist[t];

    return 0;
}

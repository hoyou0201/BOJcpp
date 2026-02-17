#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
const int INF = 1000000000;

vector<vector<pair<int,int>>> graph;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<int> dist;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    graph = vector<vector<pair<int,int>>>(n+1);
    dist = vector<int>(n+1, INF);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);
    }

    pq.emplace(0,1);

    while(!pq.empty()){
        auto [d, node] = pq.top();
        pq.pop();

        if(dist[node] <= d) continue;

        dist[node] = d;

        if(node == n){
            break;
        }

        for(auto [_d, _node] : graph[node]){
            pq.emplace(_d+d, _node);
        }
    }
    cout << dist[n];

    return 0;
}

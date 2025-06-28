#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int v, e, k;
vector<bool> visit;
vector<vector<pair<int,int>>> g;
vector<int> d;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
int infity = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> v >> e >> k;
    visit = vector<bool>(v+1);
    d = vector<int>(v+1, infity);
    g = vector<vector<pair<int,int>>>(v+1, vector<pair<int,int>>());
    q = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>();
    for(int i = 0; i < e; i++){
        int u, vv, w;
        cin >> u >> vv >> w;
        auto it = find_if(g[u].begin(), g[u].end(), [vv](const pair<int,int>& p) {
            return p.second == vv;
        });
        if(it != g[u].end()){
            it->first = min(it->first, w);
        }
        else{
            g[u].push_back({w,vv});
        }
    }
    d[k] = 0;
    q.push({0, k});
    while(!q.empty()){
        int vv = q.top().second;
        int w = q.top().first;
        q.pop();
        if(visit[vv]){
            continue;
        }
        visit[vv] = true;
        for (int i = 0; i < g[vv].size(); i++) {
            if(visit[g[vv][i].second]) continue;
            d[g[vv][i].second] = min(d[g[vv][i].second], g[vv][i].first+d[vv]);
            q.push({d[g[vv][i].second], g[vv][i].second});
        }
    }
    for (int i = 1; i <= v; i++) {
        if(d[i] == infity){
            cout << "INF\n";
        }
        else{
            cout << d[i] << '\n';
        }
    }

    return 0;
}

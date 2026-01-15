#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, e, a, b, c, v1, v2;

vector<vector<int>> graph;
vector<long> tov1;
vector<long> v1to;
vector<long> v2to;
vector<bool> visit;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qv1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> e;

    graph = vector<vector<int>>(n+1, vector<int>(n+1));

    for (int i = 0; i < e; i++){
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    cin >> v1 >> v2;

    tov1 = vector<long>(n+1, 1e9);
    tov1[1] = 0;
    qv1.push({0,1});
    bool bv1 = false;
    bool bv2 = false;
    visit = vector<bool>(n+1, false);
    while(!qv1.empty()){
        auto [t, v] = qv1.top();
        qv1.pop();
        if(visit[v]){
            continue;
        }
        if(v == v1) bv1 = true;
        if(v == v2) bv2 = true;
        if(bv1 && bv2) break;
        visit[v] = true;
        for (int i = 1; i < n+1; i++) {
            if(graph[v][i] != 0 && !visit[i]){
                tov1[i] = min(tov1[i], (long)tov1[v]+graph[v][i]);
                qv1.push({tov1[i], i});
            }
        }
    }
    qv1 = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>();
    v1to = vector<long>(n+1, 1e9);
    v1to[v1] = 0;
    qv1.emplace(0, v1);
    bv1 = false;
    bv2 = false;
    visit = vector<bool>(n+1, false);
    while(!qv1.empty()){
        auto [t, v] = qv1.top();
        qv1.pop();
        if(visit[v]){
            continue;
        }
        if(v == n) bv1 = true;
        if(v == v2) bv2 = true;
        if(bv1 && bv2) break;
        visit[v] = true;
        for (int i = 1; i < n+1; i++) {
            if(graph[v][i] != 0 && !visit[i]){
                v1to[i] = min(v1to[i], (long)v1to[v]+graph[v][i]);
                qv1.emplace(v1to[i], i);
            }
        }
    }
    qv1 = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>();
    v2to = vector<long>(n+1, 1e9);
    v2to[v2] = 0;
    qv1.emplace(0, v2);
    bv1 = false;
    bv2 = false;
    visit = vector<bool>(n+1, false);
    while(!qv1.empty()){
        auto [t, v] = qv1.top();
        qv1.pop();
        if(visit[v]){
            continue;
        }
        if(v == n) bv1 = true;
        if(v == v1) bv2 = true;
        if(bv1 && bv2) break;
        visit[v] = true;
        for (int i = 1; i < n+1; i++) {
            if(graph[v][i] != 0 && !visit[i]){
                v2to[i] = min(v2to[i], (long)v2to[v]+graph[v][i]);
                qv1.emplace(v2to[i], i);
            }
        }
    }
    if((long)tov1[v1]+v1to[v2]+v2to[n] > (long)tov1[v2]+v2to[v1]+v1to[n]){
        if((long)tov1[v2]+v2to[v1]+v1to[n] >= 1e9){
            cout << -1;
            return 0;
        }
        cout << (long)tov1[v2]+v2to[v1]+v1to[n];
    }
    else{
        if((long)tov1[v1]+v1to[v2]+v2to[n] >= 1e9){
            cout << -1;
            return 0;
        }
        cout << (long)tov1[v1]+v1to[v2]+v2to[n];
    }

    return 0;
}

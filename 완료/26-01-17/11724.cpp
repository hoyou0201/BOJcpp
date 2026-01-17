#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, b;
vector<vector<int>> graph;
vector<bool> visit;

void dfs(int v){
    visit[v] = true;
    for(int i : graph[v]){
        if(!visit[i]) dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    graph = vector<vector<int>>(n+1);
    visit = vector<bool>(n+1);

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int r = 1;
    dfs(1);
    bool c = true;
    for(int i = 1; i < n+1; i++){
        c &= visit[i];
    }
    while(true){
        int k;
        for(k = 1; k < n+1; k++){
            if(!visit[k]){
                r++;
                dfs(k);
                break;
            }
        }
        if(k == n+1){
            break;
        }
    }
    cout << r;

    return 0;
}

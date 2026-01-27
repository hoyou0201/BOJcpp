#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b, w;

vector<vector<pair<int,int>>> tree;
vector<int> dist;

void dfs(int node, int we){
    dist[node] = we;
    for (auto [i, wei] : tree[node]) {
        if(dist[i] == -1){
            dfs(i, we+wei);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    tree = vector<vector<pair<int,int>>>(n+1);

    for(int i = 0; i < n-1; i++){
        cin >> a >> b >> w;
        tree[a].emplace_back(b, w);
        tree[b].emplace_back(a, w);
    }
    dist = vector<int>(n+1, -1);
    dfs(1, 0);
    int k = max_element(dist.begin(), dist.end())-dist.begin();
    dist = vector<int>(n+1, -1);
    dfs(k, 0);
    cout << *max_element(dist.begin(), dist.end());

    return 0;
}

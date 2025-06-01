#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, r, q, u, v;
vector<vector<int>> nodes;
vector<int> count_node;

int count(int pre, int now){
    count_node[now] = 1;
    for (int i = 0; i < nodes[now].size(); i++) {
        if(nodes[now][i] != pre){
            count_node[now] += count(now, nodes[now][i]);
        }
    }
    return count_node[now];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> r >> q;
    nodes = vector<vector<int>>(n+1);
    count_node = vector<int>(n+1, 0);
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    count(-1, r);
    for (int i = 0; i < q; i++) {
        cin >> u;
        cout << count_node[u]<< endl;
    }
    
    
}
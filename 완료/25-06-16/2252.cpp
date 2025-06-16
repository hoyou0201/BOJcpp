#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> d;
vector<vector<int>> graph;
queue<int> q;
vector<int> r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    d = vector<int>(n+1,0);
    graph = vector<vector<int>>(n+1, vector<int>());
    q = queue<int>();
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        d[b]+=1;
    }
    for(int i = 1; i <=n; i++){
        if(d[i] == 0){
            q.push(i);
        }
    }
    r = vector<int>();
    while(q.size()){
        int t = q.front();
        r.push_back(t);
        q.pop();
        for(int i : graph[t]){
            d[i]--;
            if(d[i] == 0){
                q.push(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << r[i] << ' ';
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> d;
priority_queue<int, vector<int>, greater<int>> q;

vector<int> r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    graph = vector<vector<int>>(n+1, vector<int>());
    d = vector<int>(n+1);
    q = priority_queue<int, vector<int>, greater<int>>();
    r = vector<int>();
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        d[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if(d[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int t = q.top();
        q.pop();
        r.push_back(t);

        for(int i : graph[t]){
            if(--d[i] == 0){
                q.push(i);
            }
        }
        
    }
    for (int i = 0; i < n; i++) {
        cout << r[i] << " ";
    }
    return 0;
}

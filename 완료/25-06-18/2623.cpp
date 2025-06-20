#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> d;
queue<int> q;
vector<int> result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    d = vector<int>(n+1, 0);
    graph = vector<vector<int>>(n+1, vector<int>());
    q = queue<int>();
    result = vector<int>();

    for (int i = 0; i < m; i++) {
        int nm, a, b;
        a = 0;
        cin >> nm;
        for (int j = 0; j < nm; j++) {
            cin >> b;
            if(a!=0){
                graph[a].push_back(b);
                d[b] += 1;
            }
            a = b;
        }
    }

    for (int i = 1; i <= n; i++) {
        if(d[i] == 0){
            q.push(i);
        }
    }
    while(q.size() != 0){
        int t = q.front();
        q.pop();
        result.push_back(t);

        for(int i : graph[t]){
            if(--d[i] == 0){
                q.push(i);
            }
        }
    }

    for (int i : d) {
        if(i!=0){
            cout << 0;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << '\n';
    }


    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
    int u, v, w;
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};


int tc, n, m, w, s, e, t;

vector<int> dist;
vector<edge> edges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> tc;

    for (int _ = 0; _ < tc; _++) {
        cin >> n >> m >> w;
        dist = vector<int>(n+1, 0);
        edges = vector<edge>();
        for (int __ = 0; __ < m; __++) {
            cin >> s >> e >> t;
            edges.emplace_back(s, e, t);
            edges.emplace_back(e, s, t);
        }
        for (int __ = 0; __ < w; __++) {
            cin >> s >> e >> t;
            edges.emplace_back(s, e, t*-1);
        }
        for (int __ = 0; __ < n-1; __++) {
            for(edge ed : edges){
                dist[ed.v] = min(dist[ed.v], dist[ed.u]+ed.w);
            }
        }
        bool check = false;
        for(edge ed : edges){
            if(dist[ed.v] > dist[ed.u]+ed.w){
                check = true;
                break;
            }
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}

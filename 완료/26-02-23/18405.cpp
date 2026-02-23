#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct vi{
    int x, y, k, t;
};

vector<vector<int>> ma;

int n, k, s, x, y;
vector<vector<vi>> vec;
queue<vi> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    ma = vector<vector<int>>(n+1, vector<int>(n+1));
    vec = vector<vector<vi>>(k+1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> ma[i][j];
            if(ma[i][j] != 0){
                vec[ma[i][j]].push_back({j, i, ma[i][j], 0});
                ma[i][j] = 0;
            }
        }
    }
    cin >> s >> x >> y;
    for(int i = 1; i <= k; i++){
        for(vi v : vec[i]){
            q.push(v);
        }
    }
    while(!q.empty()){
        vi v = q.front();
        q.pop();
        if(v.t > s){
            continue;
        }
        if(ma[v.y][v.x] == 0){
            ma[v.y][v.x] = v.k;
            if(v.x == y && v.y == x){
                cout << v.k;
                return 0;
            }
            if(v.y -1 > 0 && ma[v.y-1][v.x] == 0){
                q.push({v.x, v.y-1, v.k, v.t+1});
            }
            if(v.y +1 <= n && ma[v.y+1][v.x] == 0){
                q.push({v.x, v.y+1, v.k, v.t+1});
            }
            if(v.x -1 > 0 && ma[v.y][v.x-1] == 0){
                q.push({v.x-1, v.y, v.k, v.t+1});
            }
            if(v.x +1 <= n && ma[v.y][v.x+1] == 0){
                q.push({v.x+1, v.y, v.k, v.t+1});
            }
        }
    }
    cout << 0;
    return 0;
}

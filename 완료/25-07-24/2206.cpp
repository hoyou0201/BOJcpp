#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct a
{
    int pre, y, x;
    bool state;
};


int n, m;
vector<vector<bool>> wall;
vector<vector<pair<bool,bool>>> visit;
queue<a> q;
int k[] = {-1, 1, 0, 0};
bool g;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    wall = vector<vector<bool>>(n, vector<bool>(m));
    visit = vector<vector<pair<bool,bool>>>(n, vector<pair<bool,bool>>(m, {false, false}));
    g = true;
    q = queue<a>();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char t;
            cin >> t;
            if(t == '1')
                wall[i][j] = true;
            else
                wall[i][j] = false;
        }
    }
    q.push({1,0,0, false});
    while(!q.empty()){
        a yx = q.front();
        q.pop();
        if(yx.y == n-1 && yx.x == m-1){
            cout << yx.pre;
            g = false;
            break;
        }
        if(yx.state && visit[yx.y][yx.x].second) continue;
        if(!yx.state && visit[yx.y][yx.x].first) continue;

        
        if(yx.state) visit[yx.y][yx.x].second = true;
        else visit[yx.y][yx.x].first = true;
        for(int i = 0; i < 4; i++){
            int ny = yx.y + k[i];
            int nx = yx.x + k[3 - i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(wall[ny][nx]) {
                if(!yx.state) {
                    q.push({yx.pre + 1, ny, nx, true});
                }
            }
            else {
                q.push({yx.pre + 1, ny, nx, yx.state});
            }
        }
    }
    if(g) cout << -1;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct txy
{
    int t;
    int y;
    int x;
    txy(int _t, int _y, int _x) : t(_t), y(_y), x(_x) {}
};


int n, m;
vector<vector<int>> maze;
queue<txy> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    maze = vector<vector<int>>(n, vector<int>(m));
    char a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            if(a == '1') maze[i][j] = 1;
            else maze[i][j] = 0;
        }
    }

    q.emplace(1, 0, 0);
    maze[0][0] = 0;

    while(!q.empty()){
        auto [t, y, x] = q.front();
        q.pop();
        t++;
        if(y != 0 && maze[y-1][x] == 1){
            if(x == m-1 && y-1 == n-1){
                cout << t;
                return 0;
            }
            maze[y-1][x] = 0;
            q.emplace(t, y-1, x);
        }
        if(y != n-1 && maze[y+1][x] == 1){
            if(x == m-1 && y+1 == n-1){
                cout << t;
                return 0;
            }
            maze[y+1][x] = 0;
            q.emplace(t, y+1, x);
        }
        if(x != 0 && maze[y][x-1] == 1){
            if(x-1 == m-1 && y == n-1){
                cout << t;
                return 0;
            }
            maze[y][x-1] = 0;
            q.emplace(t, y, x-1);
        }
        if(x != m-1 && maze[y][x+1] == 1){
            if(x+1 == m-1 && y == n-1){
                cout << t;
                return 0;
            }
            maze[y][x+1] = 0;
            q.emplace(t, y, x+1);
        }
    }

    return 0;
}

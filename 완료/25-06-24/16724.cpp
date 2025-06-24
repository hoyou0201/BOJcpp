#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s;

vector<vector<char>> map;
vector<vector<bool>> a;
vector<vector<bool>> t;

void cycle(int y, int x){
    if(a[y][x]){
        return;
    }
    else if(t[y][x]){
        s++;
        a[y][x] = true;
        return;
    }
    else{
        t[y][x] = true;
    }
    if(map[y][x] == 'D'){
        cycle(y+1, x);
    }
    else if(map[y][x] == 'U'){
        cycle(y-1, x);
    }
    else if(map[y][x] == 'L'){
        cycle(y, x-1);
    }
    else if(map[y][x] == 'R'){
        cycle(y, x+1);
    }
    a[y][x] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    map = vector<vector<char>>(n, vector<char>(m));
    a = vector<vector<bool>>(n, vector<bool>(m, false));
    t = vector<vector<bool>>(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!a[i][j]){
                cycle(i, j);
            }
        }
    }
    cout << s;
    return 0;
}

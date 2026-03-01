#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c;
vector<vector<int>> al;

int dfs(int mask, int y, int x){
    int mx = 0;
    if(y > 0 && !(mask & al[y-1][x])) mx = max(mx, dfs(mask|al[y-1][x], y-1, x));
    if(x > 0 && !(mask & al[y][x-1])) mx = max(mx, dfs(mask|al[y][x-1], y, x-1));
    if(y < r-1 && !(mask & al[y+1][x])) mx = max(mx, dfs(mask|al[y+1][x], y+1, x));
    if(x < c-1 && !(mask & al[y][x+1])) mx = max(mx, dfs(mask|al[y][x+1], y, x+1));
    return mx+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;

    al = vector<vector<int>>(r, vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char t;
            cin >> t;
            al[i][j] = 1<<(t-'A');
        }
    }

    cout << dfs(al[0][0], 0, 0);

    return 0;
}

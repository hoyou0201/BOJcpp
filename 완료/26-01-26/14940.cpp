#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> ma;
vector<vector<int>> di;
queue<pair<int,int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    ma = vector<vector<int>>(n, vector<int>(m, -1));
    di = vector<vector<int>>(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ma[i][j];
            if(ma[i][j] == 0){
                di[i][j] = 0;
            }
            else if(ma[i][j] == 2){
                q.emplace(i, j);
                di[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        if(i != 0 && ma[i-1][j] != 0 && di[i-1][j] == -1){
            di[i-1][j] = di[i][j]+1;
            q.emplace(i-1, j);
        }
        if(i != n-1 && ma[i+1][j] != 0 && di[i+1][j] == -1){
            di[i+1][j] = di[i][j]+1;
            q.emplace(i+1, j);
        }
        if(j != 0 && ma[i][j-1] != 0 && di[i][j-1] == -1){
            di[i][j-1] = di[i][j]+1;
            q.emplace(i, j-1);
        }
        if(j != m-1 && ma[i][j+1] != 0 && di[i][j+1] == -1){
            di[i][j+1] = di[i][j]+1;
            q.emplace(i, j+1);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << di[i][j] << ' ';
        }
        cout << '\n';
    }
    

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

int n, m;
vector<vector<int>> ma;
queue<pair<int,int>> q;
unordered_map<int, int> c;

void bfs(int k, int y, int x){
    q = queue<pair<int,int>>();
    q.push({y,x});
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        if(ma[node.first][node.second] != 0){
            continue;
        }
        ma[node.first][node.second] = k;
        c[k]++;
        if(node.first != 0){
            q.push({node.first-1, node.second});
        }
        if(node.first != n-1){
            q.push({node.first+1, node.second});
        }
        if(node.second != 0){
            q.push({node.first, node.second-1});
        }
        if(node.second != m-1){
            q.push({node.first, node.second+1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    ma = vector<vector<int>>(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char chr;
            cin >> chr;
            ma[i][j] = chr-'0';
        }
    }

    for(int i = 0, k = 2; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ma[i][j] == 0){
                bfs(k++, i, j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ma[i][j] == 1){
                int r = 1;
                set<int> a = set<int>();
                if(i != 0){
                    a.insert(ma[i-1][j]);
                }
                if(i != n-1){
                    a.insert(ma[i+1][j]);
                }
                if(j != 0){
                    a.insert(ma[i][j-1]);
                }
                if(j != m-1){
                    a.insert(ma[i][j+1]);
                }
                for(int h : a){
                    r += c[h];
                }
                cout << r%10;
            }
            else{
                cout << 0;
            }
        }
        cout << "\n";
    }
    return 0;
}

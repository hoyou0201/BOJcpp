#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int,int>> q;

vector<vector<char>> map;

int n, m, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    c = 0;
    
    map = vector<vector<char>>(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'I'){
                q.push({i,j});
                map[i][j] = 'X';
            }
        }
    }

    while(!q.empty()){
        pair<int,int> t = q.front();
        int i = t.first;
        int j = t.second;
        q.pop();

        if(i+1 < n && map[i+1][j] != 'X'){
            if(map[i+1][j] == 'P') c++;
            q.push({i+1,j});
            map[i+1][j] = 'X';
        }
        if(i-1 >= 0 && map[i-1][j] != 'X'){
            if(map[i-1][j] == 'P') c++;
            q.push({i-1,j});
            map[i-1][j] = 'X';
        }
        if(j+1 < m && map[i][j+1] != 'X'){
            if(map[i][j+1] == 'P') c++;
            q.push({i,j+1});
            map[i][j+1] = 'X';
        }
        if(j-1 >= 0 && map[i][j-1] != 'X'){
            if(map[i][j-1] == 'P') c++;
            q.push({i,j-1});
            map[i][j-1] = 'X';
        }

    }
    if(c == 0){
        cout << "TT";
    }
    else{
        cout << c;
    }

    return 0;
}

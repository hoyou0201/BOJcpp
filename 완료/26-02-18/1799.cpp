#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<pair<int,int>>> black_ru;
vector<bool> black_rd;
vector<vector<pair<int,int>>> white_ru;
vector<bool> white_rd;
vector<bool> u,d;

int ru(int i, int j){
    return i+j;
}
int rd(int i, int j){
    return j-i+n-1;
}

int black_dfs(int idx){
    int cnt = 0;
    if(idx >= n*2-1) return 0;
    for(auto [i, j] : black_ru[idx]){
        if(!black_rd[rd(i,j)]){
            black_rd[rd(i,j)] = true;
            cnt = max(black_dfs(idx+2)+1, cnt);
            black_rd[rd(i,j)] = false;
        }
    }
    return max(cnt, black_dfs(idx+2));
}

int white_dfs(int idx){
    int cnt = 0;
    if(idx >= n*2-1) return 0;
    for(auto [i, j] : white_ru[idx]){
        if(!white_rd[rd(i,j)]){
            white_rd[rd(i,j)] = true;
            cnt = max(white_dfs(idx+2)+1, cnt);
            white_rd[rd(i,j)] = false;
        }
    }
    return max(cnt, white_dfs(idx+2));
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    black_ru = vector<vector<pair<int,int>>>(2*n);
    black_rd = vector<bool>(2*n);
    white_ru = vector<vector<pair<int,int>>>(2*n);
    white_rd = vector<bool>(2*n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if(a){
                if((i+j)%2 == 0) black_ru[ru(i,j)].emplace_back(i, j);
                else white_ru[ru(i,j)].emplace_back(i, j);
            }
        }
    }

    cout << black_dfs(0) + white_dfs(1);






    return 0;
}

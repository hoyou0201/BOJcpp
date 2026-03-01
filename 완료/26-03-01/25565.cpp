#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, cnt;
vector<vector<int>> tt;
vector<pair<int,int>> ga, se;
pair<int,int> f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;

    tt = vector<vector<int>>(n+1, vector<int>(m+1));
    f = {0,0};

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            cin >> tt[i][j];
            if(tt[i][j] == 1){
                if(f.first == 0){
                    f = {i,j};
                }
                cnt++;
            }
        }
    }

    if(cnt == 2*k){
        cout << 0;
        return 0;
    }
    else if(cnt == 2*k-1){
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if(tt[i][j] && (i > 1 && tt[i-1][j] || i < n && tt[i+1][j]) && (j > 1 && tt[i][j-1] || j < m && tt[i][j+1])){
                    cout << 1 << '\n' << i <<' ' << j;
                    return 0;
                }
            }
        }
    }
    int ccc = 2*k-cnt;
    int offset = k-ccc;
    if(f.first < n && tt[f.first+1][f.second]){
        cout << ccc << '\n';
        for(int i = f.first+offset; i < f.first+offset+ccc; i++){
            cout << i << ' ' << f.second << '\n';
        }
    }
    else{
        cout << ccc << '\n';
        for(int i = f.second+offset; i < f.second+offset+ccc; i++){
            cout << f.first << ' ' << i << '\n';
        }
    }

    return 0;
}

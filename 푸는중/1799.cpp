#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> map;
vector<bool> a;
vector<bool> b;


int dfs(int i, int j){
    int c = 0;
    int d = 0;
    bool tempa;
    bool tempb;
    if(map[i][j] == 1 && a[i+j] == false && b[i-j+n-1] == false){
        map[i][j] = 0;
        a[i+j] = true;
        b[i-j+n-1] = true;
        c= 1;
        if(j == n-1){
            if(i != n-1){
                c += dfs(i+1, 0);
            }
        }
        else{
            c += dfs(i,j+1);
        }
        map[i][j] = 1;
        a[i+j] = false;
        b[i-j+n-1] = false;
    }
    if(j == n-1){
        if(i != n-1){
            d = dfs(i+1, 0);
        }
        else{
            d = 0;
        }
    }
    else{
        d = dfs(i,j+1);
    }
    if(max(c,d) == n*2-2){
        cout << max(c,d);
        exit(0);
    }
    return max(c, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    map = vector<vector<int>>(n, vector<int>(n));
    b = vector<bool>(n*2+1);
    a = vector<bool>(n*2+1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    cout << dfs(0,0);



    return 0;
}

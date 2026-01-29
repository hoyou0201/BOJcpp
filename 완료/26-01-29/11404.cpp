#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, b, c;
vector<vector<int>> tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    tree = vector<vector<int>>(n+1, vector<int>(n+1, 1e9));
    for (int i = 1; i <= n; i++) {
        tree[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        tree[a][b] = min(tree[a][b], c);
    }

    for(int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                tree[i][j] = min(tree[i][j], tree[i][k]+tree[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(tree[i][j] == 1e9){
                cout << 0 << ' ';
            }
            else{
                cout << tree[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}

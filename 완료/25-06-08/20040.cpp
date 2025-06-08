#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



vector<int> parent;
int n, m;

int find(int k){
    if(parent[k] == k){
        return k;
    }
    parent[k] = find(parent[k]);
    return parent[k];
}

bool uni(int k, int j){
    k = find(k);
    j = find(j);
    if(k!=j){
        parent[k] = j;
        return false;
    }
    else{
        return true;
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    parent = vector<int>(n+1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if(uni(a, b)){
            cout << i;
            return 0;
        }
    }
    cout << 0;

    return 0;
}

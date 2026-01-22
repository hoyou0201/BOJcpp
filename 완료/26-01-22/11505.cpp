#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector<long long> arr;
vector<long long> tree;
const long long MOD = 1000000007LL;

long long build(int node, int s, int e){
    if(s == e) return tree[node] = (arr[s])%MOD;
    int m = (s+e)/2;
    return tree[node] = (build(node*2, s, m) * build(node*2+1, m+1, e))%MOD;
    
}

long long update(int node, int s, int e, int i, long long new_value){
    if(i < s || i > e) return tree[node];
    if(s == e) return tree[node] = (new_value%MOD);
    int m = (s+e)/2;
    return tree[node] = (update(node*2, s, m, i, new_value) * update(node*2+1, m+1, e, i, new_value))%MOD;

}

long long query(int node, int s, int e, int l, int r){
    if(r < s || l > e) return 1;
    if(l <= s && r >= e) return tree[node];
    int m = (s+e)/2;
    return (query(node*2, s, m, l, r) * query(node*2+1, m+1, e, l, r))%MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    arr = vector<long long>(n+10);
    tree = vector<long long>(n*4+10, 1);

    for (int i = 1; i < n+1; i++) {
        cin >> arr[i];
    }
    build(1,1,n);
    for (int i = 0; i < m+k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(1, 1, n, b, c);
        }
        else{
            cout << query(1, 1, n, b, c) << '\n';
        }
    }


    return 0;
}

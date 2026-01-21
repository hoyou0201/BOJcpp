#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long long arr[100007];
long long segmin[400020];
long long segmax[400020];

void build(int node, int s, int e){
    if(s == e){
        segmin[node] = arr[s];
        segmax[node] = arr[s];
        return;
    }
    int m = (s+e)/2;
    build(node*2, s, m);
    build(node*2+1, m+1, e);
    segmin[node] = min(segmin[node*2], segmin[node*2+1]);
    segmax[node] = max(segmax[node*2], segmax[node*2+1]);
}

long long query_max(int node, int s, int e, int l, int r){
    if(r < s || l > e) return 0;
    else if(l <= s && r >= e) return segmax[node];
    else{
        int m = (s + e) / 2;
        return max(query_max(node*2, s, m, l, r), query_max(node*2+1, m+1, e, l, r));
    }
}
long long query_min(int node, int s, int e, int l, int r){
    if(r < s || l > e) return 10e9+10;
    else if(l <= s && r >= e) return segmin[node];
    else{
        int m = (s + e) / 2;
        return min(query_min(node*2, s, m, l, r), query_min(node*2+1, m+1, e, l, r));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i < n+1; i++){
        cin >> arr[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << query_min(1, 1, n, a, b) << " " << query_max(1, 1, n, a, b) << '\n';
    }



    return 0;
}

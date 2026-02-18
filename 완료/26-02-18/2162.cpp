#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point{
    long long x, y;
};

struct line {
    point s, e;
};

int n;
vector<line> lines;
vector<int> parent;
vector<int> cnt;

int ccw(point a, point b, point c){
    long long k = (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    if(k > 0) return 1;
    else if (k < 0) return -1;
    else return 0;
}

bool in_box(point a, point b, point c){
    return (min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x)
        && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y));
}

bool is_cross(line a, line b){
    int t1 = ccw(a.s, a.e, b.s);
    int t2 = ccw(a.s, a.e, b.e);
    int t3 = ccw(b.s, b.e, a.s);
    int t4 = ccw(b.s, b.e, a.e);
    
    if(t1 == 0 && in_box(a.s, a.e, b.s)) return true;
    if(t2 == 0 && in_box(a.s, a.e, b.e)) return true;
    if(t3 == 0 && in_box(b.s, b.e, a.s)) return true;
    if(t4 == 0 && in_box(b.s, b.e, a.e)) return true;

    return (t1*t2 < 0 && t3*t4 < 0);
}

int find(int x){
    if(parent[x] == x) return x;
    else{
        return parent[x] = find(parent[x]);
    }
}

void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        parent[a] = b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    lines = vector<line>(n);
    parent = vector<int>(n);
    cnt = vector<int>(n);

    for (int i = 0; i < n; i++) {
        cin >> lines[i].s.x >> lines[i].s.y >> lines[i].e.x >> lines[i].e.y;
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if(is_cross(lines[i], lines[j])){
                unite(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cnt[find(i)]++;
    }
    int r = 0, m = 0;
    for (int i = 0; i < n; i++) {
        if(cnt[i]){
            m = max(m, cnt[i]);
            r++;
        }
    }
    cout << r << ' ' << m;

    return 0;
}

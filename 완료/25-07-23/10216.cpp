#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct circle{
    int x, y, r;
};

int n, T, s;
vector<circle> c;
vector<int> g;
int pow(int a){
    return a*a;
}

bool isis(circle c1, circle c2){
    return pow(c1.x-c2.x)+pow(c1.y-c2.y) <= pow(c1.r+c2.r);
}

int find(int i){
    if(g[i] == i){
        return i;
    }
    else{
        g[i] = find(g[i]);
        return g[i];
    }
}

void uni(int a, int b){
    int aa = find(a);
    int bb = find(b);
    if(aa != bb){
        g[aa] = bb;
        s--;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for(int _ = 0; _ < T; _++){
        cin >> n;
        c = vector<circle>(n);
        g = vector<int>(n);
        s = n;
        for(int i = 0; i < n; i++){
            g[i] = i;
            cin >> c[i].x >> c[i].y >> c[i].r;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if(isis(c[j], c[i])){
                    uni(i, j);
                }
            }
        }
        cout << s << "\n";

    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int n, p;
vector<int> g;

int find(int x){
    if(g[x] == x){
        g[x] -=1;
        return x;
    }
    g[x] = find(g[x]);
    return g[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> p;
    g = vector<int>(n+1);
    iota(g.begin(), g.end(), 0);

    for(int i = 0; i < p; i++){
        int airplane;
        cin >> airplane;
        if(find(airplane) == 0){
            cout << i;
            return 0;
        }
    }
    cout << p;



    return 0;
}

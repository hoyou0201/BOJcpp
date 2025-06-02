#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, m;
vector<int> sss;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;
    sss = vector<int>(n+1,0);
    m = n+1;

    for (int i = 1; i < n+1; i++) {
        cin >> sss[i];
        sss[i] += sss[i-1];
    }

    int l = 0;
    int r = 1;
    while(r < n+1){
        if(sss[r]-sss[l] >= s){
            m = min(m, r-l);
            l += 1;
        }
        else{
            r += 1;
        }
    }
    if(m == n+1){
        cout << 0;
    }
    else cout << m;
    return 0;
}
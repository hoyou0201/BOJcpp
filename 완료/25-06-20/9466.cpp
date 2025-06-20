#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, n, r;
vector<int> a;
vector<int> t;

void good(int k){
    if(t[k] == -1){
        return;
    }
    else{
        r -= 1;
        t[k] = -1;
        good(a[k]);
    }
}

void dp(int k, int o){
    if(t[k] == o){
        good(k);
    }
    else if(t[k] == 0){
        t[k] = o;
        dp(a[k], o);
    }
    else{
        return;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for(int _=0; _<T; _++){
        cin >> n;
        r = n;
        a = vector<int>(n+1);
        t = vector<int>(n+1, 0);
        for(int i=0; i < n; i++){
            cin >> a[i+1];
        }
        for(int i=0; i < n; i++){
            if(t[i+1] == 0)
                dp(i+1, i+1);
        }
        cout << r << '\n';


    }

    return 0;
}

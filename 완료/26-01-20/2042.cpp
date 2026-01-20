#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, a, b;
long long c;
long long ftree[1000007];
long long arr[1000007];

void add(int i, long long d){
    while(i <= n){
        ftree[i] += d;
        i += (i & -i);
    }
}

long long nujuk(int i){
    int j = i - (i&-i);
    if(i > 0){
        return nujuk(j)+ftree[i];
    }
    else{
        return ftree[i];
    }
}

void update(int i, long long newd){
    long long d = newd-arr[i];
    arr[i] = newd;
    add(i, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 1; i < n+1; i++) {
        cin >> arr[i];
        add(i, arr[i]);
    }
    for (int i = 0; i < m+k; i++) {
        cin >> a >> b >> c;
        if(a == 1){
            update(b, c);
        }
        else{
            cout << (nujuk(c) - nujuk(b-1)) << '\n';
        }
    }

    return 0;
}

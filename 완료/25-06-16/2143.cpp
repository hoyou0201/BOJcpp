#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

long long n, m, t;
vector<long long> a;
map<long long,long long> asum;
vector<long long> b;
vector<long long> bsum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    cin >> n;
    a = vector<long long>(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i != 0){
            a[i] += a[i-1];
        }
    }
    cin >> m;
    b = vector<long long>(m+1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        if(i != 0){
            b[i] += b[i-1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            asum[a[j]-a[i]] += 1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = i+1; j <= m; j++) {
            bsum.push_back(b[j]-b[i]);
        }
    }
    long long c = 0;
    for(long long i : bsum){
        c += asum[t-i];
    }
    cout << c;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long n, a;
vector<int> pow2;
priority_queue<int> hot;
const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long r = 0;
    cin >> n;
    pow2 = vector<int>(n+1);
    pow2[0] = 1;
    for(int i = 1; i < n+1; i++){
        cin >> a;
        hot.push(a);
        pow2[i] = (pow2[i-1]*2)%MOD;
    }
    for (int i = n; i > 0; i--) {
        a = hot.top();
        hot.pop();
        r += (a*pow2[i-1])%MOD;
        r -= (a*pow2[n-i])%MOD;
    }
    cout << ((r%MOD)+MOD)%MOD;

    return 0;
}

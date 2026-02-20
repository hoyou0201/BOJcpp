#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long a, b, n;
const long long MOD = 1000000007;
const long long T = (1LL<<31) % MOD;

long long powmod(long long base, long long exp){
    if (exp == 0){
        return 1;
    }
    else if(exp == 1){
        return base%MOD;
    }
    long long k = powmod(base, exp/2);
    k = (k*k)%MOD;
    if(exp%2) k = (k*base)%MOD;
    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> n;

    long long k = 1;


    cout << powmod(T, n-1);

    return 0;
}

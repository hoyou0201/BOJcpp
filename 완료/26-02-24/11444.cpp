#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;
const int MOD = 1000000007;

pair<long long,long long> fibo(long long n){
    if(n == 0) return {0,1};
    if(n == 1) return {1,1};
    auto [a, b] = fibo(n/2);
    long long c = a*(((2*b)%MOD-a+MOD)%MOD)%MOD;
    long long d = (a*a%MOD+b*b%MOD)%MOD;
    if(n%2 == 0) return {c, d};
    else return {d, c+d};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    cout << fibo(n).first%MOD;

    return 0;
}

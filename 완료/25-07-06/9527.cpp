#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long a, b;

long long countone(long long n){
    long long s = 0;
    for (long long i = 1; i <= n; i<<=1) {
        s += (n+1)/(i<<1)*i;
        s += max((n+1) % (i<<1)-i, 0ll);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;

    cout << countone(b)-countone(a-1);
    return 0;
}

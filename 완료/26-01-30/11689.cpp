#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    long long r = n;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            while(n%i == 0) n /= i;
            r -= r/i;
        }
    }
    if(n > 1){
        r -= r/n;
    }
    cout << r;

    return 0;
}

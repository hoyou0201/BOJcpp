#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    long long k = n/6;
    long long r = n%6;
    if(r == 0){
        cout << 1+3*k*(k+1);
    }
    else if(r == 1){
        cout << 1+3*k*(k+1)+k;
    }
    else{
        cout << 1+3*k*(k+1)+k+(k+1)*(r-1);
    }

    return 0;
}

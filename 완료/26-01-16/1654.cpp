#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, n;
vector<long long> lan;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k >> n;

    lan = vector<long long>(n);
    for(int i = 0; i < k; i++){
        cin >> lan[i];
    }

    long long l = 0;
    long long r = *max_element(lan.begin(), lan.end());

    while(l <= r){
        long long mid = (l+r)/2;
        long long c = 0;
        if(mid == 0) break;
        for(int i = 0; i < k; i++){
            c += lan[i]/mid;
        }
        if(c < n){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << r;
    return 0;
}

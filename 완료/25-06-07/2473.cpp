#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//범위를 long long으로 해야함
long long n, k;
vector<long long> a;
long long ans[3];

//일반 abs를 쓰면 안됨
long long labs(long long b){
    if(b < 0){
        // b*-1은 제대로 안나옴
        return -b;
    }
    else return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    a = vector<long long>(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    //최대값을 정함
    k = labs(a[0]+a[1]+a[2]);
    //최대값 기준으로 정함
    ans[0] = a[0];
    ans[1] = a[1];
    ans[2] = a[2];

    //기준은 0 ~ n-3
    for (int i = 0; i < n-2; i++) {
        //여기서부터 투포인터
        int l = i+1;
        int r = n-1;
        while(l < r){
            long long t = a[i]+a[l]+a[r];
            if(k > labs(t)){
                //0이면 바로 출력(굳이 안해도 됨)
                if(t == 0){
                    cout << a[i] << " " << a[l] << " " << a[r];
                    return 0;
                }
                ans[0] = a[i];
                ans[1] = a[l];
                ans[2] = a[r];
                k = labs(t);
            }
            if(t > 0){
                r--;
            }
            else{
                l++;
            }

        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2];

    return 0;
}
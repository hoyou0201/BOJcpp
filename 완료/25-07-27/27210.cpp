#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, smin, smax;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        if(t==2){
            s++;
        }
        else{
            s--;
        }
        smin = min(s, smin);
        smax = max(s, smax);
    }
    cout << smax - smin; 


    return 0;
}

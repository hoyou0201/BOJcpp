#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool a[4000009];
vector<int> u;
int start, result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    start = 0;

    for (int i = 2; i <= n; i++) {
        if(a[i]){
            continue;
        }
        for (int j = i*2; j <= n; j+=i) {
            a[j] = true;
        }
        u.push_back(i);
        int s = 0;
        do{
            s = 0;
            for (int j = start; j < u.size(); j++) {
                s+=u[j];
            }
            if(s == n){
                result += 1;
            }
            if(s >= n){
                start += 1;
            }
        }while(s >= n);
    }
    cout << result;
    return 0;
}

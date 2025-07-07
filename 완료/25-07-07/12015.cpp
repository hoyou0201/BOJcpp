#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        auto it = lower_bound(a.begin(), a.end(), t);
        if(it == a.end()){
            a.push_back(t);
        }
        else{
            *it = t;
        }
    }
    cout << a.size();
    return 0;
}

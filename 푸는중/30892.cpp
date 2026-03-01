#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, k, t;

vector<long long> stk;
vector<long long> food;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k >> t;

    food = vector<long long>(n);

    for (int i = 0; i < n; i++) {
        cin >> food[i];
    }

    sort(food.begin(), food.end());

    int idx = 0;
    for (int i = 0; i < k; i++) {
        while(idx < n && food[idx] < t){
            stk.push_back(food[idx++]);
        }
        if(stk.empty()){
            cout << t;
            return 0;
        }
        t += stk.back();
        stk.pop_back();
    }
    cout << t;

    return 0;
}

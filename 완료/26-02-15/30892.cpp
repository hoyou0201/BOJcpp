#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long n, k, t;
vector<long long> a;
priority_queue<long long> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k >> t;
    a = vector<long long>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int idx = 0;
    for (int i = 0; i < k; i++) {
        while(idx < n && a[idx] < t){
            q.push(a[idx++]);
        }
        if(q.empty()) break;
        t += q.top();
        q.pop();
    }

    cout << t;



    return 0;
}

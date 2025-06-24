#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int n, k;
long long rr;
priority_queue<pair<int,int>> ju;
multiset<int> bag;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    ju = priority_queue<pair<int,int>>();
    bag = multiset<int>();

    for (int i = 0; i < n; i++) {
        pair<int,int> ttt;
        cin >> ttt.second >> ttt.first;
        ju.push(ttt);
    }
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        bag.insert(t);
    }

    while(!ju.empty()){
        pair<int,int> juu = ju.top();
        ju.pop();

        auto mid = bag.lower_bound(juu.second);
        if(mid == bag.end()){
            continue;
        }
        else{
            rr+=juu.first;
            bag.erase(mid);
        }
    }
    cout << rr;
    return 0;
}

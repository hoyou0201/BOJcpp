#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int n, m, t;
vector<int> a;
queue<int> q;
stack<int> b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    a = vector<int>(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> t;
        if(a[i] == 0){
            b.push(t);
        }
    }
    while(!b.empty()){
        q.push(b.top());
        b.pop();
    }
    cin >> m;
    
    for(int i = 0; i < m; i++){
        cin >> t;
        q.push(t);
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}

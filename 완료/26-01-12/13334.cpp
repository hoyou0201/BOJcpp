#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
using namespace std;


int n, h, o, d, result;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> lines;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h >> o;
        if(h > o) lines.push({h, o});
        else lines.push({o, h});
    }

    cin >> d;

    while(!lines.empty()){
        pair<int, int> a = lines.top();
        lines.pop();
        if(a.first - a.second > d) continue;
        q.push(a.second);
        while(!q.empty() && q.top() < a.first-d){
            q.pop();
        }
        result = max((int)q.size(), result);
    }
    cout << result;



    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
using namespace std;


int n, h, o, d, result;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> lines;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h >> o;
        if(h > o) lines.push({o, h});
        else lines.push({h, o});
    }

    cin >> d;

    while(!lines.empty()){
        pair<int, int> a = lines.top();
        lines.pop();
        if(a.second - a.first > d) continue;
        int m = 1;
        stack<pair<int,int>> temp;      
        while(!lines.empty() && lines.top().first <= a.first+d){
            if(lines.top().second <= a.first+d){
                m++;
            }
            temp.push(lines.top());
            lines.pop();
        }
        result = max(result, m);
        while(!temp.empty()){
            lines.push(temp.top());
            temp.pop();
        }
    }
    cout << result;



    return 0;
}

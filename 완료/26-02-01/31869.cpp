#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int n;
unordered_map<string, pair<int,int>> jigab;
priority_queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int w, d, p;
        cin >> s >> w >> d >> p;
        jigab[s] = {w*7+d, p};
    }
    for (int i = 0; i < n; i++) {
        string s;
        int m;
        cin >> s >> m;
        if(jigab[s].second <= m){
            q.push(jigab[s].first);
        }
    }
    int max_r = 0;
    int r = 0;
    int tt = -1;
    while(!q.empty()){
        int day = q.top();
        q.pop();
        if(tt -1 == day){
            r++;
        }
        else if(tt == day){
            
        }
        else{
            max_r = max(r, max_r);
            r = 1;
        }
        tt = day;
    }
    cout << max(max_r, r);
    return 0;
}

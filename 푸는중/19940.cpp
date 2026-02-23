#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T, n;

vector<int> timer;
vector<vector<int>> best;
vector<bool> visit;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    queue<pair<int,vector<int>>> q;
    best = vector<vector<int>>(61);
    visit = vector<bool>(61);

    q.emplace(1, 0,0,0,1,0);
    q.emplace(10, 0,1,0,0,0);
    q.emplace(60, 1,0,0,0,0);

    while(!q.empty()){
        auto [a, v] = q.front();
        if(!visit[a]){
            visit[a] = true;
            best[a] = v;
            if(a-1 > 0){
                v[4]+1;
                q.emplace(a-1, v);
                v[4]-1;
            }
            if(a+1 < 61){
                v[3]+1;
                q.emplace(a-1, v);
                v[3]-1;
            }
            if(a-10 > 0){
                v[2]+1;
                q.emplace(a-10, v);
                v[2]-1;
            }
            if(a+10 < 61){
                v[1]+1;
                q.emplace(a+10, v);
                v[1]-1;
            }
        }
    }



    for(int _ = 0; _ < T; _++){
        cin >> n;

        timer = vector<int>(5, 0);

        timer[0] = n / 60;
        n %= 60;



    }

    return 0;
}

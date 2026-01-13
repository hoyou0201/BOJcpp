#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, uuu;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
vector<vector<int>> dist;
vector<int> selected;

void dfs(int index, int x){
    if(x == m){
        int s = 0;
        for (int i = 0; i < house.size(); i++) {
            int mimi = 1000000;
            for (int j : selected) {
                mimi = min(mimi, dist[j][i]);
            }
            s += mimi;
        }
        uuu = min(uuu, s);
    }
    else{
        for (int i = index+1; i < chicken.size(); i++) {
            selected.push_back(i);
            dfs(i, x+1);
            selected.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a;
            if(a == 2){
                chicken.emplace_back(i, j);
            }
            else if(a == 1){
                house.emplace_back(i, j);
            }
        }
    }
    dist = vector<vector<int>>(chicken.size(), vector<int>(house.size()));
    for (int i = 0; i < chicken.size(); i++) {
        for (int j = 0; j < house.size(); j++) {
            dist[i][j] = abs(chicken[i].first-house[j].first) + abs(chicken[i].second-house[j].second);
        }
    }

    uuu = 1000000;
    dfs(-1,0);

    cout << uuu;


    return 0;
}

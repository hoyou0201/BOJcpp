#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m, k;
vector<int> candys;
vector<int> friends;
unordered_map<int, int> cf;
vector<pair<int,int>> candycandy;
vector<vector<int>> dp;
int mc;

int find(int a){
    if(friends[a] == a){
        return a;
    }
    else{
        friends[a] = find(friends[a]);
        return friends[a];
    }
}

void add(int a, int b){
    int aa = find(a);
    int bb = find(b);
    if(aa != bb){
        friends[aa] = bb;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    candys = vector<int>(n);
    candycandy = vector<pair<int,int>>();
    friends = vector<int>(n+1);
    cf = unordered_map<int, int>();
    for (int i = 0; i < n; i++) {
        cin >> candys[i];
        friends[i+1] = i+1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for (int i = 0; i < n; i++) {
        if(cf.find(find(i+1)) != cf.end()){
            candycandy[cf[find(i+1)]].first += 1;
            candycandy[cf[find(i+1)]].second += candys[i];
        }
        else{
            cf[find(i+1)] = candycandy.size();
            candycandy.push_back({1, candys[i]}); 
        }
    }
    dp = vector<vector<int>>(candycandy.size()+1, vector<int>(k, 0));
    for (int i = 1; i < candycandy.size()+1; i++) {
        for (int j = 0; j < k; j++) {
            if(j >= candycandy[i-1].first)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-candycandy[i-1].first]+candycandy[i-1].second);
            else{
                dp[i][j] = dp[i-1][j];
            }
            mc = max(mc, dp[i][j]);
        }
    }
    cout << mc;
    return 0;
}

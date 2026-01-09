#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

vector<string> num;


struct Cmp{
    bool operator()(int a, int b) const {
        return num[a] < num[b];
    }
};


vector<unordered_map<int, set<int, Cmp>>> g;
unordered_map<int, unordered_map<string, int>> name;

int n, m, t, tt, na;
string s;

void dfs(int d, int k){
    if(g.size() <= d || g[d].count(k) == 0){
        return;
    }
    for (int i : g[d][k]) {
        for (int j = 0; j < d; j++) {
            cout << "--";
        }
        cout << num[i] << '\n';
        dfs(d+1, i);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    
    name = unordered_map<int, unordered_map<string, int>>();
    num = vector<string>();
    for (int i = 0; i < n; i++) {
        cin >> m;
        tt = -1;
        for (int j = 0; j < m; j++) {
            if(g.size() == j){
                g.push_back(unordered_map<int, set<int, Cmp>>());
            }
            cin >> s;
            if(name[tt].count(s)){
                tt = name[tt][s];
            }
            else{
                name[tt][s] = num.size();
                num.push_back(s);
                g[j][tt].insert(name[tt][s]);
                tt = name[tt][s];
            }
        }
    }

    dfs(0, -1);

    return 0;
}

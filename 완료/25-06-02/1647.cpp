#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e, a, b, c;
vector<pair<int, pair<int, int>>> edges;
vector<int> parent;

int find(int k){
    if(parent[k] == k){
        return k;
    }
    parent[k] = find(parent[k]);
    return parent[k];
}

bool uni(int k, int j){
    k = find(k);
    j = find(j);
    if(k!=j){
        parent[k] = j;
        return true;
    }
    else{
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    edges = vector<pair<int, pair<int, int>>>();

    int s = 0;

    cin >> v >> e;
    parent = vector<int>(v+1);
    for (int i = 1; i < v+1; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        edges.push_back({c,{a,b}});
    }

    sort(edges.begin(), edges.end());

    int i = 0;
    for (int j = 0; j < v-2; j++) {
        while(true){
            a = edges[i].second.first;
            b = edges[i].second.second;
            c = edges[i].first;

            i++;
            if(uni(a,b)){
                s += c;
                break;
            }
            else{
                continue;
            }
        }
    }
    cout << s;
    return 0;
}
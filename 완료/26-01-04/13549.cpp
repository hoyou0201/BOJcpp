#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int n, k;
queue<vector<int>> q = queue<vector<int>>();
vector<bool> v = vector<bool>(100001);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    int t = 0;
    q.push({n});
    while(!q.empty()){
        vector<int> ve = q.front();
        stack<int> ne = stack<int>();
        vector<int> nne = vector<int>();
        q.pop();
        for(int i : ve){
            int p = i;
            v[p] = true;
            if(p == k){
                cout << t;
                return 0;
            }
            ne.push(p);
            p*= 2;
            while(p < 100001){
                if(v[p]){
                    break;
                }
                v[p] = true;
                if(p == k){
                    cout << t;
                    return 0;
                }
                ne.push(p);
                p*=2;
            }
        }
        while(!ne.empty()){
            int i = ne.top();
            ne.pop();
            if(i+1 < 100001 && !v[i+1]){
                nne.push_back(i+1);
                v[i+1]=true;
            }
            if(i-1 >= 0 && !v[i-1]){
                nne.push_back(i-1);
                v[i-1]=true;
            }
        }
        if(!nne.empty()) q.push(nne);
        t += 1;

    }

    

    return 0;
}

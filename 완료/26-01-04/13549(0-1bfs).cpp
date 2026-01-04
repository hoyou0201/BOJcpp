#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n, k;
deque<int> q = deque<int>();
vector<int> d = vector<int>(100001, 200000);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    if(n == k){
        cout << 0;
        return 0;
    }
    q.push_back(n);
    d[n] = 0;
    while(!q.empty()){
        int i = q.front();
        q.pop_front();

        if(i*2 < 100001 && d[i*2] > d[i]){
            d[i*2] = d[i];
            if(i*2==k){
                cout << d[i*2];
                return 0;
            }
            q.push_front(i*2);
        }
        if(i-1 >= 0 && d[i-1] > d[i]){
            d[i-1] = d[i]+1;
            if(i-1==k){
                cout << d[i-1];
                return 0;
            }
            q.push_back(i-1);
        }

        if(i+1 < 100001 && d[i+1] > d[i]){
            d[i+1] = d[i]+1;
            if(i+1==k){
                cout << d[i+1];
                return 0;
            }
            q.push_back(i+1);
        }
        
    }
    
    return 0;
}

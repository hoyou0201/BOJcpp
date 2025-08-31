#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int r1, c1, r2, c2;
vector<vector<int>> mmm;
int mj;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r1 >> c1 >> r2 >> c2;
    mmm = vector<vector<int>>();
    mj = 0;

    int ii = 0;
    for(int i = r1; i <= r2; i++){
        mmm.push_back(vector<int>());
        for(int j = c1; j <= c2; j++){
            int k = max(abs(i), abs(j));
            int g = (2*k+1)*(2*k+1);
            int t;
            if(i == k){
                t = g-k+j;
            }
            else if(j == -k){
                t = g-3*k+i;
            }
            else if(i == -k){
                t = g-5*k-j;
            }
            else{
                t = g-7*k-i;
            }
            mj = max(mj, (int)to_string(t).size());
            mmm[ii].push_back(t);
        }
        ii++;
    }

    for(auto i : mmm){
        for(int j : i){
            int s = to_string(j).size();
            for(int k = s; k < mj; k++){
                cout << ' ';
            }
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}

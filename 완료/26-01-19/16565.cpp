#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    c.push_back({1});
    for (int i = 1; i < 52; i++) {
        c.push_back(vector<int>(i+1));
        for (int j = 0; j < i+1; j++) {
            if(j == 0 || j == i){
                c[i][j] = 1;
            }
            else{
                c[i][j] = (c[i-1][j-1]+c[i-1][j])%10007;
            }
        }
    }

    int k = 1;
    int r = 0;
    while(k*4 <= n){
        int g = c[13][k];
        int t = c[52-k*4][n-k*4];
        if(k%2 == 1){
            r += (g*t)%10007;
        }
        else{
            r -= (g*t)%10007;
            r = (r+10007)%10007;
        }
        k++;
    }
    cout << (r+10007)%10007;

    return 0;
}

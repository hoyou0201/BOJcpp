#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000000
using namespace std;

int n;
vector<vector<int>> num;
vector<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    num = vector<vector<int>>(n+1, vector<int>(10, 0));
    s = vector<int>(n+1);
    num[1] = {0,1,1,1,1,1,1,1,1,1};
    s[1] = 9;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 10; j++){
            num[i][j] = 0;
            if(j-1 >= 0){
                num[i][j] = (num[i][j] + num[i-1][j-1]) % MOD;
            }
            if(j+1 < 10){
                num[i][j] = (num[i][j] + num[i-1][j+1]) % MOD;
            }
            s[i] = (s[i] + num[i][j]) % MOD;
        }

    }
    cout << s[n];
    return 0;
}

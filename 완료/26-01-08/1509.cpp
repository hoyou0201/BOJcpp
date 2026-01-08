#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;

int dp[2501][2501];
int dpdp[2501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    for(int l = 1; l <= s.length(); l++){
        for (int i = 1; i <= s.length(); i++) {
            if(i+l-2 >= s.length()) break;
            if(l == 1){
                dp[i][i] = true;
            }
            else if(l == 2){
                if(s[i-1] == s[i]) dp[i][i+1] = true;
            }
            else{
                if(s[i-1] == s[i+l-2] && dp[i+1][i+l-2]) dp[i][i+l-1] = true;
            }
        }
    }

    dpdp[0]= 0;
    dpdp[1]= 1;
    for (int i = 2; i <= s.length(); i++) {
        dpdp[i] = 10000;
        for (int j = 0; j < i; j++) {
            if(dp[j+1][i]) dpdp[i] = min(dpdp[i], dpdp[j]+1);
        }
    }
    
    cout << dpdp[s.length()];


    return 0;
}

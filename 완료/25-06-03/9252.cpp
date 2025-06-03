#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s1, s2;
vector<vector<int>> dp;
vector<char> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s1 >> s2;
    dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, 0));

    for (int i = 1; i < s1.size()+1; i++) {
        for (int j = 1; j < s2.size()+1; j++) {
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = s1.size();
    int j = s2.size();
    while(i!= 0 && j != 0){
        if(s1[i-1] == s2[j-1]){
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    if(s.size() == 0){
        cout << 0;
        return 0;
    }
    else{
        cout << s.size() << '\n';
        for (int i = s.size()-1; i >= 0; i--) {
            cout << s[i];
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
#define MAX 100009
using namespace std;

vector<int> a;
int dp[MAX][5][5];

int comp(int b, int c){
    if(b == 0){
        return 2;
    }
    else if(abs(b-c) == 1){
        return 3;
    }
    else if(b==c){
        return 1;
    }
    else{
        return 4;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    a = vector<int>();

    while(true){
        cin >> t;
        if(t == 0){
            break;
        }
        else{
            a.push_back(t);
        }
    }

    for (int i = 0; i < a.size()+3; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if(dp[i][j][k] == INF){
                    continue;
                }
                int next = a[i];
                dp[i+1][next][k] = min(dp[i+1][next][k], dp[i][j][k]+comp(j,next));
                dp[i+1][j][next] = min(dp[i+1][j][next], dp[i][j][k]+comp(k,next));
            }
        }
    }

    int m = INF;
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
            m = min(m,dp[a.size()][j][k]);
        }
    }
    cout << m;
    
    return 0;
}

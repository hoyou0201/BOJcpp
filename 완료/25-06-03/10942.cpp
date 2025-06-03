#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> a;
bool dp[2005][2005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    for (int i = 0; i < n-1; i++) {
        if(a[i] == a[i+1]){
            dp[i][i+1] = true;
        }
    }
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            int end = j + i - 1;
            if (a[j] == a[end] && dp[j + 1][end - 1]) {
                dp[j][end] = true;
            }
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k, l;
        cin >> k >> l;
        cout << dp[k-1][l-1] << '\n';
    }

    return 0;
}
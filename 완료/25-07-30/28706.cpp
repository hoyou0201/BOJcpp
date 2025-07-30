#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for(int _ = 0; _ < T; _++){
        cin >> n;
        int v1, v2;
        char op1, op2;
        vector<vector<bool>> a(n+1, vector<bool>(7, false));
        a[0][1] = true;
        for(int i = 1; i <= n; i++){
            cin >> op1 >> v1 >> op2 >> v2;
            for(int j = 0; j < 7; j++){
                if(!a[i-1][j]){
                    continue;
                }
                if(op1 == '+'){
                    a[i][(j+v1)%7] = true;
                }
                else{
                    a[i][(j*v1)%7] = true;
                }
                if(op2 == '+'){
                    a[i][(j+v2)%7] = true;
                }
                else{
                    a[i][(j*v2)%7] = true;
                }
            }
        }
        if(a[n][0]){
            cout << "LUCKY\n";
        }
        else{
            cout << "UNLUCKY\n";
        }
    }

    return 0;
}

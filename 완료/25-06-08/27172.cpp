#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> card;
bool a[1000009];
int point[1000009];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    card = vector<int>(n);

    for(int i = 0; i < n; i++){
        cin >> card[i];
        a[card[i]] = true;
    }


    for (int i = 0; i < n; i++) {
        int t = card[i];
        for (int j = t*2; j < 1000009; j+=t) {
            if(a[j]){
                point[t] += 1;
                point[j] -= 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << point[card[i]] << ' ';
    }

    return 0;
}

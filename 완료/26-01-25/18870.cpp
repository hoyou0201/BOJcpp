#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a;
vector<int> b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    a = vector<int>(n);
    b = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; i++) {
        cout << lower_bound(b.begin(), b.end(), a[i])-b.begin() << ' ';
    }

    return 0;
}

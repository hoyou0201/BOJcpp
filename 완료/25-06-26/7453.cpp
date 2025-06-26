#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, r;
vector<long long> a;
vector<long long> b;
vector<long long> c;
vector<long long> d;
vector<long long> ab;
vector<long long> cd;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    a = vector<long long>(n);
    b = vector<long long>(n);
    c = vector<long long>(n);
    d = vector<long long>(n);
    ab = vector<long long>();
    cd = vector<long long>();

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(a[i]+b[j]);
            cd.push_back(-c[i]-d[j]);
        }
    }
    sort(cd.begin(), cd.end());
    r = 0;
    for (int i = 0; i < ab.size(); i++) {
        r += upper_bound(cd.begin(), cd.end(), ab[i]) - lower_bound(cd.begin(), cd.end(), ab[i]);
    }

    cout << r;
    return 0;
}

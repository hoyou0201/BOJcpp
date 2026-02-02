#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int x, y, t, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> x >> y >> d >> t;

    double dist = sqrt(1.0*x*x+1.0*y*y);

    if((1.0*d)/t < 1){
        cout << fixed << setprecision(15) << dist;
    }

    int k = dist/d;

    double ans = t*k + fmod(dist, d);
    if(k == 0){
        ans = min(ans, 1.0*t+d-fmod(dist, d));
        ans = min(ans, 2.0*t);
    }
    else ans = min(ans, 1.0*t*(k+1));
    
    cout << fixed << setprecision(15) << ans;

    return 0;
}

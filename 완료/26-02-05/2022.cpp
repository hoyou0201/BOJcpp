#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

double x, y, c, w, wl, wr, mid, h1, h2, cc;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> x >> y >> c;

    wl = 0;
    wr = min(x, y);

    for(int _=0; _<100; _++){
        mid = (wl+wr)/2.0;
        h1 = sqrt(x*x-mid*mid);
        h2 = sqrt(y*y-mid*mid);
        cc = h1*h2/(h1+h2);
        if(cc < c){
            wr = mid;
        }
        else{
            wl = mid;
        }
    }

    cout << fixed << setprecision(3) << (wr+wl)/2.0;

    return 0;
}

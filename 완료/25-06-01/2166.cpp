#include <iostream>
#include <vector>
using namespace std;


long long s;
int n;
long long x, y, xx, yy, tx, ty;

int main(){
    cin >> n;
    cin >> x >> y;
    tx = x;
    ty = y;
    for(int i = 1; i < n; i++){
        cin >> xx >> yy;
        s += x*yy - xx*y;
        x = xx; 
        y = yy;

    }
    s += x*ty - y*tx;
    if(s < 0) s *=-1;
    double t = s/2.0;
    cout << fixed;
    cout.precision(1);
    cout << t;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct circle{
    double x, y, r;
};

const double eps = 1e-10;
const double PI = acos(-1);

circle a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a.x >> a.y >> a.r;
    cin >> b.x >> b.y >> b.r;

    double d = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

    if(d >= a.r+b.r-eps){
        cout << fixed << setprecision(3) << 0.0;
    }
    else if (d <= fabs(a.r-b.r)+eps){
        circle k = a;
        if(a.r > b.r) k = b;
        double x = k.r*k.r*PI;
        cout << fixed << setprecision(3) << x;
    }
    else{
        double ar = acos(((a.r*a.r)+(d*d)-(b.r*b.r))/(2*a.r*d));
        double br = acos(((b.r*b.r)+(d*d)-(a.r*a.r))/(2*b.r*d));

        double x = a.r*a.r*ar+b.r*b.r*br-0.5*sqrt((a.r+b.r+d)*(a.r-b.r+d)*(a.r+b.r-d)*(b.r+d-a.r));

        cout << fixed << setprecision(3) << x;
    }

    return 0;
}

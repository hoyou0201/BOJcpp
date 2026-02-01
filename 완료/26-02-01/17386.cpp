#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
    long long x;
    long long y;
};

Point a, b, c, d;

int ccw(Point a, Point b, Point c){
    long long k = (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    if(k < 0) return -1;
    else return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    if(ccw(a,b,c)*ccw(a,b,d) == -1 && ccw(c,d,a)*ccw(c,d,b) == -1){
        cout << 1;
    }
    else{
        cout << 0;
    }

    return 0;
}

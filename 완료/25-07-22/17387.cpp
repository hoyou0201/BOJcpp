#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

int ccw(Point a, Point b, Point c) {
    long long val = 1LL * (b.x - a.x) * (c.y - a.y) 
                  - 1LL * (b.y - a.y) * (c.x - a.x);
    if (val > 0) return 1;     // 반시계 방향
    if (val < 0) return -1;    // 시계 방향
    return 0;                  // 일직선
}

bool isCross(Point a, Point b, Point c, Point d) {
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);

    if (ab == 0 && cd == 0) {
        // 두 선분이 일직선상에 있을 때는 범위 겹침 여부로 판단
        if (a.x > b.x) swap(a, b);
        if (c.x > d.x) swap(c, d);
        return !(b.x < c.x || d.x < a.x || max(a.y, b.y) < min(c.y, d.y) || max(c.y, d.y) < min(a.y, b.y));
    }

    return ab <= 0 && cd <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y;
    cin >> C.x >> C.y >> D.x >> D.y;

    cout << (isCross(A, B, C, D) ? 1 : 0);
    return 0;
}

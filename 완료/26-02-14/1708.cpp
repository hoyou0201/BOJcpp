#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct Point {
    long long x, y;

    bool operator<(const Point& other) const{
        if(other.x == x) return y < other.y;
        else return x < other.x;
    }
};

int n;
vector<Point> points;
vector<Point> down;
vector<Point> up;

bool ccw(Point a, Point b, Point c){
    long long t = (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
    if(t <= 0) return false;
    else return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    points = vector<Point>(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end());
    down.push_back(points[0]);
    down.push_back(points[1]);
    for(int i = 2; i < n; i++){
        while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], points[i])){
            down.pop_back();
            if(down.size() == 1){
                break;
            }
        }
        down.push_back(points[i]);
    }
    up.push_back(points[n-1]);
    up.push_back(points[n-2]);
    for(int i = n-3; i >= 0; i--){
        while(up.size() >= 2 && !ccw(up[up.size()-2], up[up.size()-1], points[i])){
            up.pop_back();
        }
        up.push_back(points[i]);
    }

    cout << down.size()+up.size()-2;

    return 0;
}

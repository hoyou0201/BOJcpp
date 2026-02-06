#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct rect{
    int x, y, p, q;
};

int a, b, c, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int _=0; _<4; _++){
        cin >> a >> b >> c >> d;
        rect r1 {a, b, c, d};
        cin >> a >> b >> c >> d;
        rect r2 {a, b, c, d};
        if(r1.p < r2.x || r1.q < r2.y || r2.p < r1.x || r2.q < r1.y){
            cout << 'd' << '\n';
        }
        else if(r1.p == r2.x && (r1.q == r2.y || r2.q == r1.y) || r2.p == r1.x && (r1.q == r2.y || r2.q == r1.y)){
            cout << 'c' << '\n';
        }
        else if(r1.p == r2.x || r1.q == r2.y || r2.p == r1.x || r2.q == r1.y){
            cout << 'b' << '\n';
        }
        else{
            cout << 'a' << '\n';
        }

    }


    return 0;
}

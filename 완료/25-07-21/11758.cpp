#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct p{
    int x, y;
};

p l(p p1, p p2){
    return {p2.x-p1.x, p2.y-p1.y};
}

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    p p1, p2, p3;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;

    p l1 = l(p1, p3);
    if(l1.y == 0){
        if(l1.x > 0){
            if(p2.y > p1.y){
                cout << 1;
            }
            else if(p2.y < p1.y){
                cout << -1;
            }
            else{
                cout << 0;
            }
        }
        else{
            if(p2.y > p1.y){
                cout << -1;
            }
            else if(p2.y < p1.y){
                cout << 1;
            }
            else{
                cout << 0;
            }
        }
        return 0;
    }
    int x = (p2.y-p1.y)*l1.x/l1.y+p1.x;
    if(l1.y > 0){
        if(x < p2.x){
            cout << 1;
        }
        else if(x > p2.x){
            cout << -1;
        }
        else{
            cout << 0;
        }
    }
    else{
        if(x < p2.x){
            cout << -1;
        }
        else if(x > p2.x){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }

    return 0;
}

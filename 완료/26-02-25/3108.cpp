#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct sq{
    int x1, y1, x2, y2;
};

int n;

vector<sq> sqs;
vector<int> parent;

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void uni(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        parent[a] = b;
    }
}

bool is_cross(sq a, sq b){
    bool inax = false;
    bool inay = false;
    if(a.x2 < b.x1 || a.y2 < b.y1 || b.x2 < a.x1 || b.y2 < a.y1) return false;
    if(a.x1 > b.x1 && a.x2 < b.x2 && a.y1 > b.y1 && a.y2 < b.y2) return false;
    if(b.x1 > a.x1 && b.x2 < a.x2 && b.y1 > a.y1 && b.y2 < a.y2) return false;
    return true;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    sqs = vector<sq>(n+1);
    sqs[0] = {0,0,0,0};
    parent = vector<int>(n+1);

    for(int i = 1; i < n+1; i++){
        cin >> sqs[i].x1 >> sqs[i].y1 >> sqs[i].x2 >> sqs[i].y2;
        if(sqs[i].x1 > sqs[i].x2) swap(sqs[i].x1, sqs[i].x2);
        if(sqs[i].y1 > sqs[i].y2) swap(sqs[i].y1, sqs[i].y2);
        parent[i] = i;
    }

    for (int i = 0; i < n+1; i++) {
        for (int j = i+1; j < n+1; j++) {
            if(is_cross(sqs[i], sqs[j])){
                uni(i, j);
            }
        }
    }
    for (int i = 0; i < n+1; i++) {
        find(i);
    }
    sort(parent.begin(), parent.end());
    cout << distance(parent.begin(), unique(parent.begin(), parent.end()))-1;


    return 0;
}

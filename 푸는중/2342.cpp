#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
pair<int,int> foot, lfoot, rfoot;
int l, r;

int comp(int b, int c){
    if(b == 0){
        return 2;
    }
    else if(abs(b-c) == 1){
        return 3;
    }
    else if(b==c){
        return 1;
    }
    else{
        return 4;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    a = vector<int>();
    foot = pair<int,int>({0,0});
    lfoot = pair<int,int>({0,0});
    rfoot = pair<int,int>({0,0});

    while(true){
        cin >> t;
        if(t == 0){
            break;
        }
        else{
            a.push_back(t);
        }
    }

    for(int i : a){
        int temp;
        pair<int,int> tempfoot;
        if(l+comp(lfoot.first, i) < r+comp(rfoot.first, i)){
            temp += comp(lfoot.first, i);
            tempfoot = lfoot;
            tempfoot.first = i;
        }
        else{
            temp = r+comp(rfoot.first, i);
            tempfoot = rfoot;
            tempfoot.first = i;
        }
        if(comp(lfoot.second, i) < comp(rfoot.second, i)){
            r = l+comp(lfoot.second, i);
            rfoot = lfoot;
            rfoot.second = i;
        }
        else{
            r += comp(rfoot.second, i);
            rfoot.second = i;
        }
        l = temp;
        lfoot = tempfoot;
    }

    cout << min(l,r);
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char dict[] = {'a', 'b', 'k', 'd', 'e', 'g', 'h', 'i', 'l', 'm', 'n', 'c', 'o', 'p', 'r', 's', 't', 'u', 'w', 'y'};
vector<string> l;

bool comp(string a, string b){
    for(int i = 0; i < a.size() && i < b.size(); i++){
        char a_target = a[i];
        char b_target = b[i];
        auto ait = find(begin(dict), end(dict), a_target);
        auto bit = find(begin(dict), end(dict), b_target);
        if(ait != bit){
            return ait < bit;
        }
    }
    return b.size() > a.size();
}

string ng2c(string a){
    string b = "";
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 'n'){
            if(a[++i] == 'g'){
                b += "c";
            }
            else{
                b += a[--i];
            }
        }
        else{
            b += a[i];
        }
    }
    return b;
}
string c2ng(string a){
    string b = "";
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 'c'){
            b += "ng";
        }
        else{
            b += a[i];
        }
    }
    return b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    l = vector<string>(n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
        l[i] = ng2c(l[i]);
    }
    sort(l.begin(), l.end(), comp);
    

    for(int i = 0; i < n; i++){
        cout << c2ng(l[i]) << '\n';
    }
    return 0;
}

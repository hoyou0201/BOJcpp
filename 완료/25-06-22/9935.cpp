#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

string s;
string t;
string r;

string stk;
stack<int> lk;
int l;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s >>t;
    r = "";
    stk = "";
    int tn = t.length();
    lk = stack<int>();
    for(char c : s){
        if(!stk.empty() && c == t[lk.top()]){
            stk += c;
            lk.top() += 1;
            if(lk.top() == tn){
                lk.pop();
                stk.erase(stk.size()-tn);
            }
        }
        else if(c == t[0]){
            stk += c;
            lk.push(1);
            
            if(lk.top() == tn){
                lk.pop();
                stk.erase(stk.size()-tn);
            }
        }
        else{
            r += stk;
            r += c;
            lk = stack<int>();
            stk = "";
        }
    }
    r += stk;
    if(r == ""){
        cout << "FRULA";
    }
    else{
        cout << r;
    }

    return 0;
}

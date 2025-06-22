#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

string s;
string t;
string r;

stack<string> stk;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s >>t;
    r = "";
    for(char c : s){
        if(c == t[0]){
            stk.push(string(1, c));
        }
        else if(!stk.empty() && c == t[stk.top().length()]){
            stk.top() += c;
            if(stk.top().length() == t.length()){
                stk.pop();
            }
        }
        else{
            r += c;
        }
    }
    cout << r;

    return 0;
}

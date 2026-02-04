#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <regex>
using namespace std;

stack<pair<char,int>> op;
stack<int> g;

string s;

int priority(char c){
    if(c == '+' || c == '-'){
        if(g.empty()) return 0;
        else return g.top();
    }
    else{
        if(g.empty()) return 1;
        else return g.top()+1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    for(char c : s){
        if(c >= 'A' && c <= 'Z'){
            cout << c;
        }
        else if(c == '('){
            if(g.empty()){
                g.push(2);
            }
            else{
                g.push(g.top()+2);
            }
        }
        else if(c == ')'){
            while(!op.empty() && op.top().second - g.top() >= 0){
                cout << op.top().first;
                op.pop();
            }
            g.pop();
        }
        else{
            if(op.empty()){
                op.emplace(c, priority(c));
                continue;
            }
            while(!op.empty() && priority(c) <= op.top().second){
                cout << op.top().first;
                op.pop();
            }
            op.emplace(c, priority(c));
            continue;
        }
    }
    while(!op.empty()){
        cout << op.top().first;
        op.pop();
    }
    return 0;
}
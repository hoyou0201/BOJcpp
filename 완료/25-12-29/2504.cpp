#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

string s;
stack<int> sta; //() -> 0, [] -> 1

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    for(char c : s){
        if(c == '('){
            sta.push(0);
        }
        else if(c == ')'){
            if(sta.size() == 0){
                cout << 0;
                return 0;
            }
            if(sta.top() == 0){
                sta.pop();
                sta.push(2);
            }
            else{
                int t = 0;
                while(sta.size() != 0 && sta.top() != 0){
                    if(sta.top() == 1){
                        cout << 0;
                        return 0;
                    }
                    t += sta.top();
                    sta.pop();
                }
                if(sta.size() == 0){
                    cout << 0;
                    return 0;
                }
                sta.pop();
                sta.push(t*2);
            }
        }
        if(c == '['){
            sta.push(1);
        }
        else if(c == ']'){
            if(sta.size() == 0){
                cout << 0;
                return 0;
            }
            if(sta.top() == 1){
                sta.pop();
                sta.push(3);
            }
            else{
                int t = 0;
                while(sta.size() != 0 && sta.top() != 1){
                    if(sta.top() == 0){
                        cout << 0;
                        return 0;
                    }
                    t += sta.top();
                    sta.pop();
                }
                if(sta.size() == 0){
                    cout << 0;
                    return 0;
                }
                sta.pop();
                sta.push(t*3);
            }
        }
    }
    int t = 0;
    while(sta.size() > 0 && sta.top() > 1){
        t += sta.top();
        sta.pop();
    }
    if(sta.size() != 0){
        cout << 0;
        return 0;
    }

    cout << t;

    return 0;
}

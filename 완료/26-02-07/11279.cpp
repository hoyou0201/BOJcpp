#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class pq{
    private:
        int data[100009];
        int idx;
    public:
        pq() : idx(0) {}
        bool empty(){
            return idx == 0;
        }
        void push(int k){
            idx++;
            data[idx] = k;
            int t = idx;
            while(t != 1 && data[t/2] < data[t]){
                int temp = data[t/2];
                data[t/2] = data[t];
                data[t] = temp;
                t/=2;
            }
        }
        int pop(){
            int r = data[1];
            data[1] = data[idx--];
            int t = 1;
            while(t <= idx/2){
                if(t*2+1 <= idx){
                    if(max(data[t*2], data[t*2+1]) <= data[t]){
                        break;
                    }
                    else if(data[t*2] < data[t*2+1]){
                        int temp = data[t*2+1];
                        data[t*2+1] = data[t];
                        data[t] = temp;
                        t*=2;
                        t++;
                    }
                    else{
                        int temp = data[t*2];
                        data[t*2] = data[t];
                        data[t] = temp;
                        t*=2;
                    }
                }
                else if(t*2 == idx){
                    if(data[2*t] > data[t]){
                        int temp = data[t*2];
                        data[t*2] = data[t];
                        data[t] = temp;
                    }
                    break;
                }
            }
            return r;

        }
};

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    pq q;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if(k == 0){
            if(q.empty()) cout << 0 << '\n';
            else cout << q.pop() << '\n';
        }
        else q.push(k);
    }

    return 0;
}

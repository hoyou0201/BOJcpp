#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n, min_left, min_right;
vector<long long> l;

int main(){
    cin >> n;

    l = vector<long long>(n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }

    sort(l.begin(), l.end());

    int left = 0;
    int right = n-1;
    long long min_sum = l[left] + l[right];
    min_left = left;
    min_right = right;
    while(left < right){
        long long sum =  l[left] + l[right];
        if(sum == 0){
            cout << l[left] << " " << l[right];
            return 0;
        }
        else if(sum > 0){
            if(llabs(min_sum) > llabs(sum)){
                min_sum = sum;
                min_left = left;
                min_right = right;
            }
            right--;
        }
        else{
            if(llabs(min_sum) > llabs(sum)){
                min_sum = sum;
                min_left = left;
                min_right = right;
            }
            left++;
        }
    }
    cout << l[min_left] << " " << l[min_right];
}
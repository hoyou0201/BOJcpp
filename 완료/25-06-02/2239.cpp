#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstdlib>
using namespace std;

vector<unordered_set<int>> row;
vector<unordered_set<int>> column;
vector<unordered_set<int>> square;
vector<pair<int,int>> blank;
vector<vector<int>> m_row;

bool isgood(int i, int j, int data){
    return row[i].count(data) == 0 && column[j].count(data) == 0 && square[(i/3)*3+j/3].count(data) == 0;
}

void dfs(int index){
    if(index == blank.size()){
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << m_row[i][j];
            }
        cout << '\n';
        }
        exit(0);
    }
    int x = blank[index].second;
    int y = blank[index].first;
    for (int i = 1; i <= 9; i++) {
        if(isgood(y,x,i)){
            row[y].insert(i);
            m_row[y][x] = i;
            column[x].insert(i);
            square[(y/3)*3+x/3].insert(i);
            dfs(index+1);
            row[y].erase(i);
            m_row[y][x] = 0;
            column[x].erase(i);
            square[(y/3)*3+x/3].erase(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;

    row = vector<unordered_set<int>>(9, unordered_set<int>());
    column = vector<unordered_set<int>>(9, unordered_set<int>());
    square = vector<unordered_set<int>>(9, unordered_set<int>());
    m_row = vector<vector<int>>(9, vector<int>(9,0));
    blank = vector<pair<int,int>>();

    for (int i = 0; i < 9; i++) {
        cin >> s;
        for (int j = 0; j < 9; j++) {
            m_row[i][j] = (s[j]-'0');
            if(s[j] == '0'){
                blank.push_back({i,j});
                continue;
            }
            row[i].insert(s[j]-'0');
            column[j].insert(s[j]-'0');
            square[(i/3)*3+j/3].insert(s[j]-'0');
        }
    }
    dfs(0);


    

    return 0;
}
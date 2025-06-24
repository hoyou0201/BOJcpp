#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<bool> banned(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int x; cin >> x;
        banned[x] = true;
    }

    int L = static_cast<int>(sqrt(2 * N)) + 2;

    vector<vector<int>> dist(N + 1, vector<int>(L + 1, INF));
    queue<pair<int,int>> q;

    /* 시작: 돌 1 에서 jump 길이 0 (아직 점프 안 함) */
    dist[1][0] = 0;
    q.push({1, 0});

    while (!q.empty()) {
        auto [pos, j] = q.front(); q.pop();
        int d = dist[pos][j];

        for (int nj = max(1, j - 1); nj <= j + 1; ++nj) {
            if (nj > L) continue;
            int np = pos + nj;
            if (np > N || banned[np]) continue;
            if (dist[np][nj] > d + 1) {
                dist[np][nj] = d + 1;
                q.push({np, nj});
            }
        }
    }

    int ans = *min_element(dist[N].begin(), dist[N].end());
    cout << (ans == INF ? -1 : ans);
    return 0;
}
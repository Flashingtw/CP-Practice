#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <tuple>
using namespace std;
const int MAXN = 105;
const int INF = 1e9;
vector<pair<int, int>> adj[MAXN][MAXN];
int dist[MAXN][MAXN][2];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int M, N, T, Q;
bool isValid(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

void solve() {
    if (!(cin >> M >> N >> T >> Q)) return;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            adj[i][j].clear();
        }
    }

    for (int i = 0; i < T; ++i) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        adj[r1][c1].push_back({r2, c2});
    }
    while (Q--) {
        int start_r, start_c, end_r, end_c;
        long long k;
        cin >> start_r >> start_c >> end_r >> end_c >> k;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dist[i][j][0] = INF;
                dist[i][j][1] = INF;
            }
        }
        deque<tuple<int, int, int>> dq;
        dist[start_r][start_c][0] = 0;
        dq.push_front({start_r, start_c, 0});
        while (!dq.empty()) {
            auto [ux, uy, p] = dq.front();
            dq.pop_front();
            int current_dist = dist[ux][uy][p];
            for (auto& edge : adj[ux][uy]) {
                int vx = edge.first;
                int vy = edge.second;

                if (dist[vx][vy][p] > current_dist) {
                    dist[vx][vy][p] = current_dist;
                    dq.push_front({vx, vy, p});
                }
            }
            for (int i = 0; i < 4; ++i) {
                int vx = ux + dx[i];
                int vy = uy + dy[i];

                if (isValid(vx, vy)) {
                    int next_p = 1 - p;
                    if (dist[vx][vy][next_p] > current_dist + 1) {
                        dist[vx][vy][next_p] = current_dist + 1;
                        dq.push_back({vx, vy, next_p});
                    }
                }
            }
        }
        int target_parity = k % 2;
        int shortest_dist = dist[end_r][end_c][target_parity];

        if (shortest_dist <= k) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
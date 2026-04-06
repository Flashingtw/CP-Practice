#include <bits/stdc++.h>
using namespace std;

int x_len, y_len;
int g[515][515];
bool vis[515][515];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Island {
    int w, n, e, s, a;
};

void bfs(int start_y, int start_x) {
    int min_x = start_x, max_x = start_x;
    int min_y = start_y, max_y = start_y;
    int area = 0;

    queue<pair<int, int>> q;
    q.push({start_y, start_x});
    vis[start_y][start_x] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        area++;

        int cur_y = cur.first;
        int cur_x = cur.second;

        min_x = min(min_x, cur_x);
        max_x = max(max_x, cur_x);
        min_y = min(min_y, cur_y);
        max_y = max(max_y, cur_y);

        for (int i = 0; i < 4; i++) {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];

            if (nx >= 0 && nx < x_len && ny >= 0 && ny < y_len && g[ny][nx] == 1 && !vis[ny][nx]) {
                vis[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
    cout << min_x << " " << min_y << " " << max_x << " " << max_y << " " << area << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> x_len >> y_len)) return 0;

    for (int i = 0; i < y_len; i++) {
        for (int j = 0; j < x_len; j++) {
            cin >> g[i][j];
            vis[i][j] = false;
        }
    }

    for (int i = 0; i < y_len; i++) {
        for (int j = 0; j < x_len; j++) {
            if (g[i][j] == 1 && !vis[i][j]) {
                bfs(i, j);
            }
        }
    }
}
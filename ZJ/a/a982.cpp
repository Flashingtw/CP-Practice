#include <bits/stdc++.h>
using namespace std;

struct P { int x, y; };

int main() {
    int n;
    while (cin >> n) {
        char g[105][105];
        int d[105][105];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> g[i][j];
                d[i][j] = -1;
            }
        }

        queue<P> q;
        q.push({1, 1});
        d[1][1] = 1; 

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        bool found = false;

        for (; !q.empty(); ) {
            P cur = q.front();
            q.pop();

            if (cur.x == n - 2 && cur.y == n - 2) {
                cout << d[cur.x][cur.y] << '\n';
                found = true;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && g[nx][ny] == '.' && d[nx][ny] == -1) {
                    d[nx][ny] = d[cur.x][cur.y] + 1;
                    q.push({nx, ny});
                }
            }
            if (found) break;
        }

        if (!found) {
            cout << "No solution!" << '\n';
        }
    }
}
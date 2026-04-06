#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> n >> m;
        int r[105][105] = {0};
        
        int dr1[] = {0, 1, 0, -1};
        int dc1[] = {1, 0, -1, 0};
        int dr2[] = {1, 0, -1, 0};
        int dc2[] = {0, 1, 0, -1};

        int *dr = dr1, *dc = dc1;
        if (m == 2) {
            dr = dr2;
            dc = dc2;
        }

        int x = 0, y = 0, d = 0;
        for (int i = 1; i <= n * n; i++) {
            r[x][y] = i;
            if (i == n * n) break;
            
            int nx = x + dr[d];
            int ny = y + dc[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || r[nx][ny] != 0) {
                d = (d + 1) % 4;
                nx = x + dr[d];
                ny = y + dc[d];
            }
            x = nx;
            y = ny;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << setw(5) << r[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

long long s[505][505];

int main() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int val;
                cin >> val;
                s[i][j] = val + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            }
        }

        for (int i = 0; i < m; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            long long ans = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
            cout << ans << '\n';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    if (cin >> t) {
        for (int k = 0; k < t; k++) {
            int n, m;
            cin >> n >> m;
            long long g[15][15];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> g[i][j];
                }
            }

            bool ok = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (g[i][j] != g[n - 1 - i][m - 1 - j]) {
                        ok = false;
                    }
                }
            }

            if (ok) cout << "go forward" << '\n';
            else cout << "keep defending" << '\n';
        }
    }
}
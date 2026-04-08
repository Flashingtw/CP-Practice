#include <bits/stdc++.h>

using namespace std;

int deg[10005];

int main() {
    int n, m;
    while (cin >> n >> m) {
        memset(deg, 0, sizeof(deg));
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            deg[a]++;
            deg[b]++;
        }

        int odd = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i] % 2 != 0) {
                odd++;
            }
        }

        if (odd == 0 || odd == 2) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}
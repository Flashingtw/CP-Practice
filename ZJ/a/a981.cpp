#include <bits/stdc++.h>
using namespace std;

int n, m, a[35], p[35];
bool f;

void dfs(int id, int sum, int pi) {
    if (sum == m) {
        f = true;
        for (int i = 0; i < pi; i++) {
            cout << p[i] << (i == pi - 1 ? "" : " ");
        }
        cout << '\n';
    } else if (id < n && sum < m) {
        p[pi] = a[id];
        dfs(id + 1, sum + a[id], pi + 1);

        dfs(id + 1, sum, pi);
    }
}

int main() {
    while (cin >> n >> m) {
        f = false;
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);

        dfs(0, 0, 0);

        if (!f) cout << -1 << '\n';
    }
}
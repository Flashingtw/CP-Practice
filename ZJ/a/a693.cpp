#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<long long> p(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int val;
            cin >> val;
            p[i] = p[i - 1] + val;
        }

        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            cout << p[r] - p[l - 1] << '\n';
        }
    }
}
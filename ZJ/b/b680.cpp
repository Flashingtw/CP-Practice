#include <bits/stdc++.h>
using namespace std;

struct P {
    int id;
    double s;
};

bool cmp(P a, P b) {
    return a.s < b.s;
}

int main() {
    int n;
    while (cin >> n) {
        vector<P> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].id >> v[i].s;
        sort(v.begin(), v.end(), cmp);

        int gn = n / 8;
        vector<vector<int>> g(gn, vector<int>(8));
        int lane[] = {4, 5, 3, 6, 2, 7, 1, 8};

        for (int i = 0; i < n; i++) {
            int r = i / gn;
            int c = i % gn;
            if (r % 2 == 0) {
                g[c][r] = v[i].id;
            } else {
                g[gn - 1 - c][r] = v[i].id;
            }
        }

        for (int i = 0; i < gn; i++) {
            cout << i + 1;
            int res[9];
            for (int j = 0; j < 8; j++) {
                res[lane[j]] = g[i][j];
            }
            for (int j = 1; j <= 8; j++) {
                cout << " " << res[j];
            }
            cout << '\n';
        }
    }
}
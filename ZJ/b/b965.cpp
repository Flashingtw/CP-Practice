#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c, m;
    while (cin >> r >> c >> m) {
        vector<vector<int>> v(r, vector<int>(c));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> v[i][j];
        
        vector<int> op(m);
        for (int i = 0; i < m; i++) cin >> op[i];

        for (int i = m - 1; i >= 0; i--) {
            if (op[i] == 1) {
                reverse(v.begin(), v.end());
            } else {
                int nr = v[0].size(), nc = v.size();
                vector<vector<int>> t(nr, vector<int>(nc));
                for (int r_idx = 0; r_idx < nc; r_idx++)
                    for (int c_idx = 0; c_idx < nr; c_idx++)
                        t[nr - 1 - c_idx][r_idx] = v[r_idx][c_idx];
                v = t;
            }
        }

        cout << v.size() << " " << v[0].size() << '\n';
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                cout << v[i][j] << (j == v[i].size() - 1 ? "" : " ");
            }
            cout << '\n';
        }
    }
}
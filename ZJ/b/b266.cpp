#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c, m;
    while (cin >> r >> c >> m) {
        vector<vector<int>> a(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> a[i][j];
            }
        }

        vector<int> ops(m);
        for (int i = 0; i < m; i++) cin >> ops[i];

        for (int i = m - 1; i >= 0; i--) {
            if (ops[i] == 1) {
                reverse(a.begin(), a.end());
            } 
            else {
                int nr = a[0].size();
                int nc = a.size();
                vector<vector<int>> tmp(nr, vector<int>(nc));
                for (int j = 0; j < nr; j++) {
                    for (int k = 0; k < nc; k++) {
                        tmp[j][k] = a[k][nr - 1 - j];
                    }
                }
                a = tmp;
            }
        }

        cout << a.size() << " " << a[0].size() << '\n';
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[i].size(); j++) {
                cout << a[i][j] << (j == a[i].size() - 1 ? "" : " ");
            }
            cout << '\n';
        }
    }
}
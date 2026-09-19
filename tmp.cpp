#include<bits/stdc++.h>

using namespace std;
void f( vector<vector<int>>a) {
    int r = a.size();
    int c = a[0].size();
    vector<vector<int>> res(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = a[r - 1 - i][j];
        }
    }
    return res;
}

void p( vector<vector<int>> a) {
    int r = a.size();
    int c = a[0].size();
    vector<vector<int>> res(c, vector<int>(r));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[c - 1 - j][i] = a[i][j];
        }
    }
    return res;
}
#
int main() {
    int r, c, m;
    cin >> r >> c >> m;
    vector<vector<int>> a(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> o(m);
    for (int i = 0; i < m; i++) {
        cin >> o[i];
    }
    for (int i = m - 1; i >= 0; i--) {
        if (o[i] == 1) {
            a = f(a);
        }
        else if (o[i] == 0) {
            a = p(a);
            swap(r, c);
        }
    }

    cout << r << " " << c << '\n';
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j];
            if (j != c - 1) cout << " ";
        }
        cout << '\n';
    }

    return 0;
}
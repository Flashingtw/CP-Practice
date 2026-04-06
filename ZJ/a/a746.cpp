#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        bool v[505][505] = {false};
        int x1, y1, x2, y2;
        
        cin >> x1 >> y1;
        v[x1][y1] = true;
        
        for (int i = 1; i < m; i++) {
            cin >> x2 >> y2;
            if (x1 == x2) {
                int start = min(y1, y2);
                int end = max(y1, y2);
                for (int j = start; j <= end; j++) v[x1][j] = true;
            } else {
                int start = min(x1, x2);
                int end = max(x1, x2);
                for (int j = start; j <= end; j++) v[j][y1] = true;
            }
            x1 = x2;
            y1 = y2;
        }

        for (int i = 0; i < n + 2; i++) cout << '-';
        cout << '\n';

        for (int i = 1; i <= n; i++) {
            cout << '|'; 
            for (int j = 1; j <= n; j++) {
                if (v[i][j]) cout << '*';
                else cout << ' ';
            }
            cout << '|' << '\n';
        }

        for (int i = 0; i < n + 2; i++) cout << '-';
        cout << '\n';
    }
}
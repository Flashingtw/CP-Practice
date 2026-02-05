#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    if (max(n, m) <= x) return true;
    if (min(n, m) == 1 && max(n, m) <= y) return true;

    if (n % 2 == 1 && m % 2 == 1) return true;
    if (n % 2 == 0 && m % 2 == 0) return x >= 2;
    if (x >= 2 || y >= 2) return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        if (solve()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

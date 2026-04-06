#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int h1, m1, h2, m2, m3;
        cin >> h1 >> m1 >> h2 >> m2 >> m3;
        int t1 = h1 * 60 + m1;
        int t2 = h2 * 60 + m2;
        if (t1 + m3 <= t2) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}
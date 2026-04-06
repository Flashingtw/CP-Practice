#include <bits/stdc++.h>
using namespace std;

int n, t;
int c[10];
int s[10];

void f(int d, int sum) {
    if (d == n) {
        if (sum == t) {
            cout << "(";
            for (int i = 0; i < n; i++) {
                cout << s[i] << (i == n - 1 ? "" : ",");
            }
            cout << ")\n";
        }
    } else {
        for (int i = 0; sum + i * c[d] <= t; i++) {
            s[d] = i;
            f(d + 1, sum + i * c[d]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (;;) {
        if (!(cin >> n)) break;
        for (int i = 0; i < n; i++) cin >> c[i];
        cin >> t;
        f(0, 0);
        break;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    long long a, b, m, s, x, y, t;
    while (cin >> a >> b) {
        x = a;
        y = b;
        while (y) {
            t = x % y;
            x = y;
            y = t;
        }
        a /= x;
        b /= x;
        m = 1;
        s = 0;
        while (a != 1 || b != 1) {
            if (a > b) {
                m *= 2;
                a -= b;
            } else {
                s += m;
                swap(a, b);
            }
        }
        cout << m + s << '\n';
    }
}
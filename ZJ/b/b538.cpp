#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    long long a, b, c, d, p, q, x, y, t;
    char o;
    while (cin >> a >> b >> c >> d >> o) {
        if (o == '+') {
            p = a * d + b * c;
            q = b * d;
        } else if (o == '-') {
            p = a * d - b * c;
            q = b * d;
        } else if (o == '*') {
            p = a * c;
            q = b * d;
        } else {
            p = a * d;
            q = b * c;
        }
        
        x = abs(p);
        y = abs(q);
        while (y) {
            t = x % y;
            x = y;
            y = t;
        }
        
        if (x != 0) {
            p /= x;
            q /= x;
        }
        
        if (q < 0) {
            p = -p;
            q = -q;
        }
        
        if (q == 1) {
            cout << p << '\n';
        } else {
            cout << p << '/' << q << '\n';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    long long x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        long long dy = y2 - y1;
        long long dx2 = (x2 - x1) * (x2 - x1);
        
        long long common = abs(gcd(dy, dx2));
        long long p = dy / common;
        long long q = dx2 / common;
        
        if (q < 0) {
            p = -p;
            q = -q;
        }

        long long b = p;
        long long c = -2 * p * x1;
        long long d = p * x1 * x1 + q * y1;

        cout << q << "y = " << b << "x^2 + " << c << "x + " << d << '\n';
    }
}
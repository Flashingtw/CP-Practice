#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    double det = a * e - b * d;
    double dx = c * e - b * f;
    double dy = a * f - c * d;

    if (det != 0) {
        double x = dx / det;
        double y = dy / det;
        if (abs(x) < 0.005) x = 0;
        if (abs(y) < 0.005) y = 0;
        
        cout << fixed << setprecision(2);
        cout << "x=" << x << '\n';
        cout << "y=" << y << '\n';
    } else {
        if (dx == 0 && dy == 0) {
            cout << "Too many" << '\n';
        } else {
            cout << "No answer" << '\n';
        }
    }
}
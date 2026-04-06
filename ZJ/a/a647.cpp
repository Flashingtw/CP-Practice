#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double m, p;
        cin >> m >> p;
        double x = (p - m) / m * 100.0;
        
        if (x >= 0) x += 1e-9;
        else x -= 1e-9;
        if (abs(x) < 1e-7) x = 0.0;

        cout << fixed << setprecision(2) << x << "% ";
        
        if (x >= 10.0 || x <= -7.0) {
            cout << "dispose" << '\n';
        } else {
            cout << "keep" << '\n';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (a == 1) cout << b + c << '\n';
        else if (a == 2) cout << b - c << '\n';
        else if (a == 3) cout << b * c << '\n';
        else if (a == 4) cout << b / c << '\n';
    }
}
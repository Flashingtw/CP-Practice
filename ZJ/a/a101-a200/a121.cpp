#include <bits/stdc++.h>
using namespace std;

bool is_p(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        int c = 0;
        for (int i = a; i <= b; i++) {
            if (is_p(i)) c++;
        }
        cout << c << '\n';
    }
}
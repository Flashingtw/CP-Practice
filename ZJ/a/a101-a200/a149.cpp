#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    long long n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n == 0) {
            cout << 0 << '\n';
            continue;
        }
        long long ans = 1;
        while (n > 0) {
            ans *= (n % 10);
            n /= 10;
        }
        cout << ans << '\n';
    }
}
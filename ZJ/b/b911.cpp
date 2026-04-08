#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    while (cin >> n) {
        if (n == 0) {
            cout << 0 << '\n';
        } else {
            int ans = 0;
            while (n > 0) {
                n >>= 1;
                ans++;
            }
            cout << ans << '\n';
        }
    }
}
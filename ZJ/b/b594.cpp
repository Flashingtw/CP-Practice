#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    while (cin >> n && n != 0) {
        int ans = 0;
        for (long long m = 2; m * (m + 1) / 2 <= n; m++) {
            long long temp = n - m * (m - 1) / 2;
            if (temp > 0 && temp % m == 0) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}
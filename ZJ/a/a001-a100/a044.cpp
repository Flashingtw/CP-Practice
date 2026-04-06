#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    while (cin >> n) {
        long long ans = (n * n * n + 5 * n + 6) / 6;
        cout << ans << '\n';
    }
}
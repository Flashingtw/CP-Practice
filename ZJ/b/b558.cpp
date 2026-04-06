#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    long long n;
    while (cin >> n) {
        cout << 1 + n * (n - 1) / 2 << '\n';
    }
}
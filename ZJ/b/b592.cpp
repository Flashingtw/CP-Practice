#include <bits/stdc++.h>
using namespace std;

long long f(int n, int p, int t[]) {
    if (n == 0) return 0;
    if (t[n] == p) return f(n - 1, p, t);
    return f(n - 1, 6 - p - t[n], t) + (1LL << (n - 1));
}

long long g(int n, int s[], int t[]) {
    if (n == 0) return 0;
    if (s[n] == t[n]) return g(n - 1, s, t);
    int m = 6 - s[n] - t[n];
    return f(n - 1, m, s) + 1 + f(n - 1, m, t);
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        int s[35], t[35];
        for (int i = 1; i <= n; i++) cin >> s[i];
        for (int i = 1; i <= n; i++) cin >> t[i];
        cout << g(n, s, t) << '\n';
    }
}
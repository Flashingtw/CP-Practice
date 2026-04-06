#include <bits/stdc++.h>
using namespace std;

long long f[30005], g[30005];

int main() {
    f[1] = 1;
    g[1] = 1;
    for (int i = 2; i <= 30000; i++) {
        f[i] = i + f[i - 1];
        g[i] = f[i] + g[i - 1];
    }

    int n;
    while (cin >> n) {
        cout << f[n] << " " << g[n] << '\n';
    }
}
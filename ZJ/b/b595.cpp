#include <bits/stdc++.h>
using namespace std;

int a[35];
long long dp[35];
int pre[35];

void path(int i) {
    if (i < 0) return;
    path(pre[i]);
    cout << i << (i == 0 ? "" : " ");
}

void solve(int i) {
    if (i == -1) return;
    solve(pre[i]);
    cout << i << " ";
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        a[0] = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];

        for (int i = 1; i <= n; i++) dp[i] = -1;
        dp[0] = 0;
        pre[0] = -1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                long long cost = dp[j] + (long long)pow(200 - (a[i] - a[j]), 2);
                if (dp[i] == -1 || cost <= dp[i]) {
                    dp[i] = cost;
                    pre[i] = j;
                }
            }
        }
        solve(n);
        cout << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

void dfs(int l, int r, int n, string s) {
    if (l == n && r == n) {
        cout << s << '\n';
        return;
    }
    if (l < n) {
        dfs(l + 1, r, n, s + "(");
    }
    if (r < l) {
        dfs(l, r + 1, n, s + ")");
    }
}

int main() {
    int n;
    while (cin >> n) {
        dfs(0, 0, n, "");
    }
}
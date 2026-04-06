#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    vector<bool> vis(n, false);
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt++;
            int cur = i;
            for (; !vis[cur]; ) {
                vis[cur] = true;
                cur = f[cur];
            }
        }
    }

    cout << cnt << '\n';
}
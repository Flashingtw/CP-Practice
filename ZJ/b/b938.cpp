#include <bits/stdc++.h>

using namespace std;

int nxt[1000005];
bool dead[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i < n; i++) {
            nxt[i] = i + 1;
            dead[i] = false;
        }
        nxt[n] = 0;
        dead[n] = false;

        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;

            if (dead[k] || nxt[k] == 0) {
                cout << "0u0 ...... ?" << '\n';
            } else {
                int target = nxt[k];
                cout << target << '\n';
                nxt[k] = nxt[target];
                dead[target] = true;
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int c[30005];

int main() {
    int n;
    if (cin >> n) {
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            c[v]++;
            if (c[v] > mx) {
                mx = c[v];
            }
        }

        for (int i = 1; i <= 30000; i++) {
            if (c[i] == mx) {
                cout << i << " " << mx << '\n';
            }
        }
    }
}
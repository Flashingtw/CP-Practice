#include <bits/stdc++.h>
using namespace std;

int main() {
    int g[4];
    while (cin >> g[0] >> g[1] >> g[2] >> g[3]) {
        int n;
        cin >> n;
        for (int k = 0; k < n; k++) {
            int t[4];
            for (int i = 0; i < 4; i++) cin >> t[i];

            int a = 0, b = 0;
            int gc[10] = {0}, tc[10] = {0};

            for (int i = 0; i < 4; i++) {
                if (t[i] == g[i]) {
                    a++;
                } else {
                    gc[g[i]]++;
                    tc[t[i]]++;
                }
            }

            for (int i = 0; i < 10; i++) {
                if (gc[i] < tc[i]) b += gc[i];
                else b += tc[i];
            }

            cout << a << "A" << b << "B" << '\n';
        }
    }
}
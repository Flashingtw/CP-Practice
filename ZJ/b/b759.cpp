#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    for (;;) {
        if (!(cin >> s)) break;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << s[(i + j) % n];
            }
            cout << '\n';
        }
        break;
    }
}
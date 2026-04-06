#include <bits/stdc++.h>
using namespace std;

int c[30][30];

void init() {
    for (int i = 0; i <= 26; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
}

int main() {
    init();
    string s;
    while (cin >> s && s != "0") {
        bool ok = true;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] <= s[i - 1]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << 0 << '\n';
            continue;
        }

        int ans = 0;
        int len = s.length();
        for (int i = 1; i < len; i++) ans += c[26][i];

        int last = 0;
        for (int i = 0; i < len; i++) {
            int cur = s[i] - 'a' + 1;
            for (int j = last + 1; j < cur; j++) {
                ans += c[26 - j][len - 1 - i];
            }
            last = cur;
        }
        cout << ans + 1 << '\n';
    }
}
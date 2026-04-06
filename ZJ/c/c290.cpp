#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int a = 0;
    int b = 0;

    for (int i = 0; i < s.length(); i++) {
        if (i % 2 == 0) {
            a += s[i] - '0';
        } else {
            b += s[i] - '0';
        }
    }

    int ans = a - b;
    if (ans < 0) {
        ans = -ans;
    }

    cout << ans << '\n';
}
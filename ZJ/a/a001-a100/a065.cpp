#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < 6; i++) {
        cout << abs(s[i] - s[i + 1]);
    }
    cout << '\n';
}
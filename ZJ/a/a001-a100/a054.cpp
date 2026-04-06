#include <bits/stdc++.h>
using namespace std;

int main() {
    int m[] = {10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
    string s;
    while (cin >> s) {
        int ck = s[8] - '0';
        for (int i = 0; i < 26; i++) {
            int n = m[i];
            int sum = (n / 10) + (n % 10) * 9;
            for (int j = 0; j < 8; j++) {
                sum += (s[j] - '0') * (8 - j);
            }
            int r = (10 - (sum % 10)) % 10;
            if (r == ck) cout << (char)('A' + i);
        }
        cout << '\n';
    }
}
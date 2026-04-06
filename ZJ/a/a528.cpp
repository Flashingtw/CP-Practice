#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
    if (a[0] == '-' && b[0] != '-') return true;
    if (a[0] != '-' && b[0] == '-') return false;
    
    if (a[0] == '-') {
        if (a.length() != b.length()) return a.length() > b.length();
        return a > b;
    } else {
        if (a.length() != b.length()) return a.length() < b.length();
        return a < b;
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < n; i++) {
            cout << v[i] << '\n';
        }
    }
}
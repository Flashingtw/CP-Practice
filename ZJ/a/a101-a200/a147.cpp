#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        bool first = true;
        for (int i = 1; i < n; i++) {
            if (i % 7 != 0) {
                if (!first) cout << " ";
                cout << i;
                first = false;
            }
        }
        cout << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (cin >> n) {
        long long s = 0;
        for (int i = 1; i <= n; i++) {
            long long a;
            cin >> a;
            s += (i * a);
        }
        cout << s << '\n';
    }
}
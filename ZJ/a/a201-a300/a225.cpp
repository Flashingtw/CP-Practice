#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    int r1 = a % 10;
    int r2 = b % 10;
    if (r1 != r2) return r1 < r2;
    return a > b;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < n; i++) {
            cout << v[i] << (i == n - 1 ? "" : " ");
        }
        cout << '\n';
    }
}
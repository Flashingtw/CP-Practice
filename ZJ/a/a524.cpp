#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = n - i;
        }

        bool hasNext = true;
        for (; hasNext; ) {
            for (int i = 0; i < n; i++) {
                cout << v[i];
            }
            cout << '\n';
            hasNext = prev_permutation(v.begin(), v.end());
        }
    }
}
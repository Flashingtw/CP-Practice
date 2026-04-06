#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    while (cin >> n) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            sum += x;
        }
        if (sum / n > 59) {
            cout << "no" << '\n';
        } else {
            cout << "yes" << '\n';
        }
    }
}
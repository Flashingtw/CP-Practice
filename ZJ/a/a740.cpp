#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    while (cin >> n) {
        long long s = 0;
        long long d = 2;
        long long temp = n;

        for (; d * d <= temp; ) {
            for (; temp % d == 0; ) {
                s += d;
                temp /= d;
            }
            d++;
        }

        if (temp > 1) {
            s += temp;
        }

        cout << s << '\n';
    }
}
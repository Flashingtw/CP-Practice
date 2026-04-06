#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    while (cin >> n) {
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }

        string binary = "";
        while (n > 0) {
            binary += to_string(n % 2);
            n /= 2;
        }
        reverse(binary.begin(), binary.end());
        cout << binary << endl;
    }
}
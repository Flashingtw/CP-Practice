#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int cnt = 0;
        int temp = n;
        for (; (temp & 1) == 1; ) {
            cnt++;
            temp >>= 1;
        }
        cout << cnt << '\n';
    }
}
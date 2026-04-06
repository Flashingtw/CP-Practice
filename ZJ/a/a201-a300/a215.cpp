#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    while (cin >> n >> m) {
        long long sum = 0;
        int cnt = 0;
        for (long long i = n;; i++) {
            sum += i;
            cnt++;
            if(sum>m) break;
        }
        cout << cnt << '\n';
    }
}
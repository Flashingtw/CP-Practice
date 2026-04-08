#include <bits/stdc++.h>

using namespace std;

map<long long, long long> mp;

long long solve(long long n, long long m) {
    if (n < m) return 0;
    if (n < 2 * m) return 1;
    if (mp.count(n)) return mp[n];
    
    return mp[n] = solve(n / 2, m) + solve((n + 1) / 2, m);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    while (cin >> n >> m) {
        mp.clear();
        cout << solve(n, m) << '\n';
    }
}
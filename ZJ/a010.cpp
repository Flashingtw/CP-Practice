#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;
    vector<pair<long long, int>> v;
    for (long long i=2;i*i<=n;i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                count++;
                n /= i;
            }
            v.push_back({i, count});
        }
    }
    if (n > 1) {
        v.push_back({n, 1});
    }
    for (int i = 0; i < v.size(); i++) {
        if (i > 0) cout << " * ";
        
        if (v[i].second == 1) {
            cout << v[i].first;
        } else {
            cout << v[i].first << "^" << v[i].second;
        }
    }
    cout << '\n';

    return 0;
}
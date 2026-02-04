#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
vector<int> cnt(N,0);
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i];
        cnt[v[i]]++;
    }
    int q;
    cin>>q;
    while (q--) {
        int val;
        cin>>val;
        if (val>N-1) {
            cout << 0 << "\n";
            continue;
        }
        cout << cnt[val] << "\n";
    }
}
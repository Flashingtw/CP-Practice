#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n+1,0),prefix(n+1,0);
    for (int i=1;i<=n;i++) {
        cin>>v[i];
        prefix[i] = prefix[i-1]^v[i];
    }
    int q;
    cin>>q;
    while (q--) {
        int a,b;
        cin>>a>>b;
        cout << (prefix[b]^prefix[a-1]) << "\n";
    }
}
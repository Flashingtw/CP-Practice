#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,f=0;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    for (int i=n-1;i>=0;i--) {
        f = max(f,v[i]);
        if (f!=0) {
            v[i]=1;
            f--;
        }
    }
    for (int i: v) {
        cout << i <<" ";
    }
    cout << "\n";
}
int main() {
    int t;
    cin>>t;
    while (t--) solve();
}
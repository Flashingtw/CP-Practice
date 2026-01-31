#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n),b(n);
    int b_max=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) {
        cin>>b[i];
        b_max = max(b_max,b[i]);
    }
    vector<long long> c(n);
    for(int i = 0; i < n; i++){
        c[i] = max(a[i], b[i]);
    }
    vector<long long> suf_max(n);
    suf_max[n-1] = c[n-1];
    for(int i = n - 2; i >= 0; i--){
        suf_max[i] = max(c[i], suf_max[i+1]);
    }
    vector<long long> prefix(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix[i+1] = prefix[i] + suf_max[i];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << " ";
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<long long> a(n);
    for(auto &i:a) cin>>i;
    vector<long long> d(n);
    d[0] = a[0]-a[n-1];
    for(int i=1;i<n;i++) {
        d[i] = a[i]-a[i-1];
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=max(0LL,d[i]);
    }
    ans = max(*max_element(a.begin(),a.end()),ans);
    cout << ans << '\n';
}
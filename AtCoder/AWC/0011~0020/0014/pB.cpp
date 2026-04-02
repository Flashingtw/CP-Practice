#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,v;
    cin>>n>>v;
    vector<ll> d(n);
    d[0]=0;
    for(int i=1;i<n;i++){
        cin>>d[i];
        d[i]+=d[i-1];
    }
    vector<int> ans;
    for(int i=2;i<=n;i++){
        ll t;
        cin>>t;
        if((__int128_t)t*v>d[i-1]){
            ans.push_back(i);
        }
    }
    if(ans.empty()) cout << -1;
    else for(int i:ans) cout << i << ' ';
}
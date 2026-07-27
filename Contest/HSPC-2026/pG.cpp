#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF = 1e9+9;
ll mod = 1e9+7;
ll fpow(ll base,ll p){
    ll res=1;
    while(p>0){
        if(p&1) res = (res*base)%mod;
        base = (base*base)%mod;
        p/=2;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<pll> v(m);
    for(auto &[a,b]:v) cin>>a>>b;
    sort(v.begin(),v.end());
    ll dp0=1,dp1=0;
    ll cur=0;
    for(auto [a,b]:v){
        ll k = a-cur-1;
        if(k>0){
            ll sum = (dp0+dp1)%mod;
            ll val = (sum*fpow(2,k-1))%mod;
            dp0 = val;
            dp1 = val;
        }
        if(b==1) {
            dp1 = dp0;
            dp0 = 0;
        }
        else {
            dp0 = dp1;
            dp1 = 0;
        }
        cur = a;
    }
    if(cur<n){
        ll sum = (dp0+dp1)%mod;
        ll val = (sum*fpow(2,n-cur-1))%mod;
        dp0 = val;
        dp1 = val;
    }
    cout << (dp0+dp1)%mod << '\n';
}
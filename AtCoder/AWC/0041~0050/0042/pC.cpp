#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const ll mod = 998244353;
ll fpow(ll base,ll p){
    base = base%mod;
    ll res=1;
    while(p>0){
        if(p&1) res = (res*base)%mod;
        base = (base*base) % mod;
        p>>=1;
    }
    return res%mod;
}

int main(){
    int n,d;
    cin>>n>>d;
    vector<ll> p(n);
    vector<ll> w(d);
    ll s=0;
    for(int i=0;i<n;i++) {
        cin>>p[i];
        s+=p[i];
    }
    ll miv = fpow(s,mod-2);
    ll td =0;
    for(int i=0;i<d;i++) {
        cin>>w[i];
        td+=w[i];
    }
    td%=mod;
    vector<ll> t(n);
    for(int i=0;i<n;i++){
        t[i] = (p[i]*td%mod)*miv%mod;
    }
    ll ans=1;
    for(int i=0;i<n;i++){
        ans = (ans*t[i])%mod;
    }
    cout << ans;
}
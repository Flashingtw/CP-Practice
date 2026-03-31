#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int N = 1e6+5;
ll lvl[N];

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

ll C(ll n,ll k){
    ll num = lvl[n];
    ll inv1 = fpow(lvl[k],mod-2);
    ll inv2 = fpow(lvl[n-k],mod-2);
    return (num*inv1%mod)*inv2%mod;
}

int main(){
    ll n,k;
    cin>>n>>k;
    lvl[1]=1;
    lvl[0]=1;
    for(int i=2;i<N;i++){
        lvl[i]=(lvl[i-1]*i)%mod;
    }
    if (n-k+1<k) cout << 0 << '\n';
    else cout << C(n-k+1,k) << '\n';
}
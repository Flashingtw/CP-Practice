#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod =  998244353;
const int N = 5e5+5;
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
    ll n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        sum = (sum+a)%mod;
    }
    lvl[1]=1;
    lvl[0]=1;
    for(int i=2;i<N;i++){
        lvl[i]=(lvl[i-1]*i)%mod;
    }
    if(n==1){
        cout << sum;
        return 0;
    }
    ll c;
    if(n&1){
        c = (fpow(2,n-2)+(C(n-1,(n-1)/2)*fpow(2,mod-2))%mod)%mod;
    }
    else{
        c = fpow(2,n-2);
    }
    cout << (c*sum)%mod;
}
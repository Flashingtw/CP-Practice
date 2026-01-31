#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int N = 1000005;
typedef long long ll;
ll fact[N];

ll power(ll base,ll y) {
    ll res=1;
    base%=mod;
    while (y>0) {
        if (y&1) res = (res*base)%mod;
        base = (base*base)%mod;
        y/=2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n,mod-2);
}

void precompute() {
    fact[0]=1;
    for (int i=1;i<N;i++) {
        fact[i]= (fact[i-1]*i)%mod;
    }
}

ll nCr(ll n,ll k) {
    if (k<0||k>n) return 0;
    return fact[n]*modInverse(fact[k])%mod*modInverse(fact[n-k])%mod;
}
int main() {
    int k;
    cin>>k;
    precompute();
    while (k--) {
        long long n,m;
        cin>>n>>m;
        cout << nCr(n,m) << "\n";
    }
}
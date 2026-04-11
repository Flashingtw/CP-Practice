#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll INF = 1e18+9;
const ll mod = 998244353;
const int N = 2e5+5;
ll pre[N];
ll both[N];

ll L[N],R[N];
ll fpow(ll a, ll b) {
    ll res = 1;
    while (b>0) {
        if (b&1) res=res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}
ll fact[N], invFact[N];
void init_math() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i=1;i<N;i++) {
        fact[i] = fact[i-1]*i%mod;
    }
    invFact[N-1] = fpow(fact[N - 1], mod-2);
    for (int i = N-2; i>=1;i--) {
        invFact[i] = invFact[i+1]*(i+1)%mod;
    }
}

ll C(ll n,ll m){
    if(m<0||m>n) return 0;
    return ((fact[n]*invFact[m])%mod*invFact[n-m])%mod;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int l,r;
        cin>>l>>r;
        pre[l]++;
        pre[r+1]--;
        L[i]=l,R[i]=r;
    }
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1]+pre[i];
    }
    for(int i=1;i<=n;i++){
        ll l = max(L[i],n-R[i]);
        ll r = min(R[i],n-L[i]);
        if(l<=r){
            both[l]++;
            both[r+1]--;
        }
    }
    for(int i=1;i<=n;i++){
        both[i] = both[i-1]+both[i]; 
    }
    init_math();

    ll ans=0;
    for(int i=1;i<n;i++){
        ll Z = both[i];
        ll Y = pre[i]-Z;
        ll X = pre[n-i]-Z;
        ll W = n-(pre[i]+pre[n-i]-Z);
        if(W>0) continue;
        ans = (ans+C(Z,i-Y)) %mod;
    }
    cout << ans << '\n';
}
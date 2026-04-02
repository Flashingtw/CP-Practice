#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
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
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll cur=1;
    for(int i=0;i<k;i++){
        cur = (cur*v[i])%mod;
    }
    ll sum = cur;
    for(int i=k,j=0;i<n;i++){
        cur = (cur*fpow(v[j],mod-2))%mod;
        cur = (cur*v[i])%mod;
        sum = (sum+cur)%mod;
        j++;
    }
    cout << sum;
}
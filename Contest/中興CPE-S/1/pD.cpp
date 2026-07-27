#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;

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
    ll n;
    cin>>n;
    ll o = (n+1)/2, e = (n)/2;
    cout << (fpow(o,o)*fpow(e,e))%mod;
}

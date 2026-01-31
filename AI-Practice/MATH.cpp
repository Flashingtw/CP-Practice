#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exGCD(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll d = exGCD(b, a % b, x, y);
    ll temp = x;
    x = y;
    y = temp-(a/b)*y;
    return d;
}

ll modInverse(ll a,ll m){
    ll x,y;
    ll g = exGCD(a,m,x,y);
    if(g!=1) return -1;
    return (x%m+m)%m;
}

ll CRT(vector<ll> remainder, vector<ll> mod){
    ll prod=1;
    ll ans=0;
    for (ll m:mod) prod*=m;
    for (int i=0;i<remainder.size();i++){
        ll a_i= remainder[i];
        ll m_i= mod[i];
        ll Mi = prod/m_i;
        ll ti = modInverse(Mi,m_i);
        ll term = (a_i*Mi)%prod;
        term = (term*ti)%prod;
        ans = (ans+term)%prod;
    }
    return (ans+prod)%prod;
}

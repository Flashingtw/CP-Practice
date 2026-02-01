#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct RollingHash{
    const ll P1 = 131;
    const ll mod1 = 1e9+7;
    const ll P2 = 13331;
    const ll mod2 = 1e9+9;
    vector<ll> h1,p1,h2,p2;
    RollingHash(string s){
        int n = s.length();
        h1.resize(n+1, 0);
        p1.resize(n+1, 1);
        h2.resize(n+1, 0);
        p2.resize(n+1, 1);
        for (int i=0;i<n; i++) {
            h1[i+1] = (h1[i]*P1+s[i])%mod1;
            p1[i+1] = (p1[i]*P1)%mod1;

            h2[i+1] = (h2[i]*P2+s[i])%mod2;
            p2[i+1] = (p2[i]*P2)%mod2;
        }
    }
    pair<ll,ll> get(int l,int r){
        ll raw1 = h1[r+1]-(h1[l]*p1[r-l+1])%mod1;
        ll res1 = (raw1%mod1+mod1)%mod1;
        ll raw2 = h2[r+1]-(h2[l]*p2[r-l+1])%mod2;
        ll res2 = (raw2%mod2+mod2)%mod2;
        return {res1,res2};
    }
};

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const ll mod = 998244353;
void solve(){
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    for(int L=1;L<=19;L++){
        ll low = 1;
        for(int i=0;i<L-1;i++) low*=10;
        ll top = 0;
        if(L<19){ 
            top = low*10-1;
        }
        else{
            if(low<n) break;
            top = n;
        }
        top = min(n,top);
        if(low>top) break;
        ll rem = 1;
        for(int i=0;i<L;i++) rem = (rem*10)%m;
        ll d = gcd((rem-1+m)%m,m);
        ll x = n/(m/d);
        ll y = top-low+1;
        x%=mod,y%=mod;
        ans = (ans+(x*y)%mod) % mod;
    }
    cout << ans%mod << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}
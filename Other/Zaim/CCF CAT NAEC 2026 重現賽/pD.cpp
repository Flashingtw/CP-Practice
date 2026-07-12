#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

ll f(ll x){
    return (x|(x<<1));
}   
void solve(){
    ll a;
    cin>>a;
    ll ans=0;
    for(int i=0;i<61;i++){
        if((a>>i)&1){
            if((a>>(i+1))&1){
                ans|=(1LL<<i);
            }
        }
    }
    if(f(ans)==a) cout << ans << '\n';
    else cout << -1 << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}
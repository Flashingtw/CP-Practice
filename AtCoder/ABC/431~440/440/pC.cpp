#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n,w;
    cin>>n>>w;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    vector<ll> diff(2*w+1,0);

    for(int i=1;i<=n;i++){
        int L = (-i%(2*w)+2*w)%(2*w);
        int R = L+w-1;
        if(R<2*w){
            diff[L]+=v[i];
            diff[R+1]-=v[i];
        }
        else{
            diff[L]+=v[i];
            diff[2*w]-=v[i];
            diff[0]+=v[i];
            diff[R-2*w +1]-=v[i];
        }
    }
    ll ans=1e18;
    ll cur=0;
    for(int i=0;i<2*w;i++){
        cur+=diff[i];
        ans = min(ans,cur);
    }
    cout << ans << '\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
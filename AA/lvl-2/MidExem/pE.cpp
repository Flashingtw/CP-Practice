#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
ll n,q,k;

bool chk(ll tar){
    ll cnt=0;
    for(ll j=n;j>=1;j--){
        ll val = j*(j+1);
        ll mx = (tar-1)/val;
        if(mx>=n) break;
        cnt += n-mx;
        if(cnt>=k) return 1;
    }
    return 0;
}

void solve(){
    cin>>k;
    ll l=1,r=n*n*(n+1);
    ll ans;
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans << '\n';
}

int main(){
    cin>>n>>q;
    while(q--){
        solve();
    }
}
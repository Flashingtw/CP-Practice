#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

// (a1+a1+(n-1)*d)n/2 (2a1+(n-1)*d) * n /2
ll sum(ll n,ll a1,ll d){
    ll ans=0;
    ll an = a1+(n-1)*d;
    if(a1+(n-1)*d<0) {
        an-=d;
        ans+=an;
        n--;
    }
    ans += (a1+an)*n/2;
    return ans;
}
void solve(){
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> a(n),b(n);
    for(ll &i:a) cin>>i;
    for(ll &i:b) cin>>i;
    
    ll l=1,r=1e9+1,ans=0;
    while(l<=r){
        ll mid = l+ (r-l)/2;
        ll t=0,score=0;
        for(int i=0;i<n;i++){
            if(a[i]<mid) continue;
            t+=1+(a[i]-mid)/b[i];
            score+=sum(1+(a[i]-mid)/b[i],a[i],-b[i]);
        }
        if(t<=k){
            r = mid-1;
            ans = score+(k-t)*(mid-1);
        }
        else l = mid+1;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF = 1e9+9;
int n;
bool chk(ll d,vector<pll> &v){
    int curL=0;
    ll mxy=-1,mny=1e18;
    for(int i=0;i<n;i++){
        while(curL<n&&v[i].first-v[curL].first>=d){
            mxy = max(mxy,v[curL].second);
            mny = min(mny,v[curL].second);
            curL++;
        }
        if(curL>0&&max(abs(mxy-v[i].second),abs(mny-v[i].second))>=d) return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    vector<pll> v(n);
    for(auto &[a,b]:v) cin>>a>>b;
    sort(v.begin(),v.end());
    ll l=0,r=1e9,ans=-1;
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(mid,v)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans << '\n';
}
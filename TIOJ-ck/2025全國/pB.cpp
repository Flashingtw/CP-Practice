#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n,k;
pii aval[1000005];
int sz;
bool chk(ll m,vector<pii> &a){
    sz=0;
    int cnt = 0;
    int cur = 0;
    int l = 0;
    int r = 0;
    vector<int> vis(n);
    for (auto [x,s]:a) {
        while (r+1<n&&abs(a[r+1].first-x)<=m) r++;
        while (l<n&&abs(a[l].first-x)>m) {
            cur -= vis[l];
            l++;
        }
        int p = r;
        while (cur<=s&&p>=l) {
            if (sz>0&&aval[sz-1].second==p) {
                p = aval[sz-1].first;
                sz--;
                continue;
            }
            if (vis[p]) return 0;
            vis[p] = 1;
            cur += 1;
            cnt += 1;
            p--;
        }
        aval[sz++] = {p,r};
        if (cur <= s) return 0;
    }
    return cnt <= k;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>k;
    vector<pii> v(n);
    for(auto &[a,b]:v){
        cin>>a>>b;
    }
    sort(v.begin(),v.end());
    ll l=0,r=v.back().first-v.front().first,ans=0;
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(mid,v)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << '\n';
}
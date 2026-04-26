#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 1e9+9;
struct ev{
    ll t,a,b;
    bool operator<(ev ot){
        return t<ot.t;
    }
};
int main(){
    ll n,d;
    cin>>n>>d;
    vector<ev> v(n);
    vector<pii> oth(n);
    ll mx=0;
    for(int i=0;i<n;i++){
        cin>>v[i].t>>v[i].a>>v[i].b;
        oth[i] = {v[i].t,v[i].b};
        mx = max(mx,v[i].a+v[i].b);
    }

    sort(v.begin(),v.end());
    sort(oth.begin(),oth.end());

    vector<pii> pre(n);
    pre[0] = oth[0];
    for(int i=1;i<n;i++){
        pre[i] = {oth[i].first,max(oth[i].second,pre[i-1].second)};
    }

    for(auto [t,a,b]:v){
        ll tar = d-t;
        int idx = upper_bound(pre.begin(),pre.end(),make_pair(tar,(ll)2e18))-pre.begin();
        idx--;
        if(idx==-1) continue;
        mx = max(mx,a+pre[idx].second);
    }
    cout << mx << '\n';
}
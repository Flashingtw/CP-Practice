#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 1e9+9;
struct itm{
    ll w,v;
    bool operator<(itm oth){
        return v>oth.v;
    }
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    multiset<ll> pq;
    //priority_queue<ll> pq;
    for(int i=0;i<n;i++) {
        ll a;
        cin>>a;
        pq.insert(a);
    }
    vector<itm> a(m);
    for(auto &[w,v]:a) cin>>w>>v;
    sort(a.begin(),a.end());
    ll ans=0;
    for(auto [w,v]:a){
        auto it = pq.lower_bound(w);
        if(it==pq.end()) continue;
        pq.erase(it);
        ans+=v;
    }
    cout << ans << '\n';
}
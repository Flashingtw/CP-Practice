#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 1e9+9;
ll n;
struct ev{
    ll l,r,a;
    bool operator<(const ev &oth) const {
        return l<oth.l;
    }
};
bool chk(ll tar,vector<ev> &v){
    int j=0;
    priority_queue<pii,vector<pii>,greater<>> pq;
    for(int i=0;i<n;i++){
        while(j<n&&v[j].l<=i){
            pq.push({v[j].r,v[j].a});
            j++;
        } 
        ll cur=0;
        while(!pq.empty()&&cur<tar){
            auto [r,pass] = pq.top();pq.pop();
            ll take = min(pass,tar-cur);
            cur+=take;
            pass-=take;
            if(pass>0){
                pq.push({r,pass});
            }
        }
        if(!pq.empty()&&pq.top().first==i) return 0;
    }
    return pq.empty();
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    vector<ll> a(n),d(n);
    for(ll &i:a) cin>>i;
    for(ll &i:d) cin>>i;
    vector<ev> v(n);
    for(int i=0;i<n;i++){
        auto &[l,r,idx] = v[i];
        l = max(0LL,i-d[i]);
        r = min(n-1,i+d[i]);
        idx = a[i];
    }
    sort(v.begin(),v.end());
    ll l=0,r=1e18,ans=0;
    while(l<=r){
        ll mid = l+(r-l)/2;
        if(chk(mid,v)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int N = 5e5+5;
vector<pii> adj[N];
ll c[N];
ll m,n;
bool chk(ll tar){
    ll cur=tar;
    queue<pii> q;
    vector<bool> vis(n+1);
    q.push({1,cur});
    vis[1]=1;
    ll cnt=0;
    while(!q.empty()){
        auto [u,ct] = q.front();
        q.pop();
        if(ct<=0) continue;
        cnt++;
        for(auto &[v,d]:adj[u]){
            if(vis[v]) continue;
            q.push({v,min(ct,c[u])-d});
            vis[v]=1;
        }
    }
    return cnt<=m;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n-1;i++){
        ll u,v,d;
        cin>>u>>v>>d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    if(chk(c[1])){
        cout << -1 << '\n';
        return 0;
    }
    ll l = 0,r= c[1],ans=-1;
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(mid)){
            ans=mid;
            l = mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout << ans;
}
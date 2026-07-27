#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> cnt(n+1);
    vector<int> deg(n+1);
    vector<int> vis(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(u>v){
            cnt[v]++;
        }else{
            cnt[u]++;
        }
        // if(u>v) swap(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        // cnt[u]++;
        deg[u]++,deg[v]++;
    }
    cout << *max_element(cnt.begin(),cnt.end()) << ' ';

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=0;i<n;i++) pq.push({deg[i],i});
    int mx=-1;
    while(!pq.empty()){
        auto [dg,u] = pq.top();
        pq.pop();
        if(vis[u]||deg[u]!=dg) continue;
        vis[u]=1;
        mx = max(mx,dg);
        for(int v:adj[u]){
            if(vis[v]) continue;
            pq.push({--deg[v],v});
        }
    }
    cout << mx << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}
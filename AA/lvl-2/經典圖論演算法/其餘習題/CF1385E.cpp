#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<pii> edg;
    vector<int> deg(n+1);
    for(int i=0;i<m;i++){
        int t,u,v;
        cin>>t>>u>>v;
        if(t) adj[u].push_back(v),deg[v]++;
        else edg.push_back({u,v});
    }
    queue<int> q;
    for(int i=1;i<=n;i++) if(!deg[i]) q.push(i);
    int cur=0;
    vector<int> topo(n);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo[cur++]=u;
        for(int v:adj[u]){
            if(--deg[v]==0) q.push(v);
        }
    }
    if(cur<n) {
        cout << "NO" << '\n';
        return;
    }
    else cout << "YES" << '\n';
    vector<int> idx(n+1);
    for(int i=0;i<n;i++){
        idx[topo[i]]=i;
    }
    int sz = edg.size();
    for(int i=0;i<sz;i++){
        auto [a,b] = edg[i];
        if(idx[a]>idx[b]) swap(a,b);
        cout << a << ' ' << b << '\n';
    }
    for(int u=1;u<=n;u++){
        for(int v:adj[u]){
            cout << u << ' ' << v << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}
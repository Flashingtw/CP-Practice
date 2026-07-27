#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e5+5;
struct edg{
    int v;
    ll w;
};
int n;

vector<edg> adj[N];
//return farthest index
ll ans[N];
int bfs(int s){
    queue<int> q;
    q.push(s);
    vector<ll> dist(n+1);
    vector<int> vis(n+1);
    vis[s]=1;
    int idx=-1;
    ll mx=0;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        ans[u] = max(ans[u],dist[u]);
        if(dist[u]>mx){
            idx=u;
            mx = dist[u];
        }
        for(auto [v,w]:adj[u]){
            if(vis[v]) continue;
            q.push(v);
            dist[v] = dist[u]+w;
            vis[v]=1;
        }
    }
    return idx;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    bfs(bfs(bfs(1)));
    for(int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }
}
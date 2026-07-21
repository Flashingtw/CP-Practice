#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 4e5+5;
struct edg{
    int v;
    ll w;
};
vector<edg> adj[N];
int n;
ll ans[N][2];
int bfs(int s,int tp){
    int idx=-1;
    ll mx=0;
    vector<ll> dist(2*n+1,-1);
    queue<int> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(dist[u]>mx){
            idx = u;
            mx = dist[u];
        }
        ans[u][tp] = dist[u];
        for(auto [v,w]:adj[u]){
            if(dist[v]>=0) continue;
            q.push(v);
            dist[v] = dist[u]+w;
        }
    }
    return idx;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        ll c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    for(int i=1;i<=n;i++) {
        ll w;
        cin>>w;
        adj[i].push_back({i+n,w});
        adj[i+n].push_back({i,w});
    }
    bfs(bfs(bfs(1,0),0),1);
    for(int i=1;i<=n;i++){
        ll a = max(ans[i][0],ans[i][1]);
        if(adj[i+n][0].w==a) cout << min(ans[i][0],ans[i][1]) << '\n';
        else cout << a << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int N = 200005;
const ll INF = 1e18;
vector<pll> adj[N][2];
vector<vector<ll>> dist(N,vector<ll>(2,INF));

void dijkstra(int start,int t){
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,start});
    dist[start][t]=0;
    while(!pq.empty()){
        pll cur = pq.top();
        pq.pop();
        ll u = cur.second;
        if(cur.first>dist[u][t]) continue;
        for(pll &edg:adj[u][t]){
            ll v=edg.first;
            ll w=edg.second;
            if(dist[v][t]>dist[u][t]+w){
                dist[v][t]=dist[u][t]+w;
                pq.push({dist[u][t]+w,v});
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u][0].push_back({v,w});
        adj[v][1].push_back({u,w});
    }
    dijkstra(1,0);
    dijkstra(n,1);
    ll ans = INF;
    for(int i=1;i<=n;i++){
        if(adj[i][0].empty()) continue;
        for(pll ed : adj[i][0]){
            ans=min(ans,dist[i][0]+dist[ed.first][1]);
        }
    }
    cout << ans;
}

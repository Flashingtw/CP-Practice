#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll INF = 1e18+9;
const int N = 1e5+5;
vector<pii> adj[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    vector<ll> dist(n+1,INF);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if(d>dist[u]) continue;
        for(auto [v,c]:adj[u]){
            ll nxt = d+c;
            if(dist[v]>nxt){
                dist[v]=nxt;
                pq.push({nxt,v});
            }
        }
    }
    cout << dist[n];
}
#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long INF = 1e18;
using pii = pair<long long, int>;
vector<pii> adj[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    int start = 1;//anyone else
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,start});
    vector<long long> dist(n+1,INF);
    dist[start] =0;
    while(!pq.empty()){
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(d>dist[u]) continue;
        for(pii &edge:adj[u]){
            int v=edge.second;
            long long w= edge.first;
            if(dist[u]+w<dist[v]){
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}

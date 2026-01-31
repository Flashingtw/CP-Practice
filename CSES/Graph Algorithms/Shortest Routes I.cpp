#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18+9;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);//pair<pos,weight>
    for (int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<long long> dist(n+1,oo);
    dist[1] = 0;
    priority_queue<pair<long long,int>> pq;//pair<dist,pos>
    pq.push({0,1});
    while (!pq.empty()) {
        auto u = pq.top().second;
        long long d = -pq.top().first;
        pq.pop();
        if (d>dist[u]) continue;
        for (auto e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (dist[u]+w<dist[v]) {
                dist[v] = dist[u]+w;
                pq.push({-dist[v],v});
            }
        }
    }
    for (int i=1;i<=n;i++) {
        cout << dist[i] << " ";
    }
}
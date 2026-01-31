#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    long long total=0;
    vector<bool> visited(n+1,false);
    vector<int> dist(n+1,2e9);
    dist[1]=0;
    priority_queue<pair<int,int>> pq;//pair<dist,pos>
    pq.push({0,1});
    int cnt=0;
    while (!pq.empty()) {
        auto i = pq.top();
        pq.pop();
        int u = i.second;
        int cost = -i.first;
        if (visited[u]) continue;
        visited[u] = true;
        total+=cost;
        cnt++;
        for (auto e : adj[u]) {//edge u->v
            int v = e.first;//v
            int w = e.second;//w
            if (!visited[v]&&w<dist[v]) {//if u->v < original v
                dist[v]=w;
                pq.push({-w,v});
            }
        }
    }
    if (cnt==n) cout << total;
    else cout << "IMPOSSIBLE";
}
#include <bits/stdc++.h>
using namespace std;
#define oo 1000000000
int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    for (int i=0;i<m;i++) {
        int u,v,t;
        cin>>u>>v>>t;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    int source=0;
    int d[n],parents[n];//d存距離,parents存從何來
    for (int i=0;i<n;i++) d[i]=oo;
    for (int i=0;i<n;i++) parents[i]=-1;
    priority_queue<pair<int,int>> pq;
    //first distance second Number
    pq.push({d[source]=0,0});
    vector<bool> done(n,false);
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        if (done[v]) continue;
        done[v] = true;
        for (auto e : adj[v]) {//adj first is neighbor second is distance
            int u=e.first,w=e.second;
            if (d[v]+w<d[u]) {//u Start->w the shortest distance
                d[u] = d[v]+w;
                parents[u] = v;
                pq.push({-d[u],u}); //pq first is distance second is number
            }
        }
    }
    int maxd=-1, cnt=0;
    for (int i=0;i<n;i++) {
        if (d[i]<oo) maxd= max(d[i],maxd);
        else cnt++;
    }
    cout << maxd << "\n" << cnt;
}
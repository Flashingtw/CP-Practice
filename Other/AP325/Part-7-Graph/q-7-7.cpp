#include <bits/stdc++.h>
using namespace std;
#define N 10005
long long es[N],rem[N];
int main() {
    //Input
    int n,m;
    cin>>n>>m;
    vector<int> w(n+1);
    for (int i=1;i<=n;i++) cin>>w[i];
    vector<int> adj[N],indeg(N,0);//indeg,adj
    for (int i=0;i<m;i++) {
        int from,to;
        cin>>from>>to;
        adj[from].push_back(to);// from -> to
        indeg[to]++; // ->+1 to
    }
    queue<int> q;
    for (int i=1;i<=n;i++) {
        if (indeg[i]==0) {
            es[i]=0;
            q.push(i);
        }
    }
    vector<int> topo;
    long long total_time=0;
    //topo sort
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        topo.push_back(i);
        long long final_time = es[i]+w[i];
        total_time = max(total_time,final_time);
        for (int v : adj[i]) {//->
            es[v] = max(es[v],es[i]+w[i]);
            if (--indeg[v]==0) q.push(v);
        }
    }
    for (int i=1;i<=n;i++) rem[i] = w[i];
    //reserve count rem
    for (int i=n;i>=0;i--) {
        int u = topo[i];
        for (int v : adj[u]) {
            rem[u] = max(rem[u],w[u]+rem[v]);
        }
    }
    cout << total_time << "\n";
    for (int i=1;i<=n;i++) {
        if (es[i]+rem[i]==total_time) cout << i << " ";
    }
}
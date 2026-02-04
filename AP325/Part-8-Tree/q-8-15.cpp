#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct edge {
    int to,w;
};
vector<edge> adj[N];
int hei[N],ans=0;
long long total_w = 0;
void dfs(int u,int p) {
    for (auto &e : adj[u]) {
        int v = e.to;
        int w = e.w;
        if (v==p) continue;
        dfs(v,u);
        ans = max(ans,hei[u]+hei[v]+w);
        hei[u] = max(hei[u],hei[v]+w);
    }
}
int main() {
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        total_w+=w;
    }
    dfs(0,-1);
    cout << (total_w*2)-ans;
}
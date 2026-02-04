#include <bits/stdc++.h>
#define N 50010
using namespace std;
vector<int> adj[N];
//parents,searching
vector<int> tour;
void dfs(int p,int v) {
    tour.push_back(v);
    for (int u : adj[v]) {
        if (u==p) continue;
        dfs(v,u);
        tour.push_back(v);
    }
}

int main() {
    int n;
    cin>>n;
    long long total=0;
    for (int i=0;i<n-1;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        total+=w;
    }
    for (int i=0;i<n;i++) sort(adj[i].begin(),adj[i].end());
    dfs(-1,0);
    cout << total*2 << "\n";
    for (int i=0;i<tour.size();i++) cout << tour[i] << " ";
}
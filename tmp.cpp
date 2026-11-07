#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
int n;
queue<int> a[1];
int ans=-1;
int bfs(int st){
    vector<int> vis(n);
    vector<int> dist(n);
    queue<int> q;
    vis[st]=1;
    q.push(st);
    int mx = -1;
    int idx = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(dist[u]>mx){
            mx = dist[u];
            idx = u;
        }
        for(int v:adj[u]){
            if(vis[v]) continue;
            vis[v]=1;
            q.push(v);
            dist[v]=dist[u]+1;
        }
    }
    ans = mx;
    return idx;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int idx = bfs(0);
    bfs(idx);
    cout << ans << '\n';
}
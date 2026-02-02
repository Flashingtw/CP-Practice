#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> adj[N];
bool vis[N];
void dfs(int u){
    vis[u]=true;
    for(int v:adj[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> res;
    for(int i=1;i<=n;i++){
        if(!vis[i]) {
            dfs(i);
            res.push_back(i);
        }
    }
    cout << res.size()-1 << "\n";
    for(int i=1;i<res.size();i++) cout << res[0] << " " << res[i] << "\n";
}
#include <bits/stdc++.h>
using namespace std;
const int N =200005;
const int LOG=20;
vector<int> adj[N];
int lca[N][LOG],dep[N],diff[N],ans[N];
int n,m;

void dfs(int u,int pa,int d){
    dep[u]=d;
    lca[u][0] = pa;
    for(int v:adj[u]){
        if(v==pa) continue;
        dfs(v,u,d+1);
    }
}
void dfs_diff(int u,int p){
    ans[u]=diff[u];
    for(int v:adj[u]){
        if(v==p) continue;
        dfs_diff(v,u);
        ans[u]+=ans[v];
    }
}
void lcabuild(){
    for(int j=1;j<LOG;j++){
        for(int i=1;i<=n;i++){
            if(lca[i][j-1]==0) continue;
            lca[i][j]=lca[lca[i][j-1]][j-1];
        }
    }
}
int find_lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=LOG-1;i>=0;i--){
        if(dep[lca[u][i]]>=dep[v]){
            u = lca[u][i];
        }
    }
    if(u==v) return u;
    for(int i=LOG-1;i>=0;i--){
        if(lca[u][i]!=lca[v][i]){
            u=lca[u][i];
            v=lca[v][i];
        }
    }
    return lca[u][0];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,1);
    lcabuild();
    while(m--){
        int u,v;
        cin>>u>>v;
        diff[u]++;
        diff[v]++;
        int lc = find_lca(u,v);
        diff[lc]--;
        diff[lca[lc][0]]--;
    }
    dfs_diff(1,0); 
    for(int i=1;i<=n;i++) cout << ans[i] << " ";  
}
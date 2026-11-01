#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<int> adj[N];
int a[N];
int vis[N],dp[N][2];
void dfs(int u){
    dp[u][1]+=a[u];
    for(int v:adj[u]){
        if(vis[v]) continue;
        vis[v]=1;
        dfs(v);
        dp[u][1] += min(dp[v][0],dp[v][1]);
        dp[u][0] += dp[v][1]; 
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis[1]=1;
    dfs(1);
    cout << min(dp[1][0],dp[1][1]) << '\n';
}
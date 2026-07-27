#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<int> adj[N];
int w[N],dp[N];
int ans=0;
int dfs(int u,int p) {
    dp[u] = w[u];
    for (int v : adj[u]) {
        if (v==p) continue;
        int st = dfs(v,u);
        dp[u] += max(st,0);
    }
    ans = max(ans,dp[u]);
    return dp[u];
}
int main() {
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define oo 1e18
vector<int> adj[N];
int n;
int w[N];

long long dp[N][3];
//[i][0] i build itself
//[i][2] i got father cover
//[i][1] i got child cover
void dfs(int u, int p) {
    dp[u][0] = w[u];
    dp[u][1] = oo;
    dp[u][2] = 0;
    for (int v : adj[u]) {
        if (v==p) continue;
        dfs(v,u);
        dp[u][0] += min({dp[v][0], dp[v][1], dp[v][2]});
        dp[u][2] += min(dp[v][0],dp[v][1]);//v's father can't help
        long long cost = min(dp[v][0],dp[v][1]);
        dp[u][1] = min(dp[u][1],dp[v][0]-cost);
    }
    //all can't help father
    //dp[u][1] mean the min cost to help father
    dp[u][1]+=dp[u][2];
}

int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    cout << min(dp[1][0],dp[1][1]);
}
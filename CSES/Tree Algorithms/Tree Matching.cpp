#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
vector<int> adj[N];
int dp[N][2];
void dfs(int u,int p) {
    dp[u][0] = 0;
    dp[u][1] = 0;//initialize
    for (int v : adj[u]) {
        if (v==p) continue;
        dfs(v,u);
    }
    for (int v : adj[u]) {
        if (v==p) continue;
        dp[u][0] += max(dp[v][0],dp[v][1]);
    }
    for (int v : adj[u]) {
        if (v==p) continue;
        int val = (dp[u][0] - max(dp[v][0],dp[v][1]))+dp[v][0]+1;//(差值+原值+1(連起來了))
        dp[u][1] = max(dp[u][1],val);
    }
}
int main() {
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout << max(dp[1][0],dp[1][1]);
}
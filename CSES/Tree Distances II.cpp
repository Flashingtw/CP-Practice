#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> adj[N];
int n;
long long ans[N];

int dp[N];
void dfs1(int u,int p,int depth) {
    dp[u]=1;
    ans[1] += depth;//count 1'sans depth
    for (int v : adj[u]) {
        if (v!=p) {
            dfs1(v,u,depth+1);
            dp[u]+=dp[v];
        }
    }
}
void dfs2(int u,int p) {
    for (int v : adj[u]) {
        if (v!=p) {
            ans[v] = ans[u] + n - 2*dp[v];
            dfs2(v,u);
        }
    }
}
int main() {
    cin>>n;
    for (int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,0,0);

    dfs2(1,0);
    for (int i=1;i<=n;i++) cout << ans[i] << ' ';
}
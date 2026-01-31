#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define M 100
#define INF 1e9
vector<int> adj[N];
string s[N];
int n,m;
int dp[N][4];

int get_idx(char c) {
    if (c == 'A') return 0;
    if (c == 'U') return 1;
    if (c == 'G') return 2;
    if (c == 'C') return 3;
    return -1;//@
}

void dfs(int u,int col) {
    char c = s[u][col];
    int fixed = get_idx(c);
    for (int i=0;i<4;i++) {
        if (fixed != -1&& i != fixed) {
            dp[u][i]=INF;
        }
        else {
            dp[u][i]=0;
        }
    }
    for (int v : adj[u]) {
        dfs(v,col);
        int min_v = min({dp[v][0], dp[v][1], dp[v][2], dp[v][3]});
        for (int i=0;i<4;i++) {
            if (dp[u][i] == INF) continue;
            dp[u][i] += min(dp[v][i],min_v+1);
        }
    }
}

int main() {
    cin>>n>>m;
    int root=0;
    for (int c=0;c<n;c++) {
        int i,j;
        cin>>i>>j>>s[i];
        if (i==j) {
            root = i;
            continue;
        }
        adj[j].push_back(i);
    }
    long long ans=0;
    for (int k=0;k<m;k++) {
        dfs(root,k);
        ans+=min({dp[root][0],dp[root][1],dp[root][2],dp[root][3]});
    }
    cout << ans;
}
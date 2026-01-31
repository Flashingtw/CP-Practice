#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int LOG = 20;
vector<int> adj[N];
int up[N][LOG];
int depth[N];
int n,q;
void dfs(int u,int p,int d) {
    depth[u] = d;
    up[u][0] = p;
    for (int v : adj[u]) {
        dfs(v,u,d+1);
    }
}
void build() {
    for (int j=1;j<LOG;j++) {
        for (int i=1;i<=n;i++) {
            int half = up[i][j-1];
            if (half==0) up[i][j] = 0;
            else up[i][j] = up[half][j-1];
        }
    }
}
int query(int a,int b) {
    if (depth[a]<depth[b]) swap(a,b);
    int k = depth[a]-depth[b];
    for (int j=0;j<LOG;j++) {
        if (k>>j&1) a = up[a][j];
    }
    if (a==b) return a;
    //兩個一起
    for (int j=LOG-1;j>=0;j--) {
        if (up[a][j]!=up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>q;
    for (int i=2;i<=n;i++) {
        int boss;
        cin>>boss;
        adj[boss].push_back(i);
    }
    dfs(1,0,0);
    build();
    while (q--) {
        int a,b;
        cin>>a>>b;
        cout << query(a,b) << "\n";
    }
}
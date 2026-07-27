#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<int> child[N];
int ans=0,h[N];
void dfs(int u) {
    for (int v : child[u]) {
        dfs(v);
        ans = max(ans,h[u]+h[v]+1);
        h[u] = max(h[u],h[v]+1);
    }
}
int main() {
    int n;
    cin>>n;
    int p[N];
    fill(p,p+n,-1);
    for (int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        child[a].push_back(b);
        p[b] = a;
    }
    int root=0;
    for (root=0;root<n;root++) if (p[root]==-1) break;
    dfs(root);
    cout << ans;
}
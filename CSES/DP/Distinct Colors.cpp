#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> adj[N];
int sz[N],heavy_child[N];
int color[N];
int in[N],out[N],ver[N],timer=0;

int ans[N],cnt[N],distinct_c=0;
void add(int idx) {
    int c = color[idx];
    if (cnt[c]==0) distinct_c++;
    cnt[c]++;
}
void remove(int idx) {
    int c = color[idx];
    cnt[c]--;
    if (cnt[c]==0) distinct_c--;
}
void dfs(int u,int p) {
    in[u]=++timer;
    ver[timer] = u;
    int max_sz=0,total_sz=0;
    for (int v:adj[u]) {
        if (v==p) continue;
        dfs(v,u);
        total_sz+=sz[v];
        if (sz[v]>max_sz) {
            heavy_child[u]=v;
            max_sz=sz[v];
        }
    }
    sz[u] = total_sz+1;
    out[u]=timer;
}
void dfs(int u,int p,int keep) {
    for (int v:adj[u]) {
        if (v==p||heavy_child[u]==v) continue;
        dfs(v,u,0);
    }
    if (heavy_child[u]) dfs(heavy_child[u],u,1);
    //cnt have heavy child's data
    for (int v:adj[u]) {
        if (v==p||heavy_child[u]==v) continue;
        for (int t=in[v];t<=out[v];t++) {
            add(ver[t]);
        }
    }
    add(u);
    ans[u] = distinct_c; //紀錄u裡面所包含的所有輕子樹答案
    if (!keep) {
        for (int t=in[u];t<=out[u];t++) {
            remove(ver[t]);
        }
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> o_c(n+1);
    vector<int> c(n+1);
    for (int i=1;i<=n;i++) {
        cin>>o_c[i];
        c[i] = o_c[i];
    }
    for (int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    for (int i=1;i<=n;i++) color[i] = lower_bound(c.begin(),c.end(),o_c[i])-c.begin();
    dfs(1,0);
    dfs(1,0,1);
    for (int i=1;i<=n;i++) cout << ans[i] << " ";
}
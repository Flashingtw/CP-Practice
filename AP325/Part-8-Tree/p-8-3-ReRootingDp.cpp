#include <bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
struct edge {
    int to;
    int weight;
};
vector<edge> adj[N];//adj graph
ll sz[N];//size of i's subtree
ll ans[N];//chose i's total dis
ll dist_to_root[N];//i to 0 dis
int n;
//use to compute size and distance
void dfs1(int u,int p,ll d) {
    sz[u]=1;
    dist_to_root[u] = d;
    for (edge &ed : adj[u]) {
        int v = ed.to;
        int w = ed.weight;
        if (v==p) continue;
        dfs1(v,u,d+w);
        sz[u]+=sz[v];
    }
}
void dfs2(int u,int p) {
    for (auto& ed : adj[u]) {
        int v = ed.to;
        int w = ed.weight;
        if (v==p) continue;
        ans[v] = ans[u]+(ll)w * (n-2*sz[v]);
        dfs2(v,u);
    }
}
int main() {
    cin>>n;
    //make tree
    for (int i=1;i<n;i++) {
        int p,w;
        cin>>p>>w;
        adj[i].push_back({p,w});
        adj[p].push_back({i,w});
    }
    dfs1(0,-1,0);
    ans[0] = 0;
    for(int i=0; i<n; i++) ans[0] += dist_to_root[i];
    dfs2(0,-1);
    ll min_val = ans[0];
    int best_id = 0;
    for (int i=1;i<n;i++) {
        if (ans[i]<min_val) {
            best_id = i;
            min_val = ans[i];
        }
        else if (ans[i]==min_val&&dist_to_root[i] > dist_to_root[best_id]) {
            best_id = i;
        }
    }
    cout << best_id << "\n" << min_val;
}
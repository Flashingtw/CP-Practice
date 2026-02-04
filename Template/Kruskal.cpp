#include <bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int> p;
    vector<int> sz;
    DSU(int x) {
        p.resize(x+1);
        sz.resize(x+1,1);
        iota(p.begin(),p.end(),0);
    }
    int find(int x){
        if(x==p[x]) return x;
        return p[x] = find(p[x]);
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    void unite(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX==rootY) return;
        if(sz[rootX]<sz[rootY]) swap(rootX,rootY);
        p[rootY] = rootX;
        sz[rootX] += sz[rootY];
    }
};
struct EDGE{
    int u,v,w;
};
const int N = 200005;
int main(){
    int n,m;//n node m edge
    cin>>n>>m;
    vector<EDGE> edges(m);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i] = {u,v,w};
    }
    DSU dsu(n);
    sort(edges.begin(), edges.end(),[](EDGE a,EDGE b){
         return a.w<b.w;
         });
    vector<int> adj[N];
    long long total=0;
    for(auto &e : edges){
        int u=e.u,v=e.v,w=e.w;
        if(dsu.same(u,v)) continue;
        dsu.unite(u,v);
        total+=w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        }
    cout << total;
}

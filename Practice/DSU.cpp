#include <bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int> p;
    vector<int> sz;
    void init(int x){
        p.resize(x+1);
        iota(p.begin(),p.end(),0);
        sz.assign(x+1,1);
    }
    int find(int x){
        if(p[x]==x) return x;
        return p[x] = find(p[x]);
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
struct WeightedDSU{
    vector<int> p;
    vector<int> d;
    void init(int x){
        p.resize(x+1);
        iota(p.begin(),p.end(),0);
        d.assign(x+1,0);
    }
    int find(int x){
        if(p[x]==x) return x;
        int root = find(p[x]);
        d[x]+=d[p[x]];
        return p[x] = root;
    }
    void unite(int u,int v,int w){
        int rootu = find(u);
        int rootv = find(v);
        if(rootu==rootv) return;
        p[rootu] = rootv;
        d[rootu] = w-d[u]+d[v];
    }
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    DSU dsu;
    dsu.init(n);
    while(m--){
        int type;
        cin>>type;
        if(type==1){
            int u,v;
            cin>>u>>v;
            dsu.unite(u,v);
        }
        else{
            int u;
            cin>>u;
            cout << dsu.sz[dsu.find(u)] << "\n";
        }
    }
}

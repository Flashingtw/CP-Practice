//DSU and Kruskal
#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> p;
    DSU(int n) {
        p.resize(n+1);
        iota(p.begin(),p.end(),0);
    }
    int find(int x) {
        if (p[x]==x) return x;
        return p[x] = find(p[x]);
    }
    void unite(int x,int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX!=rootY) {
            p[rootX] = rootY;
        }
    }
};
struct EDGE {
    int u,v,w;
};
int main() {
    int n,m;
    cin>>n>>m;
    vector<EDGE> ed(m);
    for (int i=0;i<m;i++) {
        cin>>ed[i].u>>ed[i].v>>ed[i].w;
    }
    sort(ed.begin(),ed.end(),
        [&](EDGE &a,EDGE &b) {return a.w<b.w;});
    DSU dsu(n);
    long long total=0;
    int cnt=0;//edge's num
    for (auto &e : ed) {
        int u = e.u;
        int v = e.v;
        if (dsu.find(u)!=dsu.find(v)) {
            total +=e.w;
            cnt++;
            dsu.unite(u,v);
        }
    }
    if (cnt==n-1) {
        cout << total;
        return 0;
    }
    cout << "IMPOSSIBLE";
}
#include <bits/stdc++.h>
using namespace std;
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
    WeightedDSU dsu;
    dsu.init(n);
    while(m--){
        int type;
        cin>>type;
        if(type==1){
            int u,v,w;
            cin>>u>>v>>w;
            dsu.unite(u,v,w);
        }
        else{
            int u,v;
            cin>>u>>v;
            if(dsu.find(u)!=dsu.find(v)){
                cout << "?" << "\n";
            }
            else{
                cout << dsu.d[u]-dsu.d[v] << "\n";
            }
        }
    }
}

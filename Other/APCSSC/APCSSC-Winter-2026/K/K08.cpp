#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int> p;
    vector<int> sz;
    int max_sz=1;
    DSU(int x){
        p.resize(x+1);
        sz.resize(x+1,1);
        iota(p.begin(),p.end(),0);
    }
    int find(int x){
        if(x==p[x]) return x;
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
int main(){
    int n,m1,m2;
    cin>>n>>m1>>m2;
    DSU dsu_old(n),dsu_new(n);
    for(int i=0;i<m1;i++){
        int u,v;
        cin>>u>>v;
        dsu_old.unite(u,v);
    }
    for(int i=0;i<m2;i++){
        int u,v;
        cin>>u>>v;
        dsu_new.unite(u,v);
    }
    vector<pair<int,int>> v(n+1);
    map<pair<int,int>,int> mp;
    for(int i=1;i<=n;i++){
        v[i]={dsu_old.find(i),dsu_new.find(i)};
        mp[v[i]]++;
    }
    for(int i=1;i<=n;i++) cout << mp[v[i]] << " ";
}

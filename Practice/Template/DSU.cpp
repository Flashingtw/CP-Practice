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

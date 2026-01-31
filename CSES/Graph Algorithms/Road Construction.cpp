#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> p;
    vector<int> sz;
    int M_sz;
    int M_c;
    DSU(int n) {
        p.resize(n+1);
        sz.resize(n+1);
        iota(p.begin(),p.end(),0);
        fill(sz.begin(),sz.end(),1);
        M_sz = 1;
        M_c = n;
    }
    int find(int x) {
        if (p[x]==x) return x;
        return p[x] = find(p[x]);
    }
    bool unite(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if (rootX==rootY) return false;
        M_c--;
        sz[rootX] += sz[rootY];
        p[rootY] = rootX;
        M_sz = max(M_sz,sz[rootX]);
        return true;
    }
};
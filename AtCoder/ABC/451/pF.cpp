#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct WeightedDSU{
    vector<int> p;
    vector<int> d;
    vector<int> sz0,sz1;
    void init(int x){
        p.resize(x+1);
        sz0.resize(x+1,1);
        sz1.resize(x+1,0);
        iota(p.begin(),p.end(),0);
        d.assign(x+1,0);
    }
    int find(int x){
        if(p[x]==x) return x;
        int root = find(p[x]);
        d[x]^=d[p[x]];
        return p[x] = root;
    }
    void unite(int u,int v){
        int rootu = find(u);
        int rootv = find(v);
        p[rootu]=rootv;
        d[rootu]=d[u]^d[v]^1;
        if(d[rootu]==0){
            sz0[rootv] += sz0[rootu];
            sz1[rootv] += sz1[rootu];
        }
        else{
            sz0[rootv]+=sz1[rootu];
            sz1[rootv]+=sz0[rootu];
        }
    }
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    WeightedDSU dsu;
    dsu.init(n);
    int ans=0;
    bool chk=1;
    while(m--){
        int u,v;
        cin>>u>>v;
        if(!chk){
            cout << -1 << '\n';
            continue;
        }
        int rv = dsu.find(v);
        int ru = dsu.find(u);
        if(rv==ru){
            if(dsu.d[u]==dsu.d[v]){
                chk=0;
                cout << -1 << '\n';
                continue;
            }
        }
        else{
            ans -= min(dsu.sz0[ru],dsu.sz1[ru]);
            ans -= min(dsu.sz0[rv],dsu.sz1[rv]);
            dsu.unite(u,v);
            ans+= min(dsu.sz0[rv],dsu.sz1[rv]);
        }
        cout << ans << '\n';
    }
}

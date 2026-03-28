#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
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
struct edge{
    int u,v,d;
    bool operator<(edge o){
        return d>o.d;
    }
};
vector<pii> adj[3005];

int grid[3005][3005];

int main(){
    int n;
    cin>>n;
    vector<edge> ed;
    for(int u=1;u<=n;u++){
        for(int v=u+1;v<=n;v++){
            cin>>grid[u][v];
            grid[v][u]=grid[u][v];
            ed.push_back({u,v,grid[u][v]});
        }
    }
    DSU dsu(n);
    sort(ed.begin(), ed.end(),[](edge a,edge b){return a.d<b.d;});
    long long total=0;
    for(auto &e:ed){
        int u=e.u,v=e.v,w=e.d;
        if(dsu.same(u,v)) continue;
        dsu.unite(u,v);
        total+=w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++){
        vector<int> dist(n+1,-1);
        queue<pii> q;
        dist[i]=0;
        q.push({i,0}); 
        while(!q.empty()){
            auto [u,d] = q.front();
            q.pop();
            for(auto &[v,c]:adj[u]){
                if(dist[v]!=-1) continue;
                q.push({v,d+c});
                dist[v] = d+c;
            }
        }
        bool chk=1;
        for(int v=1;v<=n;v++){
            if(grid[i][v]!=dist[v]){
                chk=0;
            }
        }
        if(!chk){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
} 
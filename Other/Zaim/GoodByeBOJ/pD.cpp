#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 100005;

struct edg{
    ll u,v,d,id;
    bool operator<(edg ot){
        return d<ot.d;
    }
};

vector<pii> adj[N];

struct DSU{
    int sz;
    vector<int> p;
    DSU(int _sz) : sz(_sz+1), p(_sz+1) {
        iota(p.begin(),p.end(),0);    
    };
    int find(int x){
        if(p[x]==x) return x;
        return p[x] = find(p[x]);
    }
    bool chk(int x,int y){
        return (find(x)==find(y));
    }
    void merge(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX==rootY) return;
        p[rootY] = rootX;
    }
};
int main(){
    cout << "NO" << '\n';
    int n,m;
    cin>>n>>m;
    vector<edg> edge;
    for(int i=0;i<m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
        edge.push_back({u,v,d,i+1});
    }
    sort(edge.begin(),edge.end());
    vector<edg> mst;
    ll mst_sum=0,b=0;
    DSU dsu(n);
    for(int i=0;i<m;i++){
        auto [u,v,d,id] = edge[i];
        if(!dsu.chk(u,v)){
            dsu.merge(u,v);
            mst.push_back(edge[i]);
            mst_sum+=d;
            b = max(b,d);
        }
    }
    vector<edg> can_use;
    for(int i=0;i<m;i++){
        auto [u,v,d,id] = edge[i];
        if(d<=b) can_use.push_back(edge[i]);
    }
    int cnt=0;
    vector<edg> mbst;
    ll mbst_sum=0;
    int sz = can_use.size();
    reverse(can_use.begin(),can_use.end());
    DSU dsu1(n);
    for(int i=0;i<sz;i++){
        auto [u,v,d,id] = can_use[i];
        if(!dsu1.chk(u,v)){
            dsu1.merge(u,v);
            mbst.push_back(can_use[i]);
            mbst_sum+=d;
            cnt++;
        }
    }
    if(mbst_sum>mst_sum){
        cout << "YES\n";
        for(auto [u,v,d,id]:mbst){
            cout << id << '\n';
        }
    }
    else cout << "NO\n";
}
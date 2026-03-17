#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
struct DSU{
    int sz;
    vector<int> p,s;
    DSU (int _sz){
        sz = _sz;
        p.resize(_sz+1,0);
        s.resize(_sz+1,1);
        iota(p.begin(),p.end(),0);
    }
    int find(int x){
        if(p[x]==x) return x;
        return p[x]=find(p[x]);
    }
    void unite(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX==rootY) return;
        if(s[rootY]>s[rootX]) swap(rootX,rootY);
        p[rootY]=rootX;
        s[rootX]+=s[rootY];
    }
    bool chk(int x,int y){
        return find(x)==find(y);
    }
};
struct EDGE{
    int v,id;
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pii> edge,all;
    vector<vector<EDGE>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        all.push_back({u,v});
    }
    vector<bool> in_tree(m,0),vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto [v,id]:adj[u]){
                    if(!vis[v]){
                        vis[v]=1;
                        in_tree[id]=1;
                        q.push(v);
                    }
                }
            }
        }
    }
    DSU color(n);
    for(int i=0;i<m;i++){
        if(!in_tree[i]){
            auto [u,v] = all[i];
            color.unite(u,v);
        }
    }
    vector<int> a,b,c,col(n+1,-1);
    int cnt=0;
    for(int i=1;i<=n;i++){
        int root = color.find(i);
        if(col[root]==-1){
            col[root]=cnt%3;
            cnt++;
        }
        col[i]=col[root];
    }   
    for(int i=1;i<=n;i++){
        if(col[i]==0) a.push_back(i);
        if(col[i]==1) b.push_back(i);
        if(col[i]==2) c.push_back(i);
    }
    
    cout << a.size() << ' ';
    for(int i:a) cout << i << ' ';
    cout << '\n' << b.size() << ' ';
    for(int i:b) cout << i << ' ';
    cout << '\n' << c.size() << ' ';
    for(int i:c) cout << i << ' ';
    cout << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}

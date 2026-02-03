#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef long long ll;
vector<int> adj[N];
int n,q;
ll val[N];

int in[N],out[N],timer;
ll tree[N];

void update(int idx,ll v){
    for(;idx<=N;idx+=idx&-idx) tree[idx]+=v;
}

ll query(int idx){
    ll s=0;
    for(;idx>0;idx-=idx&-idx) s+=tree[idx];
    return s;
}

void dfs(int u,int p){
    in[u]=++timer;
    for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    out[u]=timer;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        update(in[i],val[i]);
        update(out[i]+1,-val[i]);
    }
    while(q--){
        int type,u;
        cin>>type>>u;
        if(type==1){
            int x;
            cin>>x;
            ll diff = x-val[u];
            val[u]=x;
            update(in[u],diff);
            update(out[u]+1,-diff);
        }
        else cout << query(in[u]) << "\n";
    }
}
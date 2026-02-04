#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

vector<int> adj[N];
int sz[N],depth[N],p[N],son[N];
int top[N],rnk[N],dfn[N];
int n;
void dfs1(int u,int pa,int d){
    p[u]=pa;
    depth[u]=d;
    sz[u]=1;
    son[u]=-1;
    int max_sz=-1;
    for(int v:adj[u]){
        if(v==pa) continue;
        dfs1(v,u,d+1);
        sz[u]+=sz[v];
        if(sz[v]>max_sz){
            max_sz=sz[v];
            son[u]=v;
        }
    }
}
int timer;
void dfs2(int u,int t){
    dfn[u]=++timer;
    top[u]=t;
    rnk[timer]=u;
    if(son[u]==-1) return;
    //run light son
    dfs2(son[u],t);
    for(int v:adj[u]){
        if(v==son[u]||v==p[u]) continue;
        dfs2(v,v);
    }
}
int tree[4*N],node_val[N];
void pull(int idx) {
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}
void build(int idx,int l,int r){
    if(l==r){
        tree[idx]=node_val[rnk[l]];
        return;
    }
    int mid = (l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    pull(idx);
}
void update(int idx,int l,int r,int pos,int num){
    if(l==r){
        tree[idx]=num;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid) update(idx*2,l,mid,pos,num);
    else update(idx*2+1,mid+1,r,pos,num);
    pull(idx);
}
int query(int idx,int l,int r,int ql,int qr){
    if(qr<l||r<ql) return 0;
    if(ql<=l&&r<=qr) return tree[idx];
    int mid=(l+r)/2;
    return query(idx*2,l,mid,ql,qr)+query(idx*2+1,mid+1,r,ql,qr);
}
void update_node(int u,int value){
    update(1,0,n,dfn[u],value);
}
int query_path(int u,int v){
    int ans=0;
    while(top[u]!=top[v]){
        if(depth[top[u]]<depth[top[v]]) swap(u,v);
        ans += query(1,0,n,dfn[top[u]],dfn[u]);
        u = p[top[u]];
    }
    if(depth[u]>depth[v]) swap(u,v);
    return ans+query(1,0,n,dfn[u],dfn[v]);
}

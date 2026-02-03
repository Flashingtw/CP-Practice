#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma G++ optimize(1)
#pragma G++ optimize(2)
#pragma G++ optimize(3)
#pragma G++ optimize("Ofast")
#pragma G++ optimize("inline")
#pragma G++ optimize("-fgcse")
#pragma G++ optimize("-fgcse-lm")
#pragma G++ optimize("-fipa-sra")
#pragma G++ optimize("-ftree-pre")
#pragma G++ optimize("-ftree-vrp")
#pragma G++ optimize("-fpeephole2")
#pragma G++ optimize("-ffast-math")
#pragma G++ optimize("-fsched-spec")
#pragma G++ optimize("unroll-loops")
#pragma G++ optimize("-falign-jumps")
#pragma G++ optimize("-falign-loops")
#pragma G++ optimize("-falign-labels")
#pragma G++ optimize("-fdevirtualize")
#pragma G++ optimize("-fcaller-saves")
#pragma G++ optimize("-fcrossjumping")
#pragma G++ optimize("-fthread-jumps")
#pragma G++ optimize("-funroll-loops")
#pragma G++ optimize("-fwhole-program")
#pragma G++ optimize("-freorder-blocks")
#pragma G++ optimize("-fschedule-insns")
#pragma G++ optimize("inline-functions")
#pragma G++ optimize("-ftree-tail-merge")
#pragma G++ optimize("-fschedule-insns2")
#pragma G++ optimize("-fstrict-aliasing")
#pragma G++ optimize("-fstrict-overflow")
#pragma G++ optimize("-falign-functions")
#pragma G++ optimize("-fcse-skip-blocks")
#pragma G++ optimize("-fcse-follow-jumps")
#pragma G++ optimize("-fsched-interblock")
#pragma G++ optimize("-fpartial-inlining")
#pragma G++ optimize("no-stack-protector")
#pragma G++ optimize("-freorder-functions")
#pragma G++ optimize("-findirect-inlining")
#pragma G++ optimize("-frerun-cse-after-loop")
#pragma G++ optimize("inline-small-functions")
#pragma G++ optimize("-finline-small-functions")
#pragma G++ optimize("-ftree-switch-conversion")
#pragma G++ optimize("-foptimize-sibling-calls")
#pragma G++ optimize("-fexpensive-optimizations")
#pragma G++ optimize("-funsafe-loop-optimizations")
#pragma G++ optimize("inline-functions-called-once")
#pragma G++ optimize("-fdelete-null-pointer-checks")

#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef long long ll;
vector<int> adj[N];
int val[N];
int sz[N],dep[N],p[N],dfn[N],rnk[N],top[N],hev[N];
int timer;
int n,q;
void dfs1(int u,int pa,int d){
    p[u]=pa;
    dep[u]=d;
    sz[u]=1;
    hev[u]=-1;
    int max_sz=-1;
    for(int v:adj[u]){
        if(v==pa) continue;
        dfs1(v,u,d+1);
        sz[u]+=sz[v];
        if(sz[v]>max_sz){
            max_sz=sz[v];
            hev[u]=v;
        }
    }
}
void dfs2(int u,int t){
    top[u]=t;
    dfn[u]=++timer;
    rnk[timer]=u;
    if(hev[u]!=-1){
        dfs2(hev[u],t);
    }
    for(int v:adj[u]){
        if(v==p[u]||v==hev[u]) continue;
        dfs2(v,v);
    }
}

ll tree[4*N];
void pull(int idx){
    tree[idx]=max(tree[idx*2],tree[idx*2+1]);
}
void build(int idx,int l,int r){
    if(l==r){
        tree[idx] = val[rnk[l]];
        return;
    }
    int mid = (l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    pull(idx);
}
void update(int idx,int l,int r,int pos,int va){
    if(l==r){
        tree[idx] = va;
        return;
    }
    int mid = (l+r)/2;
    if (pos <= mid) update(idx * 2, l, mid, pos, va);
    else update(idx * 2 + 1, mid + 1, r, pos, va);
    pull(idx);
}
ll query(int idx,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr) return tree[idx];
    int mid = (l+r)/2;
    ll res=0;
    if (ql <= mid) res = max(res, query(idx * 2, l, mid, ql, qr));
    if (qr > mid) res = max(res, query(idx * 2 + 1, mid + 1, r, ql, qr));
    return res;
}
ll query_path(int u,int v){
    ll res=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res = max(res,query(1,1,n,dfn[top[u]],dfn[u]));
        u = p[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    res = max(res,query(1,1,n,dfn[u],dfn[v]));
    return res;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,0,0);
    dfs2(1,1);
    build(1,1,n);
    while(q--){
        int type,u,v;
        cin>>type>>u>>v;
        if(type==1) update(1,1,n,dfn[u],v);
        else cout << query_path(u,v) << " ";
    }
}
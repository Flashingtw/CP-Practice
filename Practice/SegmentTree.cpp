#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
ll val[N];
struct ST{
    int sz;
    vector<ll> tree,lazy;
    void pull(int idx){
        tree[idx] = tree[idx*2]+tree[idx*2+1];
    }
    void push(int idx,int l,int r){
        if(lazy[idx]==0) return;
        int mid = (l+r)/2;
        tree[idx*2]+= (mid-l)*lazy[idx];
        lazy[idx*2]+= lazy[idx];
        tree[idx*2+1]+= (r-mid)*lazy[idx];
        lazy[idx*2+1]+= lazy[idx];
        lazy[idx]=0;
    }
    void build(int idx,int l,int r){
        if(l-r==1){
            tree[idx]=val[l];
            return;
        }
        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid,r);
        pull(idx);
    }
    ST(int _sz){
        sz=_sz;
        tree.resize(4*sz);
        lazy.resize(4*sz,0);
    }
    void update(int idx,int l,int r,int ql,int qr,int v){
        push(idx,l,r);
        if(qr<=l||r<=ql) return;
        if(ql<=l&&r<=qr){
            lazy[idx]+=v;
            tree[idx]+=(r-l)*v;
            return;
        }
        int mid=(l+r)/2;
        update(idx*2,l,mid,ql,qr,v);
        update(idx*2+1,mid,r,ql,qr,v);
        pull(idx);
    }
    ll query(int idx,int l,int r,int ql,int qr){
        push(idx,l,r);
        if(qr<=l||r<=ql) return 0;
        if(ql<=l&&r<=qr) return tree[idx];
        int mid=(l+r)/2;
        return query(idx*2,l,mid,ql,qr)+query(idx*2+1,mid,r,ql,qr);
    }
};

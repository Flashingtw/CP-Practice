#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int tree[4*N];
int lazy[4*N];//add
int val[N];//original data
void pull(int idx){
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}
void push(int idx,int l,int r){
    if(lazy[idx]==0) return;
    int mid = (l+r)/2;
    lazy[idx*2] +=lazy[idx];
    tree[idx*2] +=lazy[idx]*(mid-l+1);

    lazy[idx*2+1] +=lazy[idx];
    tree[idx*2+1] +=lazy[idx]*(r-(mid+1)+1);

    lazy[idx]=0;
}
void build(int idx,int l,int r){
    lazy[idx]=0;
    if(l==r){
        tree[idx]=val[l];
        return;
    }
    int mid = (l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    pull(idx);
}
void update(int idx,int l,int r,int ql,int qr,int num){
    push(idx,l,r);
    if(ql<=l&&r<=qr){
        lazy[idx] += num;
        tree[idx] += num*(r-l+1);
        return;
    }
    int mid = (l+r)/2;
    if(ql<=mid) update(idx*2,l,mid,ql,qr,num);
    if(mid<qr) update(idx*2+1,mid+1,r,ql,qr,num);
    pull(idx);
}
int query(int idx,int l,int r,int ql,int qr){
    push(idx,l,r);
    if(ql<=l&&r<=qr){
        return tree[idx];
    }
    int ans=0;
    int mid = (l+r)/2;
    if(ql<=mid) ans = query(idx*2,l,mid,ql,qr);
    if(mid<qr) ans += query(idx*2+1,mid+1,r,ql,qr);
    return ans;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
ll val[N];
struct SegmentTree{
    ll tree[4*N],mt[4*N],lazy_set[4*N],lazy_add[4*N];
    void pull(int idx){
        tree[idx]=tree[idx*2]+tree[idx*2+1];
    }
    void push(int idx,int l,int r){
        if(lazy_add[idx]==0&&lazy_set[idx]==0) return;
        int mid = (l+r)/2;
        if(lazy_set[idx]!=0){
            tree[idx*2]=lazy_set[idx]*(mid-l+1);
            lazy_set[idx*2]=lazy_set[idx];
            lazy_add[idx*2]=0;

            tree[idx*2+1]=lazy_set[idx]*(r-mid);
            lazy_set[idx*2+1]=lazy_set[idx];
            lazy_add[idx*2+1]=0;
            
            lazy_add[idx]=0;
            lazy_set[idx]=0;
        }
        else{
            tree[idx*2]+=lazy_add[idx]*(mid-l+1);
            if(lazy_set[idx*2]!=0) lazy_set[idx*2]+=lazy_add[idx];
            else lazy_add[idx*2]+=lazy_add[idx];

            tree[idx*2+1]+=lazy_add[idx]*(mid-l+1);
            if(lazy_set[idx*2+1]!=0) lazy_set[idx*2+1]+=lazy_add[idx];
            else lazy_add[idx*2+1]+=lazy_add[idx];
            
            lazy_add[idx]=0;
        }
    }
    void build(int idx,int l,int r){
        lazy_add[idx]=0;
        lazy_set[idx]=0;
        if(l==r) {
            tree[idx]=val[l];
            return;
        }
        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        pull(idx);
    }
    void update_add(int idx,int l,int r,int ql,int qr,int v){
        push(idx,l,r);
        if(qr<l||r<ql) return;
        if(ql<=l&&r<=qr){
            if(lazy_set[idx]!=0) lazy_set[idx]+=v;
            else lazy_add[idx]+=v;
            tree[idx]+=(ll)v*(r-l+1);
            return;
        }
        int mid = (l+r)/2;
        update_add(idx*2,l,mid,ql,qr,v);
        update_add(idx*2+1,mid+1,r,ql,qr,v);
        pull(idx);
    }
    void update_set(int idx,int l,int r,int ql,int qr,int v){
        push(idx,l,r);
        if(qr<l||r<ql) return;
        if(ql<=l&&r<=qr){
            lazy_set[idx]=v;
            lazy_add[idx]=0;
            tree[idx]=(ll)v*(r-l+1);
            return;
        }
        int mid = (l+r)/2;
        update_set(idx*2,l,mid,ql,qr,v);
        update_set(idx*2+1,mid+1,r,ql,qr,v);
        pull(idx);
    }
    ll query_sum(int idx,int l,int r,int ql,int qr){
        push(idx,l,r);
        if(qr<l||r<ql) return 0;
        if(ql<=l&&r<=qr){
            return tree[idx];
        }
        int mid = (l+r)/2;
        return query_sum(idx*2,l,mid,ql,qr)+query_sum(idx*2+1,mid+1,r,ql,qr);
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>val[i];
    SegmentTree st;
    st.build(1,1,n);
    while(q--){
        int type;
        cin>>type;
        if(type==0){
            int l,r,x;
            cin>>l>>r>>x;
        }
    }
}
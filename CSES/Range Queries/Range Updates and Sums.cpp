#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

long long tree[4*N];
long long lazy_add[4*N];
long long lazy_set[4*N];
long long arr[N];
bool has_set[4*N];

void pull(int idx) {
    tree[idx] = tree[2*idx]+tree[2*idx+1];
}
void push(int idx,int l,int r) {
    int mid = (l+r)/2;
    if (has_set[idx]) {
        //left
        has_set[idx*2] = true;
        lazy_set[idx*2] = lazy_set[idx];
        lazy_add[idx*2] = 0;
        tree[idx*2] = lazy_set[idx]*(mid-l+1);
        //right
        has_set[idx*2+1] = true;
        lazy_set[idx*2+1] = lazy_set[idx];
        lazy_add[idx*2+1] = 0;
        tree[idx*2+1] = lazy_set[idx]*(r-mid);

        has_set[idx] = false;
        lazy_set[idx] = 0;
    }
    if (lazy_add[idx]!=0) {
        //left
        if (has_set[idx*2]) lazy_set[idx*2] += lazy_add[idx];
        else lazy_add[idx*2] += lazy_add[idx];

        tree[idx*2] += lazy_add[idx] * (mid-l+1);
        //right
        if (has_set[idx*2+1]) lazy_set[idx*2+1] += lazy_add[idx];
        else lazy_add[idx*2+1] += lazy_add[idx];

        tree[idx*2+1] += lazy_add[idx] * (r-mid);
        lazy_add[idx]=0;
    }
}
void build(int idx,int l,int r) {
    has_set[idx] = false;
    lazy_set[idx] = 0;
    lazy_add[idx] = 0;
    if (l==r) {
        tree[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    pull(idx);
}
void update_add(int idx,int l,int r,int ql,int qr,int val) {
    if (l!=r) push(idx,l,r);
    if (ql<=l&&r<=qr) {
        if (has_set[idx]) {
            lazy_set[idx]+=val;
        }
        else {
            lazy_add[idx]+=val;
        }
        tree[idx] += (long long)val*(r-l+1);
        return;
    }
    int mid = (l+r)/2;
    if (ql<=mid) update_add(idx*2,l,mid,ql,qr,val);
    if (qr>mid) update_add(idx*2+1,mid+1,r,ql,qr,val);
    pull(idx);
}
void update_set(int idx,int l,int r,int ql,int qr,int val) {
    if (l!=r) push(idx,l,r);
    if (ql<=l&&r<=qr) {
        has_set[idx] = true;
        lazy_set[idx] = val;
        lazy_add[idx] = 0;
        tree[idx] = (long long)val *(r-l+1);
        return;
    }
    int mid = (l+r)/2;
    if (ql<=mid) update_set(2*idx,l,mid,ql,qr,val);
    if (qr>mid) update_set(2*idx+1,mid+1,r,ql,qr,val);
    pull(idx);
}
long long query(int idx,int l,int r,int ql,int qr) {
    if (l!=r) push(idx,l,r);
    if (ql <= l && r <= qr) {
        return tree[idx];
    }
    int mid = (l+r)/2;
    long long sum=0;
    if (ql<=mid) sum+=query(2*idx,l,mid,ql,qr);
    if (mid<qr) sum+=query(2*idx+1,mid+1,r,ql,qr);
    return sum;
}
int main() {
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    while (q--) {
        int type;
        cin>>type;
        if (type==1) {
            int l,r,v;
            cin>>l>>r>>v;
            update_add(1,1,n,l,r,v);
        }
        if (type==2) {
            int l,r,v;
            cin>>l>>r>>v;
            update_set(1,1,n,l,r,v);
        }
        if (type==3) {
            int l,r;
            cin>>l>>r;
            cout << query(1,1,n,l,r) << "\n";
        }
    }
}
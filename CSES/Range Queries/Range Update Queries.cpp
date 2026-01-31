#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;

long long tree[4*MAXN];
long long lazy[4*MAXN];
long long arr[4*MAXN];

void pull(int idx) {
     tree[idx] = tree[2*idx]+tree[2*idx+1];
}
void push(int idx,int l,int r) {
    if (lazy[idx]!=0) {
        int mid = (l+r)/2;

        lazy[2*idx] += lazy[idx];
        tree[2*idx] += lazy[idx]*(mid-l+1);

        lazy[2*idx+1] += lazy[idx];
        tree[2*idx+1] += lazy[idx]*(r-mid);

        lazy[idx] =0;
    }
}
void build(int idx,int l,int r) {
    lazy[idx] = 0;
    if (l==r) {
        tree[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    pull(idx);
}

void update(int idx,int l,int r,int ql,int qr,long long val) {
    if (l!=r) push(idx,l,r);
    if (ql<=l&&r<=qr) {//包覆就lazy
        lazy[idx] += val;
        tree[idx] += val*(r-l+1);
        return;
    }
    int mid = (l+r)/2;
    if (ql<=mid) update(2*idx,l,mid,ql,qr,val);
    if (qr>mid) update(2*idx+1,mid+1,r,ql,qr,val);
    pull(idx);
}

long long query(int idx,int l,int r,int ql,int qr) {
    if (l!=r) push(idx,l,r);
    if (ql<=l&&r<=qr) return tree[idx];
    int mid = (l+r)/2;
    long long sum=0;
    if (ql<=mid) sum+=query(2*idx,l,mid,ql,qr);
    if (qr>mid) sum+=query(2*idx+1,mid+1,r,ql,qr);
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
            int l,r;
            long long val;
            cin>>l>>r>>val;
            update(1,1,n,l,r,val);
        }
        else {
            int k;
            cin>>k;
            cout << query(1,1,n,k,k) << "\n";
        }
    }
}
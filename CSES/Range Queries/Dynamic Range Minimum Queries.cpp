#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int INF = 1e9 + 7;

int tree[4*MAXN];
int arr[MAXN];//original Array

void pull(int idx) {
    tree[idx] = min(tree[2*idx],tree[2*idx+1]);
}
void build(int id,int l,int r) {
    if (l==r) {
        tree[id] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    pull(id);//遞迴回來再更新值
}

void update(int id,int l,int r,int pos,int val) {
    if (l==r) {
        tree[id] = val;
        return;
    }
    int mid = (l+r)/2;
    if (pos<=mid) update(id*2,l,mid,pos,val);
    else update(id*2+1,mid+1,r,pos,val);
    pull(id);
}
int query(int id,int l,int r,int ql,int qr) {
    if (ql<=l&&qr>=r) {
        return tree[id];
    }
    int mid = (l+r)/2;
    int res = INF;
    if (ql<=mid) {
        res = min(res,query(2*id,l,mid,ql,qr));
    }
    if (qr>mid) {
        res = min(res,query(2*id+1,mid+1,r,ql,qr));
    }
    return res;
}
int main() {
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    while (q--) {
        int type;
        cin>>type;
        if (type==2) {
            int l,r;
            cin>>l>>r;
            cout << query(1,1,n,l,r) << "\n";
        }
        else {
            int pos,val;
            cin>>pos>>val;
            update(1,1,n,pos,val);
        }
    }
}
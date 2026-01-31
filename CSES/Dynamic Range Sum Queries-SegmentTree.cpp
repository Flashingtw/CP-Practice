#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 200005;

long long tree[4*MAXN]; //premix
int arr[MAXN];

void pull(int idx) {
    tree[idx] = tree[2*idx]+tree[2*idx+1];
}
void build(int idx,int l,int r) {
    if (l==r) {
        tree[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    pull(idx);
}
void update(int idx,int l,int r,int pos,int val) {
    if (l==r) {
        tree[idx]=val;
        return;
    }
    int mid = (l+r)/2;
    if (pos<=mid) update(2*idx,l,mid,pos,val);
    else update(2*idx+1,mid+1,r,pos,val);
    pull(idx);
}
long long query(int idx,int l,int r,int ql,int qr) {
    if (ql<=l&&qr>=r) {
        return tree[idx];
    }
    long long sum=0;
    int mid = (l+r)/2;
    if (ql<=mid) sum += query(2*idx,l,mid,ql,qr);
    if (qr>mid) sum+= query(2*idx+1,mid+1,r,ql,qr);
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
            int k,u;
            cin>>k>>u;
            update(1,1,n,k,u);
        }
        else {
            int l,r;
            cin>>l>>r;
            cout << query(1,1,n,l,r) << "\n";
        }
    }
}
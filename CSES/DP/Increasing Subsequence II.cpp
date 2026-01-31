#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
const int mod = 1e9+7;

int tree[4*N];
void update(int idx,int l,int r,int n,int v) {
    if (l==r) {
        tree[idx] = (tree[idx]+v)%mod;
        return;
    }
    int mid = (l+r)/2;
    if (n<=mid) update(idx*2,l,mid,n,v);
    else update(idx*2+1,mid+1,r,n,v);
    tree[idx] = (tree[idx*2]+tree[idx*2+1])%mod;
}
int query(int idx,int l,int r,int ql,int qr) {
    if (r<ql||qr<l) return 0;
    if (ql<=l&&r<=qr) return tree[idx];
    int mid = (l+r)/2;
    return (query(idx*2,l,mid,ql,qr) + query(idx*2+1,mid+1,r,ql,qr))%mod;
}
int val[N];
int main() {
    int n;
    cin>>n;
    vector<int> v;
    for (int i=0;i<n;i++) {
        cin>>val[i];
        v.push_back(val[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int max_rank = v.size();
    for (int i=0;i<n;i++) {
        int rank = lower_bound(v.begin(),v.end(),val[i])-v.begin()+1;//find rank and +1(1 based)
        int val = query(1,1,max_rank,1,rank-1)+1;
        update(1,1,max_rank,rank,val);
    }
    cout << query(1,1,max_rank,1,max_rank);
}
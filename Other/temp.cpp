#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll a[N];
struct segtree{
    int sz;
    vector<ll> v;
    segtree(int _sz) : sz(_sz),v(4*_sz) {};
    void pull(int idx){
        v[idx] = v[idx*2]+v[idx*2+1];
    }
    void build(int idx,int l,int r){
        if(l==r){
            v[idx]=a[l];
            return;
        }
        int mid = l+(r-l)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        pull(idx);
    };
    void add(int idx,int l,int r,int k,ll val){
        if(l==r){
            v[idx]=val;
            return;
        }
        int mid = l+(r-l)/2;
        if(k<=mid) add(idx*2,l,mid,k,val);
        else add(idx*2+1,mid+1,r,k,val);
        pull(idx);
    }
    ll query(int idx,int l,int r,int ql,int qr){
        if(qr<l||r<ql) return 0;
        if(ql<=l&&r<=qr) return v[idx];
        int mid = l+(r-l)/2;
        ll ans=0;
        if(ql<=mid) ans+=query(idx*2,l,mid,ql,qr);
        if(mid<qr) ans+=query(idx*2+1,mid+1,r,ql,qr);
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    segtree seg(n+1);
    seg.build(1,1,n);
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int k,u;
            cin>>k>>u;
            seg.add(1,1,n,k,u);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout << seg.query(1,1,n,l,r) << '\n';
        }
    }
}
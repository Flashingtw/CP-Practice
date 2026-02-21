#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 200005;
const int INF = 1e9+9;
int mx[4*N],mini[4*N],val[N];
void pull(int idx){
    mx[idx] = max(mx[idx*2],mx[idx*2+1]);
    mini[idx] = min(mini[idx*2],mini[idx*2+1]);
}
void build(int idx,int l,int r){
    if(l==r){
        mx[idx] = val[l];
        mini[idx] = val[l];
        return;
    }
    int mid=(l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    pull(idx);
}
int query_mx(int idx,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr){
        return mx[idx];
    }
    int mid = (l+r)/2;
    int ans=-INF;
    if(ql<=mid) ans=max(ans,query_mx(idx*2,l,mid,ql,qr));
    if(mid<qr) ans=max(ans,query_mx(idx*2+1,mid+1,r,ql,qr));
    return ans;
}
int query_mini(int idx,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr){
        return mini[idx];
    }
    int mid = (l+r)/2;
    int ans=INF;
    if(ql<=mid) ans=min(ans,query_mini(idx*2,l,mid,ql,qr));
    if(mid<qr) ans=min(ans,query_mini(idx*2+1,mid+1,r,ql,qr));
    return ans;
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    build(1,1,n);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout << (query_mx(1,1,n,l,r)-query_mini(1,1,n,l,r)) << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const int MAXN = 1000000;
int tree[4*N];
int val[N];//original data
void pull(int idx){
    tree[idx] = max(tree[idx*2],tree[idx*2+1]);
}
void update(int idx,int l,int r,int pos,int num){
    if(l==r){
        tree[idx]=num;
        return;
    }
    int mid = (l+r)/2;
    if(pos<=mid) update(idx*2,l,mid,pos,num);
    if(mid<pos) update(idx*2+1,mid+1,r,pos,num);
    pull(idx);
}
int query(int idx,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr){
        return tree[idx];
    }
    int ans=0;
    int mid = (l+r)/2;
    if(ql<=mid) ans = max(ans,query(idx*2,l,mid,ql,qr));
    if(mid<qr) ans = max(ans,query(idx*2+1,mid+1,r,ql,qr));
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>val[i];
    int ans=0;
    for(int i=0;i<n;i++){
        int v=val[i];
        int l=max(0,val[i]-k);
        int r=min(MAXN,val[i]+k);
        int f_m = query(1,0,N,l,r);
        ans=max(ans,f_m+1);
        update(1,0,N,v,f_m+1);
    }
    cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct BIT{
    vector<ll> tree;
    int sz;
    BIT (int _sz):sz(_sz+1),tree(_sz+1,0){}
    void clear(){
        tree.assign(sz,0);
    }
    void update(int idx,int val){
        for(;idx<=sz;idx+=idx&-idx){
            tree[idx]+=val;
        }
    }
    ll query(int idx){
        ll sum=0;
        for(;idx>0;idx-=idx&-idx){
            sum+=tree[idx];
        }
        return sum;
    }
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n),rnk(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
        rnk[i]=v[i];
    }
    sort(rnk.begin(),rnk.end());
    rnk.erase(unique(rnk.begin(),rnk.end()),rnk.end());
    map<int,int> rks;
    for(int i=0;i<rnk.size();i++){
        rks[rnk[i]]=i+1;
    }
    BIT bit(rnk.size());
    ll k=0;
    for(int i=n-1;i>=0;i--){
        int rk = rks[v[i]];
        k+= bit.query(rk-1);
        bit.update(rk,1);
    }
    bit.clear();
    ll ans = 1e18,a=1,b=2;
    for(int i=0;i<n;i++){
        int rki = rks[v[i]];
        for(int j=i+1;j<n;j++){
            int rkj = rks[v[j]];
            if(v[i]==v[j]) {
                bit.update(rkj,1);
                continue;
            }
            int d;
            if(v[i]<v[j]) d = 1+2*(bit.query(rkj-1)-bit.query(rki));
            else d = -1+2*(bit.query(rki-1)-bit.query(rkj));
            if(k+d<ans){
                ans =k+d;
                a=i+1;
                b=j+1;
            }
            bit.update(rkj,1);
        }
        for(int j=i+1;j<n;j++){
            int rkj = rks[v[j]];
            bit.update(rkj,-1);
        }
    }
    cout << a << ' ' << b << ' ' << ans;
}
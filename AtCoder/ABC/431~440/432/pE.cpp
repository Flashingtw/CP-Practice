#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct BIT{
    vector<ll> tree;
    int sz;
    BIT(int _sz) : sz(_sz), tree(_sz,0) {};
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
    int n,q;
    cin>>n>>q;
    BIT cnt(5e5+5),sum(5e5+5);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i]++;
        cnt.update(v[i],1);
        sum.update(v[i],v[i]-1);
    }
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int x,y;
            cin>>x>>y;
            y++;
            cnt.update(v[x],-1);
            cnt.update(y,1);
            sum.update(v[x],-(v[x]-1));
            sum.update(y,y-1);
            v[x]=y;
        }
        else{
            ll l,r;
            cin>>l>>r;
            l++,r++;
            if(r<l){
                cout << n*(l-1) << '\n';
            }
            else{
                ll ans=cnt.query(l-1)*(l-1);
                ans+= sum.query(r)-sum.query(l-1);
                ans+= (n-cnt.query(r))*(r-1);
                cout << ans << '\n';
            }
        }
    }
}
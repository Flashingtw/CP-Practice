#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct BIT{
    vector<ll> tree;
    int sz;
    BIT(int _sz){
        sz=_sz+1;
        tree.resize(_sz+1,0);
    }
    void update(int idx,int val){
        for(;idx<=sz;idx+=idx&-idx) tree[idx]+=val;
    }
    ll query(int idx){
        ll sum=0;
        for(;idx>0;idx-=idx&-idx) sum+=tree[idx];
        return sum;
    }
    ll query(int l,int r){
        return query(r)-query(l-1);
    }
};

ll n,k;
ll solve(ll x,vector<int> &p){
    if(x<0) return 0;
    BIT bit(n+1);
    int r=1;
    ll inv=0,ans=0;
    for(int l=1;l<=n;l++){
        while(r<=n&&inv+bit.query(p[r]+1,n)<=x){
            inv+=bit.query(p[r]+1,n);
            bit.update(p[r],1);
            r++;
        }
        ans+= r-l;
        inv -= bit.query(p[l]-1);
        bit.update(p[l],-1);
    }
    return ans;
}

int main(){
    cin>>n>>k;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) cin>>p[i];
    cout << solve(k,p)-solve(k-1,p);
}
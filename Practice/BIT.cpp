#include <bits/stdc++.h>
#define lb(x) x&-x
using namespace std;
typedef long long ll;
const int N = 200005;
ll val[N];
struct BIT{
    ll tree[N];//Åv­ÈBIT
    int sz;
    BIT(int _sz){
        sz=_sz;
        for(int i=1;i<=sz;i++){
            tree[i]=0;
        }
    }
    void update(int idx,int val){
        for(;idx<=sz;idx+=lb(idx)) tree[idx]+=val;
    }
    ll query(int idx){
        ll sum=0;
        for(;idx>0;idx-=lb(idx)) sum+=tree[idx];
        return sum;
    }
    ll query(int l,int r){
        return query(r)-query(l-1);
    }
};
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    BIT bt(n);
    ll ans=0;
    for(int i=n;i>0;i--){
        ans+=bt.query(1,val[i]-1);
        bt.update(val[i],1);
    }
    cout << ans;
}

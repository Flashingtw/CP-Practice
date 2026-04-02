#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =200005;

ll tree[N];
int n,q;
void update(int idx,int v){
    for(;idx<=n;idx+= idx&-idx){
        tree[idx]+=v;
    }
}
ll query(int idx){
    ll sum=0;
    for(;idx>0;idx-=idx&-idx){
        sum+= tree[idx];
    }
    return sum;
}

int main(){
    cin>>n>>q;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        update(i,v[i]);
    }
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout << query(r)-query(l-1) << "\n";
        }
        else{
            int x,val;
            cin>>x>>val;
            ll diff = val-v[x];
            update(x,diff);
            v[x]=val;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct BIT{
    int sz;
    vector<ll> tree;
    BIT(int _sz) : sz(_sz+1),tree(_sz+1) {};
    void update(int idx,ll val){
        for(;idx<sz;idx+=idx&-idx){
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
    int n,q;
    cin>>n>>q;
    int b = sqrt(n);
    vector<ll> v(n+1);
    BIT bit(n+1);
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        bit.update(i,a);
    }
    vector<ll> add(b+1);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            ll x,val;
            cin>>x>>val;
            if(x<=b){
                add[x]+=val;    
            }
            else{
                for(int i=x;i<=n;i+=x){
                    bit.update(i,val);
                }
            }
        }
        else{
            int x=0;
            cin>>x;
            ll sum=0;
            for(int i=1;i<=min(b,x);i++){
                sum += (x/i)*(add[i]);
            }
            sum+= bit.query(x);
            cout << sum << '\n';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct BIT{
    int sz;
    vector<ll> tree;
    BIT(int _sz) : sz(_sz+1),tree(_sz+5) {};
    void add(int idx,ll val){
        for(;idx<=sz;idx+= idx&-idx){
            tree[idx]+=val;
        }
    }
    ll q(int idx){
        ll sum=0;
        for(;idx>0;idx-= idx&-idx){
            sum+=tree[idx];
        }
        return sum;
    }
    ll q(int l,int r){
        return q(r)-q(l-1);
    }
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n+1);
    BIT inv(n),bit(n);
    ll iv=0;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        bit.add(i,v[i]);
        iv+=inv.q(v[i],n);
        inv.add(v[i],1);
    };
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int i;
            cin>>i;
            if(v[i]<v[i+1]) iv++;
            else iv--;
            bit.add(i,v[i+1]-v[i]);
            bit.add(i+1,v[i]-v[i+1]);
            swap(v[i],v[i+1]);
        }
        else{
            ll k;
            cin>>k;
            ll sumA = bit.q(k);
            cout << iv+k*(n-k)-2*(sumA-k*(k+1)/2) << '\n';
        }
    }
}
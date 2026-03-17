#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

struct BIT{
    int sz;
    vector<ll> tree;
    BIT(ll _sz) : sz(_sz+1),tree(_sz+1){};
    void update(ll idx,ll val){
        for(;idx<=sz;idx+= idx&-idx){
            tree[idx]+=val;
        }
    }
    ll query(ll idx){
        ll sum=0;
        for(;idx>0;idx-= idx&-idx){
            sum+= tree[idx];
        }
        return sum;
    }
};

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<ll> prefix(n+1),NUM={0};
    for(int i=1;i<=n;i++){
        prefix[i] = prefix[i-1]+v[i]+m;
        NUM.push_back(prefix[i]);
        NUM.push_back(prefix[i]-k);
    }
    sort(NUM.rbegin(),NUM.rend());
    NUM.erase(unique(NUM.begin(),NUM.end()),NUM.end());
    int sz = NUM.size();
    ll ans=0;
    BIT bit(sz+1);
    int rk0 = lower_bound(NUM.begin(),NUM.end(),0,greater<ll>())-NUM.begin()+1;
    bit.update(rk0, 1);

    for(int r=1;r<=n;r++){
        int rk = lower_bound(NUM.begin(),NUM.end(),prefix[r]-k,greater<ll>())-NUM.begin()+1;
        ans+= bit.query(rk);
        int rka = lower_bound(NUM.begin(),NUM.end(),prefix[r],greater<ll>())-NUM.begin()+1;
        bit.update(rka,1);
    }
    cout << ans;
}   
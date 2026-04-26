#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

struct BIT{
    int sz;
    vector<ll> tree;
    BIT(int _sz) : sz(_sz+1),tree(_sz+1) {};
    void add(int idx, int val){
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
    ll query(int l,int r){
        return query(r)-query(l-1);
    }
};

void solve(){
    int n;
    cin>>n;
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second = i+1;
    }
    int j=0;
    sort(v.begin(),v.end(),greater());
    priority_queue<int> pq;
    BIT bit(n);
    ll ans=0;
    for(int i=1;i<=n;i++) bit.add(i,1);
    for(int i=n;i>0;i--){
        while(j<n&&v[j].first>=i){
            pq.push(v[j].second);
            j++;
        }
        if(pq.empty()){
            cout << -1 << '\n';
            return;
        }
        ans += bit.query(pq.top()+1,n);
        bit.add(pq.top(),-1);
        pq.pop();
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}
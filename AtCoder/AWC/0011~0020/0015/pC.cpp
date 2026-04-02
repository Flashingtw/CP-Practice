#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5+5;
map<pair<int,int>,int> mp;
map<int,vector<ll>> m;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int p,q;
        cin>>p>>q;
        mp[{p,q}]++;
        m[p].push_back(q);
    }
    ll ans=0;
    for(auto &[a,b]:m){
        ll s = b.size();
        ans+= s*(s-1)/2;
    }
    for(auto[pq,cnt]:mp){
        ans -= (ll)cnt*(cnt-1)/2;
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    map<ll,ll> mp;
    mp[0]=1;
    ll cur=0;
    for(int i=1;i<=n;i++){
        cur+=v[i];
        mp[cur%k]++;
    }
    ll ans=0;
    for(auto &[a,b]:mp){
        ans += b*(b-1)/2;
    }
    cout << ans;
}
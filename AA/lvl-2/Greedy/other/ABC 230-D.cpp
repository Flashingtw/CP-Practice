#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,d;
    cin>>n>>d;
    vector<pii> v(n);
    for(auto &[r,l]:v) cin>>l>>r;
    sort(v.begin(),v.end());
    ll cur=0;
    ll ans=0;
    for(auto [r,l]:v){
        if(r<=cur||cur>=l) continue;
        if(cur<r){
            ans++;
            cur = r+d-1;
        }
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,d;
    cin>>n>>d;
    vector<pll> a(n);
    for(auto &[s,f]:a) cin>>s>>f;
    ll ans=0;    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((abs(a[i].first-a[j].first))+(abs(a[i].second-a[j].second))==d) ans++;
        }
    }
    cout << ans << '\n';
}
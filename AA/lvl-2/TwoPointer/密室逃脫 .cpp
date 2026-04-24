#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,m,ans=0;
    cin>>n>>m;
    vector<ll> v(n);
    for(ll &a:v) cin>>a;
    sort(v.begin(),v.end());

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll t = m-v[j]-v[i];

            int r = upper_bound(v.begin()+j+1,v.end(),t)-v.begin();
            int l = lower_bound(v.begin()+j+1,v.end(),t)-v.begin();

            ans+= r-l;
        }
    }
    cout << ans << '\n';
}
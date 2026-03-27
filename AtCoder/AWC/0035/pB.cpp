#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF = 1e18+9;
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> d(n),s(m);
    for(int i=0;i<n;i++) cin>>d[i];
    for(int i=0;i<m;i++) cin>>s[i];
    sort(s.begin(),s.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        auto it = upper_bound(s.begin(),s.end(),d[i]);
        ll r =INF,l=INF;
        if(it!=s.end()){
            r = *it;
        }
        if(it!=s.begin()){
            it--;
            l = *it;
        }
        ans+= min(abs(r-d[i]),abs(l-d[i]));
    }
    cout << ans;
}
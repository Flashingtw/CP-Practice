#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,k,t,c;
    cin>>n>>k>>t>>c;
    vector<ll> diff(n+2);
    ll ans=0,cur=0;
    for(int i=1;i<=n;i++){
        ll d;
        cin>>d;
        if(diff[i]<0){
            cur+=diff[i];
        }
        if(d+cur<t){
            ll need=t-cur-d;
            cur+=need;
            ans+=need;
            int idx=min(n+1,i+k);
            diff[idx]-=need;
        }
    }
    cout << ans*c;
}
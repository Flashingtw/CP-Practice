#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int main(){
    ll L,n1,n2;
    cin>>L>>n1>>n2;
    vector<pii> v1(n1),v2(n2);
    for(int i=0;i<n1;i++) cin>>v1[i].first>>v1[i].second;
    for(int i=0;i<n2;i++) cin>>v2[i].first>>v2[i].second;
    ll i=0,j=0,use1=0,use2=0;
    ll ans=0;
    while(i<n1&&j<n2){
        ll l = min(v1[i].second-use1,v2[j].second-use2);
        if(v1[i].first==v2[j].first) ans+=l;
        use1+=l;
        use2+=l;
        if(use1==v1[i].second){
            i++; 
            use1=0;
        }
        if(use2==v2[j].second){
            j++; 
            use2=0;
        }
    }
    cout << ans << '\n';
}
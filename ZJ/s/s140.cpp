#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6+7;
typedef long long ll;
int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll l=0,r=min(a,b)*n;
    ll ans = r;
    ll cnt=0;
    while(l<=r){
        ll mid = (l+r)/2;
        cnt= (mid/a)+(mid/b);
        if(cnt>=n){
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout << ans%mod;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
ll k,x;

bool chk(ll tar){
    ll cnt=0;
    if(tar<=k){
        cnt = (tar*(tar+1))/2;
    }
    else{
        ll r = 2*k-1-tar;
        cnt = k*k;
        cnt -= (r*(r+1))/2; 
    }
    return cnt>=x;
}

void solve(){
    cin>>k>>x;
    ll l = 1 , r = 2*k-1,ans=2*k-1;
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(mid)){
            ans = mid;
            r = mid -1;
        }
        else{
            l = mid +1;
        }
    }
    cout << ans << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}
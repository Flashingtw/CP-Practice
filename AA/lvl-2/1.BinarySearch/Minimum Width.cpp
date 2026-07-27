#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
bool chk(ll tar,vector<ll> &v){
    if(v[0]>tar) return false;
    ll cur=v[0],cnt=1;
    for(int i=1;i<n;i++){
        if(v[i]>tar) return false;
        if(cur+v[i]+1>tar){
            cnt++;
            cur = v[i];
        }
        else{
            cur+=v[i]+1;
        }
    }
    return cnt<=m;
}

int main(){
    cin>>n>>m;
    vector<ll> v(n);
    ll l = 1,r=n+1,ans;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        r+=v[i];
    }
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(mid,v)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << '\n';
}
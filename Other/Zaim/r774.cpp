#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,z;

bool chk(ll n){
    ll az = (y+n)*100/(x+n);
    return az!=z;
}

int main(){
    cin>>x>>y;
    z = y*100/x;
    if(z>=99){
        cout << -1;
    }
    else{
        ll l = 0,r = 2e9;
        ll ans=0;
        while(l<=r){
            int mid = (l+r)/2;
            if(chk(mid)){
                ans=mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        cout << ans;
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll w,h,n;
bool chk(ll tar){
    ll x = tar/w;
    ll y = tar/h;
    if(x==0||y==0) return 0;
    if(x>=n||y>=n) return 1;
    return (tar/w)*(tar/h)>=n;
}

int main(){
    cin>>w>>h>>n;
    ll l=1,r=1e18,ans;
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(mid)){
            r = mid-1;
            ans=mid;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << '\n';
}
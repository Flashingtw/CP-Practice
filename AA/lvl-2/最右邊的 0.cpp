#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool query(ll mid){
    cout << "? " << mid << endl;
    int v;
    cin>>v;
    return v;
}
int main(){
    ll L,R;
    cin>>L>>R;
    ll l=L,r=R,ans=L-1;
    while(l<=r){
        ll mid = l+(r-l)/2;
        if(!query(mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    if(ans<L) cout << "! no zero" << endl;
    else cout << "! " << ans << endl;
}
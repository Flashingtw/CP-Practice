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
    ll l=L,r=R,ans=R+1;
    while(l<=r){
        ll mid = l+(r-l)/2;
        if(query(mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    if(ans>R) cout << "! no one" << endl;
    else cout << "! " << ans << endl;
}
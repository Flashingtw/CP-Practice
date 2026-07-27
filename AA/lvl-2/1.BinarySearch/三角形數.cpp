#include <bits/stdc++.h>
#define tri(x) (x*(x+1))/2
using namespace std;
using ll = long long;

ll query(ll x){
    ll l=1,r=2e9,ans;
    while(l<=r){
        ll mid = (l+r)/2;
        if(tri(mid)>=x){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        cout << tri(query(x)) << '\n';
    }
}
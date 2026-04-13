#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
int forb[N];
ll x,y,n,q;

bool chk(ll tar,ll dx){
    auto it = upper_bound(forb,forb+n,tar);
    --it;
    ll r = it-forb;
    ll total = tar-x+1;
    total -= r-dx+1;
    return total>=y;
}

void query(){
    ll l = x,r = 1e18,ans;
    ll dx = lower_bound(forb,forb+n,x)-forb;
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(mid,dx)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>forb[i];
    sort(forb,forb+n);
    for(int i=0;i<q;i++){
        cin>>x>>y;
        query();
    }
}
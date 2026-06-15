#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll k;
    cin>>k;
    ll l=0,r=n*m,ans=0;
    while(l<=r){
        ll mid = l+(r-l)/2;
        ll cnt=0;
        for(int i=1;i<=n;i++){
            cnt+= min(m,mid/i);
        }
        if(cnt>=k){
            r = mid-1;
            ans = mid;
        }
        else l = mid+1;
    }
    cout << ans << '\n';
}
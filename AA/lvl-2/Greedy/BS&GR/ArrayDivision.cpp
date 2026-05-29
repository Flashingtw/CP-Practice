#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n,k;
bool chk(ll m,vector<ll> &v){
    ll cur=0,cnt=1;
    for(ll i:v){
        if(i>m) return 0;
        if(cur+i<=m){
            cur+=i;
        }
        else{
            cur=i;
            cnt++;
        }
    }
    return cnt<=k;
}
int main(){
    cin>>n>>k;
    vector<ll> v(n);
    for(ll &i:v) cin>>i;
    ll l=0,r=1e15,ans=0;
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(mid,v)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << '\n';
}
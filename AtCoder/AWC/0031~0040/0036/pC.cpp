#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
ll n,k;
bool chk(vector<ll> &v,ll tar){
    ll cur=0,cnt=0;
    for(int i=0;i<n;i++){
        if(v[i]>tar) return false;
        if(cur+v[i]>tar){
            cur=v[i];
            cnt++;
        }
        else{
            cur+=v[i];
        }
    }
    return cnt<=k;
}
int main(){
    cin>>n>>k;
    vector<ll> v(n);
    ll l=0,r=0,ans=-1;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        r+=v[i];
    }
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(v,mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans;
}
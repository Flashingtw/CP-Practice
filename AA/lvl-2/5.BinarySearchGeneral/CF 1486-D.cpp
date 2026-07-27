#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n,k;
bool chk(ll mid,vector<int> &v){
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        a[i] = -1+2*(v[i-1]>=mid);
    }
    vector<int> prefix(n+1);
    for(int i=1;i<=n;i++){
        prefix[i] = prefix[i-1]+a[i];
    }
    int i=-1;
    ll sl = 1e18;
    for(int j=k;j<=n;j++){
        if(prefix[j-k]<sl){
            i = j-k;
            sl = prefix[j-k];
        }
        if(prefix[j]-sl>0) return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>k;
    vector<int> v(n);
    for(int &i:v) cin>>i;
    ll l=1,r=n+1,ans=-1;
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(mid,v)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans << '\n';
}
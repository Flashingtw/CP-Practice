#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<ll> a(n),b(n);
    for(ll &i:a) cin>>i;
    for(ll &i:b) cin>>i;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    while(q--){
        ll k;
        cin>>k;
        ll l=1,r=2e9,ans=0;
        while(l<=r){
            ll mid = l+(r-l)/2;
            int j=0;
            ll cnt=0;
            for(int i=n-1;i>=0;i--){
                while(j<n&&a[i]+b[j]<=mid) j++;
                cnt+=j;
            }
            if(cnt>=k){
                r = mid-1;
                ans = mid;
            }
            else l = mid+1;
        }
        cout << ans << '\n';
    }
}
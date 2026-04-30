#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &a:v) cin>>a;
    sort(v.begin(),v.end());
    int mx = v.back();
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int l = mx-v[i]-v[j];
            int r = v[i]+v[j];
            int L = upper_bound(v.begin()+j+1,v.end(),l)-v.begin();
            int R = lower_bound(v.begin()+j+1,v.end(),r)-v.begin();
            if(L<=R) ans+=R-L;
        }
    }
    cout << ans << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
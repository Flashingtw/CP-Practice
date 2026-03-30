#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int cnt=0;
    if(gcd(a[0],a[1])<a[0]) cnt++;
    if(gcd(a[n-1],a[n-2])<a[n-1]) cnt++;
    for(int i=1;i<n-1;i++){
        ll l = gcd(a[i-1],a[i]);
        ll r = gcd(a[i+1],a[i]);
        ll m = lcm(l,r);
        if(m<a[i]) cnt++;
    }
    cout << cnt << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}
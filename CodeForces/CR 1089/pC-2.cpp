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
    for(int i=0;i<n;i++){
        ll l = -1,r=-1;
        if(i>0) l = gcd(a[i-1],a[i]);
        if(i<n-1) r = gcd(a[i+1],a[i]);
        ll m;
        if(l==-1) m = r;
        else if (r==-1) m = l;
        else m = lcm(l,r);
        if(m<a[i]&&m<=b[i]){
            cnt++;
            continue;
        }
        if(m==a[i]){
            ll cl= (l!=-1)?(a[i-1]/l):1;
            ll cr= (r!=-1)?(a[i+1]/r):1;
            for(ll k=2;k*m<=b[i];k++){
                if(gcd(k,cl)==1&&gcd(k,cr)==1){
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

ll f(ll a,ll b){
    return a*a*a+a*a*b+a*b*b+b*b*b;
}

void solve(){
    ll N;
    cin>>N;
    ll b = 1e6;
    ll ans = 2e18;
    for(ll a=0;a*a*a<=N;a++){
        while(b>0&&f(a,b-1)>=N){
            b--;
        }
        ans = min(ans,f(a,b));
    }
    cout << ans << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    ll x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    ll dx = x1-x2;
    ll dy = y1-y2;
    ll rr = r1+r2;
    ll rl = r1-r2;
    if(rl*rl<=dx*dx+dy*dy&&dx*dx+dy*dy<=rr*rr) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    ll a,b,c,m;
    cin>>a>>b>>c>>m;
    ll thr = m/lcm(a,lcm(b,c)) , abday = m/lcm(a,b) , bcday = m/lcm(b,c) , acday = m/lcm(a,c);
    ll cnta=0,cntb=0,cntc=0;
    a = m/a, b = m/b, c = m/c;
    cnta = (a-abday-acday+thr)*6 + (abday+acday-2*thr)*3 + thr*2;
    cntb = (b-abday-bcday+thr)*6 + (abday+bcday-2*thr)*3 + thr*2;
    cntc = (c-acday-bcday+thr)*6 + (acday+bcday-2*thr)*3 + thr*2;
    cout << cnta << ' ' << cntb << ' ' << cntc << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
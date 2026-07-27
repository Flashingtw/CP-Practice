#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF = 1e9+9;

ll n,k;
bool chk(vector<pll> &v,double tar){
    ll cnt=0;
    for(auto [a,b]:v){
        ll w = a/tar;
        ll h = b/tar;
        cnt += w*h;
    }
    return cnt>=k;
}

int main(){
    cin>>n>>k;
    vector<pll> v(n);
    for(auto &[a,b]:v){
        cin>>a>>b;
    }
    double l=0,r=9e18,ans=-1;
    for(int count=0;count<100;count++){
        double mid = (l+r)/2;
        if(chk(v,mid)){
            ans = mid;
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << fixed << setprecision(15) << ans << '\n';
}
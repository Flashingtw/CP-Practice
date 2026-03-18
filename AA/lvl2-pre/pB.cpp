#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll LMT = 1e18;
ll Lccm(ll a , ll b){
    ll g = gcd(a,b);
    if(a/g>LMT/b){
        return -1;
    }
    return lcm(a,b);
}
int main(){
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    ll lc = 1;
    for(int i=0;i<n;i++){
        lc = Lccm(lc,v[i]);
        if(lc==-1){
            cout <<  "The answer is too large.";
            return 0;
        }
    }
    cout << lc;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
map<int,int> mp[11];

void f(ll num){
    for(ll i=1,t=10;i<=10;i++,t*=10){
        ll r = (num*t)%m;
        mp[i][r]++;
    }
}
int main(){
    cin>>n>>m;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        f(v[i]);
    }
    for(int i=0;i<n;i++){
        
    }
}
// x*10^L + y === 0 (mod m)
// x*10^L === -y (mod m)
// (x*10^L) %m + y%m === 0
// 
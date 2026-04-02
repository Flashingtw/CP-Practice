#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,t,k;
    cin>>n>>t>>k;
    vector<ll> v(n);
    ll mini = LONG_LONG_MAX;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mini= min(mini,v[i]);
    }
    ll d = mini-1,ans=0;
    for(int i=0;i<n;i++){
        if(v[i] <= t+k+d) ans++;
    }
    cout << ans;
}
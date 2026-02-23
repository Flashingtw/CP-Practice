#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m;
    cin>>n>>m;
    ll s,t;
    cin>>s>>t;
    if(s>t) swap(s,t); 
    ll ans=0;
    for(int i=0;i<m;i++){
        ll p,v;
        cin>>p>>v;
        if(s<=p&&p<=t) ans+=v;
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int main(){
    ll n,s,c;
    cin>>n>>s>>c;
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    int cnt=0;
    for(auto [hi,pi]:v){
        if(s>=hi) s=  s-hi+pi;
        else cnt++;
    }
    cout << cnt*c;
}
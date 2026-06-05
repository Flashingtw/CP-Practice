#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<pii> v(n);
    for(auto &[b,a]:v) cin>>a>>b;
    sort(v.begin(),v.end());
    int i=0,j=n-1;
    ll ans=0,sum=0;
    while(i<=j){
        if(sum>=v[i].first){
            ans+=v[i].second;
            sum+=v[i].second;
            i++;
        }
        else{
            ll need = v[i].first-sum;
            ll take = min(need,v[j].second);
            ans+=take*2;
            sum+=take;
            need-=take;
            v[j].second-=take;
            if(v[j].second==0) j--;
        }
    }
    cout << ans << '\n';
}
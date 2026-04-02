#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main(){
    ll n,m;
    cin>>n>>m;
    vector<pll> v(m);
    for(int i=0;i<m;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    ll cur=1,idx=0,cnt=0;
    while(n>0&&idx<m){
        if(v[idx].second<cur){
            idx++;
            continue;
        }
        ll gap = v[idx].first-cur;
        if(gap>0){
            if(gap >= n){
                cur=cur+n-1;
                n=0;
                break;
            }
            if(gap<n){
                n-=gap;
                cur=v[idx].second+1;
                idx++;
            }
        }
        else{
            cur=v[idx].second+1;
            idx++;
        }
    }
    if(n>0){
        cout << cur+n-cnt-1;
    }
    else cout << cur;
}
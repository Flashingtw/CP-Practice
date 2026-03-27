#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
bool chk(int n,int k,ll m,vector<pll> &sf_o,vector<ll> &en){
    vector<ll> sf;
    for(auto &[a,b]:sf_o){
        sf.push_back(a+m*b);
    }
    sort(sf.begin(),sf.end(),greater());
    int cnt=0;
    int i=0,j=0;
    while(i<n&&j<n){
        if(sf[i]>en[j]){
            cnt++;
            i++,j++;
        }
        else{
            j++;
        }
    }
    return cnt>=k;
}

void solve(){
    int n,k;
    cin>>n>>k;
    
    vector<ll> en(n);
    vector<pll> sf(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        sf[i]={a,b};
    }
    for(int i=0;i<n;i++){
        cin>>en[i];
    }
    sort(en.begin(),en.end(),greater());
    ll l=0,r=1e9,ans=-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(chk(n,k,mid,sf,en)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << '\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
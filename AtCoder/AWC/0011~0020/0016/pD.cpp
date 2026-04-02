#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    ll cur=0;
    vector<ll> ans(n+1);
    for(int i=1,j=1;i<=n&&j<=n;j++){
        cur+=v[j];
        while(cur>k){
            ans[i]=j;
            cur-=v[i];
            i++;
        }
        if(j==n){
            while(i<=n){
                ans[i]=j;
                i++;
            }
        }
    }
    vector<ll> prefix(n+1);
    prefix[0]=0;
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+ans[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout << prefix[r]-prefix[l-1] << '\n';
    }
}
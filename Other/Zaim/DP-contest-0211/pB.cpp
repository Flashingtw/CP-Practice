#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> dp(k+1,1);
    for(int j=2;j<=n;j++){
        vector<int> tmp(k+1);
        ll sum=0;
        for(int i=1;i<=k;i++) sum = (sum+dp[i])%mod;
        for(int j=1;j<=k;j++){
            ll v=sum;
            for(int m=2*j;m<=k;m+=j) v = (v-dp[m]+mod)%mod;
            tmp[j]=v;
        }
        swap(dp,tmp);
    }
    ll ans=0;
    for(int i=1;i<=k;i++) ans = (ans+dp[i])%mod;
    cout << ans; 
}
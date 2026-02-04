#include <bits/stdc++.h>
using namespace std;
int dp[1000020];
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int ans=0;
    for(int i=0;i<n;i++){
        int f_m=0;
        for(int j=max(0,v[i]-k);j<=min(1000010,v[i]+k);j++){
            f_m=max(f_m,dp[j]);
        }
        dp[v[i]]=f_m+1;
        ans=max(ans,dp[v[i]]);
    }
    cout << ans;
}

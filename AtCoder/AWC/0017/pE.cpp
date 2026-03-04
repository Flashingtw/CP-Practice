#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
pii pos[20];
ll dp[1<<16][16];
ll dist(int i,int j){
    auto [x1,y1] = pos[i];
    auto [x2,y2] = pos[j];
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j]=1e18;
        }
    }
    for(int i=0;i<n;i++){
        cin>>pos[i].first>>pos[i].second;
    }
    dp[1][0] = 0;
    for(int mask=1;mask<(1<<n);mask++){
        for(int u=0;u<n;u++){
            if(dp[mask][u]!=1e18){
                for(int v=1;v<n;v++){
                    if(mask&(1<<v)) continue;
                    dp[mask|(1<<v)][v]=min(dp[mask|(1<<v)][v],dp[mask][u]+dist(u,v));
                }
            }
        }
    }
    ll ans=1e18;
    int full=(1<<n)-1;
    for(int i=1;i<n;i++) ans = min(ans,dp[full][i]+dist(0,i));
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
int dp[1<<16][16];
vector<pair<int,int>> adj[16];
const int INF = 1e9;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++) dp[i][j]=INF;
    }
    for(int i=0;i<n;i++) dp[1<<i][i]=0;
    for(int mask=1;mask<(1<<n);mask++){
        for(int u=0;u<n;u++){
            if(dp[mask][u]==INF) continue;
            if(mask&(1<<u)){
                for(auto [v,w]:adj[u]){
                    if(!(mask&(1<<v))){
                        int newmask=mask|1<<v;
                        dp[newmask][v]=min(dp[newmask][v],dp[mask][u]+w);
                    }
                }
            }
        }
    }
    int ans=INF,full=(1<<n)-1;
    for(int i=0;i<n;i++){
        ans = min(ans,dp[full][i]);
    }
    cout << ans;
}
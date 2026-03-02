#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
vector<ll> H(13);
ll dist[13][13];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>H[i];
    }
    int s,t;
    cin>>s>>t;
    for(int i=0;i<13;i++){
        for(int j=0;j<13;j++) dist[i][j]=INF;
        dist[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
        dist[v][u]=w;
    }
    vector<vector<ll>> dp(1<<13,vector<ll>(13,-INF));
    dp[1<<s][s]=H[s];
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int mask=2;mask<=(1<<(n+1))-1;mask++){
        for(int u=1;u<=n;u++){
            if(mask&(1<<u)){
                if(dp[mask][u]==-INF) continue;
                for(int v=1;v<=n;v++){
                    if(!(mask&(1<<v))){
                        if(dist[u][v]==INF) continue;
                        int new_mask = mask|(1<<v);
                        dp[new_mask][v] = max(dp[new_mask][v],dp[mask][u]+H[v]-dist[u][v]);
                    }
                }
            }
        }
    }

    ll ans=-INF;
    for(int i=2;i<=(1<<(n+1))-1;i++){
        if(i&(1<<t)){
            ans = max(ans,dp[i][t]);
        }
    }
    cout << ans;
}
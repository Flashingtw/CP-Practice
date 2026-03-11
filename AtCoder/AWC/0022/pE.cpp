#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF = 1e18+9;
ll dist[20][20];
ll dp[1<<16][20];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = INF;
            if(i==j) dist[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        dist[u][v]=w;
        dist[v][u]=w;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int mask=1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++) dp[mask][i]=INF;
    }
    dp[1<<0][0]=0;
    for(int mask=1;mask<(1<<n);mask++){
        for(int u=0;u<n;u++){
            if(dp[mask][u]==INF) continue;
            for(int v=0;v<n;v++){
                if(!(mask&(1<<v))){
                    if(dist[u][v]==INF) continue;
                    int nxt = mask|(1<<v);
                    dp[nxt][v]= min(dp[nxt][v],dp[mask][u]+dist[u][v]);
                }
            }
        }
    }
    ll ans=INF;
    int full = (1<<n)-1;
    for(int i=0;i<n;i++){
        if(dp[full][i]<INF&&dist[i][0]<INF) {
            ans = min(ans,dp[full][i]+dist[i][0]);
        }
        
    }
    if(ans>=INF) cout << -1;
    else cout << ans;
}
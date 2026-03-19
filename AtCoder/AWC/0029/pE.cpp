#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF = 1e16+9;
const int N = 2e5+5;
ll dist[305][305];
ll dp[(1<<15)][15];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    int s,k;
    cin>>s>>k;
    vector<int> ver(k);
    for(int mask=1;mask<=(1<<k)-1;mask++){
        for(int u=0;u<k;u++) dp[mask][u] = INF;
    }
    for(int i=0;i<k;i++){
        cin>>ver[i];
        dp[(1<<i)][i] = dist[s][ver[i]];
    }
    for(int mask=1;mask<=(1<<k)-1;mask++){
        for(int u=0;u<k;u++){
            for(int v=0;v<k;v++){
                if(mask&(1<<v)) continue;
                int nx = mask|(1<<v);
                dp[nx][v] = min(dp[nx][v],dp[mask][u]+dist[ver[u]][ver[v]]);
            }
        }
    }
    int full = (1<<k)-1;
    ll ans = INF;
    for(int i=0;i<k;i++){
        ans = min(ans,dp[full][i]+dist[ver[i]][s]);
    }
    if(ans==INF) cout << -1;
    else cout << ans;
}
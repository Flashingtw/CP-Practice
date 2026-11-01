#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int g[N][N][4];
// R,D,L,U
int dp[N][N][3];
int main(){
    int n,m;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<n;j++){
            int v;
            cin>>v;
            g[i][j][0] = g[i][j+1][2] = v;
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<=n;j++){
            int v;
            cin>>v;
            g[i][j][1] = g[i+1][j][3] = v;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j][0] = max({
                dp[i-1][j][0]+g[i-1][j][1],
                dp[i-1][j][1]+g[i-1][j][1],
                dp[i-1][j][2]+g[i-1][j][1],
                0
            });
            dp[i][j][1] = max({
                dp[i][j-1][0]+g[i][j-1][0],
                dp[i][j-1][1]+g[i][j-1][0],
                0
            });
        }
        for(int j=n;j>=1;j--){
            dp[i][j][2] = max({
                dp[i][j+1][0]+g[i][j+1][2],
                dp[i][j+1][2]+g[i][j+1][2],
                0
            });
        }
    }
    int ans = -1e9;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            ans = max({ans,dp[i][j][0],dp[i][j][1],dp[i][j][2]});
        }
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int mod = 1e9+7;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<char>> g(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    vector<vector<ll>> dp(n+1,vector<ll>(m+1));
    dp[0][1] = g[1][1]=='.';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]=='*') continue;
            dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout << dp[n][m] << '\n';
}
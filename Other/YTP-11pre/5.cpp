#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const ll mod = 998244353;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<char>> g(n+1,vector<char>(m+1));
    vector<vector<ll>> dp(m+1,vector<ll>(2));
    vector<vector<ll>> last(m+1,vector<ll>(2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    last[1][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]=='.'){
                dp[j][0] = (dp[j-1][0] + last[j][0]) % mod;
                dp[j][1] = (dp[j-1][1] + last[j][1]) % mod;
            }
            else{
                dp[j][0] = (dp[j-1][1] + last[j][1]) % mod;
                dp[j][1] = (dp[j-1][0] + last[j][0]) % mod;
            }
        }
        dp.swap(last);
    }
    cout << last[m][1] << '\n';
}
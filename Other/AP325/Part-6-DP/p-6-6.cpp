#include <bits/stdc++.h>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> v(m+1,vector<int>(n+1,0));
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>v[i][j];
        }
    }
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for (int i=1;i<=m;i++) dp[i][1] = dp[i-1][1] + v[i][1];
    for (int i=1;i<=n;i++) dp[1][i] = dp[1][i-1] + v[1][i];
    for (int i=2;i<=m;i++) {
        for (int j=2;j<=n;j++) {
            dp[i][j] = v[i][j] + max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[m][n];
}
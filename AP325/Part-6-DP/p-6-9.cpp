#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,bag;
    cin>>n>>bag;
    vector<int> w(n+1),p(n+1);
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<=n;i++) cin>>p[i];

    vector<vector<int>> dp(n+1,vector<int>(bag+1,0));
    // i 為物品 j 為重量 , dp[i][j]為第i個物品在j重量時的最高價值
    for (int i=1;i<=n;i++) {
        for (int j=0;j<w[i];j++) {
            if (j>bag) break;
            dp[i][j] = dp[i-1][j];
        }
        for (int j=w[i];j<=bag;j++) {
            dp[i][j] = max(dp[i-1][j-w[i]]+p[i],dp[i-1][j]);
        }
    }
    cout << dp[n][bag];
}
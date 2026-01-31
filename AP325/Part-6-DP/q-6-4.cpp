#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,t;
    cin>>n>>t;
    vector<vector<int>> v(n+1,vector<int>(2));
    for (int i=1;i<=n;i++) cin>>v[i][0]>>v[i][1];
    vector<vector<int>> dp(n+1,vector<int>(2));
    //要存改成第一種跟改成第二種的最小成本
    dp[1][0] = abs(t-v[1][0]);
    dp[1][1] = abs(t-v[1][1]);//第一關改成兩種的成本
    for (int i=2;i<=n;i++) {
        dp[i][0] = min(dp[i-1][0]+ abs(v[i-1][0]-v[i][0]),dp[i-1][1]+ abs(v[i-1][1]-v[i][0]));
        dp[i][1] = min(dp[i-1][0]+ abs(v[i-1][0]-v[i][1]),dp[i-1][1]+ abs(v[i-1][1]-v[i][1]));
    }
    cout << min(dp[n][0],dp[n][1]);
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v(n+1);
    for (int i=1;i<=n;i++) cin>>v[i];
    vector<int> dp(n+1);
    dp[0] = 1000000;
    dp[1] = v[1];
    dp[2] = v[2];
    dp[3] = v[3] + min(v[2],v[1]);
    //定義遞迴式為最後一點選在i的最小成本
    for (int i=4;i<=n;i++) {
        dp[i] = v[i] + min(dp[i-1],min(dp[i-2],dp[i-3]));
    }
    cout << min(dp[n],dp[n-1]);
}
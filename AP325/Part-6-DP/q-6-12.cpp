#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for (int i=1;i<=n;i++) cin>>v[i];

    vector<int> dp(n+1,0);
    for (int i=1;i<=n;i++) {
        if (i-k<1) {
            dp[i] = max(dp[i-1],v[i]);//演賺還是不演賺
            continue;
        }
        dp[i] = max(dp[i-k-1]+v[i],dp[i-1]);//當天演or不演
    }
    cout << dp[n];
}
#include <bits/stdc++.h>
using namespace std;
const int p = 1e9+7;
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    //dp[i][j] mean the ith num is j
    vector<vector<int>> dp(n+1,vector<int>(m+2,0));
    if (v[0]!=0) dp[0][v[0]] = 1;
    else {
        for (int i=1;i<=m;i++) {
            dp[0][i] = 1;
        }
    }

    for (int i=1;i<n;i++) {
        int num=v[i];
        for (int j=1;j<=m;j++) {
            if (num==j||num==0) {
                long long sum = dp[i-1][j];
                sum+= dp[i-1][j-1];
                sum+= dp[i-1][j+1];
                dp[i][j] = sum%p;
            }
        }
    }
    long long sum =0;
    for (int i=0;i<=m;i++) {
        sum = (sum+dp[n-1][i])%p;
    }
    cout << sum;
}
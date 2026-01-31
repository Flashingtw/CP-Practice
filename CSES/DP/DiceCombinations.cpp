#include <iostream>
using namespace std;
const int MOD = 1000000007;
int main() {
    int n ;
    cin>>n;
    long long dp[n+1];
    dp[0]=1;
    for (int i = 1;i<=n;i++) {
        dp[i]=0;
        for (int k=1 ;k<=6;k++) {
            if (i-k>=0) {
                dp[i] = (dp[i] + dp[i-k])%MOD;
            }
        }
    }
    cout << dp[n];
}
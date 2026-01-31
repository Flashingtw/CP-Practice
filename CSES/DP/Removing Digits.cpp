#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> dp(n+20,0);
    for (int i=1;i<10;i++) dp[i] = 1;
    for (int i=10;i<=n;i++) {
        dp[i] = INT_MAX;
        int temp = i;
        while (temp>0) {
            if (temp%10==0) {
                temp/=10;
                continue;
            }
            dp[i] = min(dp[i],1+dp[i-temp%10]);
            temp/=10;
        }
    }
    cout << dp[n];
}
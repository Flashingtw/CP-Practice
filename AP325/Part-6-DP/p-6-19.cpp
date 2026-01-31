#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string n;
    cin>>n;
    int L = n.length();
    vector<vector<ll>> dp(L+1,vector<ll>(10,0));
    for (int i=1;i<=9;i++) {
        dp[1][i] = 1;
    }
    dp[1][0] = 0;
    for (int i=2;i<=L;i++) {
        dp[i][9] = dp[i-1][9];
        for (int j=8;j>=0;j--) {
            dp[i][j] = dp[i-1][j] + dp[i][j+1];
        }
    }
    ll ans =0;
    int i;
    for (int j =0;j<n[0]-'0';j++) {
        ans+=dp[L][j];
    }
    for (i=1;i<L;i++) {
        if (n[i] < n[i-1]) break;
        for (int j = n[i-1]-'0';j<n[i]-'0';j++) {
            ans+=dp[L-i][j];
        }
    }
    if (i==L) ans++;
    cout << ans;
}
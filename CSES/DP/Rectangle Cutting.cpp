#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int a,b;
    cin>>a>>b;

    vector<vector<int>> dp(a+1,vector<int>(b+1));
    //枚舉start
    for (int w=1;w<=a;w++) {
        for (int h=1;h<=b;h++) {
            if (w==h) {
                dp[w][h]=0;
                continue;
            }
            dp[w][h]= 2e9;
            for (int i=1;i<=w/2;i++) {
                dp[w][h] = min(dp[w][h],dp[i][h]+dp[w-i][h]+1);
            }
            for (int j=1;j<=h/2;j++) {
                dp[w][h] = min(dp[w][h],dp[w][j]+dp[w][h-j]+1);
            }
        }
    }
    cout << dp[a][b];
}
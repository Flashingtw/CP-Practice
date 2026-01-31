#include <bits/stdc++.h>
using namespace std;
int main() {
    string n,m;
    cin>>n>>m;
    int len_n=n.length(),len_m=m.length();
    //dp[i][j] is n's i-1 char change to m's j-1 char min step
    vector<vector<int>> dp(len_n + 1, vector<int>(len_m + 1,0));
    //dp initialize
    for (int i=0;i<=len_n;i++) dp[i][0] = i;
    for (int j=0;j<=len_m;j++) dp[0][j] = j;

    for (int i = 1;i<=len_n;i++) {
        for (int j = 1;j<=len_m;j++) {
            //same char
            if (n[i-1]==m[j-1]) {
                dp[i][j] = dp[i-1][j-1];//do nothing
            }
            else {
                //insert ,remove ,change
                dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
            }
        }
    }
    cout << dp[len_n][len_m];
}
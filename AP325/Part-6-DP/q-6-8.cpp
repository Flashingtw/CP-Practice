#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.length(),n=s2.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    int max_ans=0;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            int score;
            if (s1[i-1]==s2[j-1]) {
                score = dp[i-1][j-1]+8;
            }
            else {
                score = dp[i-1][j-1]-5;
            }
            int gap_top = dp[i-1][j]-3;
            int gap_left = dp[i][j-1]-3;
            dp[i][j] = max(max(0,score),max(gap_left,gap_top));
            max_ans = max(dp[i][j],max_ans);
        }
    }
    cout << max_ans;
}
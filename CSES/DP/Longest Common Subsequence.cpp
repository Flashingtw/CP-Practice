#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> v1(n);
    vector<int> v2(m);
    for (int i=0;i<n;i++) cin>>v1[i];
    for (int i=0;i<m;i++) cin>>v2[i];
    //dp initialize , ALL ZERO!
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //dp
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            //same
            if (v1[i-1]==v2[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;//add
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << "\n";
    //backtracking
    int i=n,j=m;
    vector<int> v;
    while (i>0&&j>0) {
        // choosing this
        if (v1[i-1] == v2[j-1]) {
            v.push_back(v1[i-1]);
            i--;
            j--;
        }
        //because > so the i-- will bigger than j--
        else if (dp[i-1][j]>dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    reverse(v.begin(),v.end());
    for (int num : v) {
        cout << num << " ";
    }
}
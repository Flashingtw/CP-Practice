#include <bits/stdc++.h>
using namespace std;
int n;
const int INF = 1e9+9;
vector<int> val;
int main(){
    cin>>n;
    val.resize(n);
    for(int i=0;i<n;i++) cin>>val[i];
    vector<vector<int>> dp(n,vector<int>(n,INF));
    for(int i=0;i<n;i++) dp[i][i]=0;
    for(int i = 0; i < n - 1; i++) dp[i][i+1] = 0;
    
    for(int len=3;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j = i+len-1;
            for(int k=i+1;k<i+len-1;k++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+val[i]*val[k]*val[j]);
            }
        }
    }
    cout << dp[0][n-1];
}
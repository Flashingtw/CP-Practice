#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,L;
    cin>>n>>L;
    vector<int> P(n+2);
    for (int i=1;i<=n;i++) cin>>P[i];
    P[0] = 0;
    P[n+1] = L;
    n+=2;

    vector<vector<int>> dp(n,vector<int>(n,0));
    //dp[i][j]為i->j切割所需最小花費`
    for (int len=2;len<n;len++) {//枚舉長度
        for (int i=0;i+len<n;i++) {//枚舉左邊
            int j = i+len,Mcost = 1e9;//右邊
            for (int k=i+1;k<j;k++) {//枚舉每個點
                Mcost = min(Mcost,dp[i][k]+dp[k][j]);
            }
            dp[i][j] = Mcost + P[j]-P[i];
        }
    }
    cout << dp[0][n-1];//第0個點到第n-1個點(長度L)的最小切割
}
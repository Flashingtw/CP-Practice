#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(n+1);
    for (int i=0;i<n+1;i++) cin>>v[i];
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for (int len = 2; len <= n; len++) {//枚舉長度
        for (int i = 1; i <= n - len + 1; i++) { //枚舉起點i確保終點j不超過n
            int j = i + len - 1;//計算終點 j
            dp[i][j] = 1e9;
            for (int k = i; k < j; k++) {//枚舉切割點 k：從 i 到 j-1
                // 轉移方程式：左邊成本 + 右邊成本 + 合併成本
                // v[i-1] 是左矩陣的列數, v[k] 是共同邊, v[j] 是右矩陣的行數
                int cost = dp[i][k]+dp[k+1][j]+v[i-1]*v[k]*v[j];
                if (cost < dp[i][j]) dp[i][j] = cost;
            }
        }
    }
    cout << dp[1][n] << endl;
}
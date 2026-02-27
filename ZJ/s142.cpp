#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int h,w;
    cin>>h>>w;
    vector<vector<int>> grid(h,vector<int>(w));
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++){
            cin>>grid[i][j];
        }
    }
    vector<int> dp(h),temp(h,0);
    int ans=0;
    for(int i=0;i<h;i++){
        dp[0]=grid[i][0]==1;
        for(int j=1;j<w;j++){
            if(!grid[i][j]) {
                dp[j]=0;
                continue;
            }
            dp[j] = min({temp[j-1],temp[j],dp[j-1]})+1;
            ans = max(ans,dp[j]);
        }
        swap(dp,temp);
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
vector<vector<double>> dp(2005,vector<double>(2005,1e15));
vector<pair<int,int>> pos(2005);
double dist(int i,int j){
    auto [x1,y1] = pos[i];
    auto [x2,y2] = pos[j];
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>pos[i].first>>pos[i].second;
    dp[0][0]=0;
    dp[1][0]=dist(1,0);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(dp[i][j]==1e15) continue;
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+dist(i,i+1));
            dp[i+1][i]=min(dp[i+1][i],dp[i][j]+dist(j,i+1));
        }
    }
    double ans=dp[n-1][0]+dist(0,n-1);
    for(int i=1;i<n;i++){
        ans = min(ans,dp[n-1][i]+dist(i,n-1));
    }
    cout << fixed << setprecision(2) << ans;
}
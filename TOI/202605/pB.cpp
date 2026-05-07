#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,p,r;
    cin>>n>>p>>r;
    vector<int> dp(p+1,-1);
    dp[0]=0;
    for(int count=0;count<n;count++){
        int m;
        cin>>m;
        vector<vector<int>> tmp(r+1,vector<int>(p+1,-1));
        for(int i=0;i<=p;i++) tmp[0][i] = dp[i];
        for(int i=0;i<m;i++) {
            int c,d;
            cin>>c>>d;
            for(int k=r;k>=1;k--){
                for(int cst=p;cst>=c;cst--){
                    if(tmp[k-1][cst-c]!=-1){
                        tmp[k][cst] = max(tmp[k][cst],tmp[k-1][cst-c]+d);
                    }
                }
            }
        }
        for(int k=1;k<=r;k++){
            for(int cst=1;cst<=p;cst++){
                if(tmp[k][cst]!=-1){
                    dp[cst] = max(dp[cst],tmp[k][cst]);
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=p;i++) ans = max(ans,dp[i]);
    cout << ans << '\n';
}
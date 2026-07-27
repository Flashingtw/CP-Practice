#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n,m,k,d;
int grid[1005][1005];
bool chk(int tar){
    vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));
    for(int i=0;i<n;i++) dp[i][0]=(grid[i][0]<tar?1:0);
    for(int j=1;j<m;j++){
        deque<int> dq;
        for(int i=0;i<=min(d,n-1);i++) {
            while(!dq.empty()&&dp[dq.back()][j-1]>dp[i][j-1]) dq.pop_back();
            dq.push_back(i);
        }
        for(int i=0;i<n;i++){
            dp[i][j] = min(dp[i][j],dp[dq.front()][j-1]+(grid[i][j]<tar?1:0));
            
            while(!dq.empty()&&dq.front()<i-d+1) dq.pop_front();
            if(i+d+1<n){
                while(!dq.empty()&&dp[dq.back()][j-1]>dp[i+d+1][j-1]) dq.pop_back();
                dq.push_back(i+d+1);
            }
        }
    }
    for(int i=0;i<n;i++) if(dp[i][m-1]<=k) return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>k>>d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int l=0,r=1e9,ans=0;
    while(l<=r){
        int mid = (l+r)/2;
        if(chk(mid)){
            l = mid+1;
            ans = mid;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans << '\n';
}
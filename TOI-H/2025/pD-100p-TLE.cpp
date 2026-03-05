#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
char grid[4005][4005];
int dp[2][4005][26];
ll diff[4005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=m;j++){
            grid[i][j]=s[j-1];
        }
    }
    for(int j=0; j<=m; j++){
        for(int k=0; k<26; k++){
            dp[0][j][k] = 1000000;
        }
    }
    int q;
    cin>>q;
    for(int i=1;i<=n;i++){
        int cur=i&1;
        int pre=1-cur;
        for(int j=0;j<26;j++) dp[cur][0][j] = 1000000;
        
        for(int j=1;j<=m;j++){
            int lmt = min(i,j);
            int v0 = 1e9;
            int v1 = 1e9;
            int v2 = 1e9;
            int c = grid[i][j]-'A';
            for(int k=0;k<26;k++){
                dp[cur][j][k] = min(dp[cur][j-1][k],dp[pre][j][k])+1;
                if(k==c) dp[cur][j][k] =0;
                int val = dp[cur][j][k];
                if(val < v0){
                    v2 = v1; v1 = v0; v0 = val;
                } else if(val < v1){
                    v2 = v1; v1 = val;
                } else if(val < v2){
                    v2 = val;
                }
            }
            
            if(q==1){
                int R = min(lmt,v1);
                if(1<=R){
                    diff[R+1]--;
                    diff[1]++;
                }
            }
            else{
                int L = v1+1;
                int R = min(lmt,v2);
                if(L<=R){
                    diff[L]++;
                    diff[R+1]--;
                }
            }
        }
    }
    int mx=0;
    for(int i=1;i<=min(m,n);i++){
        diff[i] += diff[i-1];
        if(diff[i]>0){
            mx=i;
        }
    }
    cout << mx << '\n';
    if(mx==0){
        cout << '\n';
    }
    else{
        for(int i=1;i<=mx;i++){
            cout << diff[i] << ' ';
        }
    }
}
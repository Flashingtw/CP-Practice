#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[305][305],score[305][305],ans[305][305];
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++){
        dp[i][i]=v[i];
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            for(int k=i;k<j;k++){
                ans[i][j] = max(ans[i][j],ans[i][k]+ans[k+1][j]);
                if(dp[i][k]>0&&dp[i][k]==dp[k+1][j]){
                    int next_lv=dp[i][k]+1;
                    ll cur=score[i][k]+score[k+1][j]+next_lv;
                    if(next_lv>dp[i][j]){
                        dp[i][j]=next_lv;
                        score[i][j]=cur;
                    }
                    else if(next_lv==dp[i][j]){
                        score[i][j]=max(score[i][j],cur);
                    }
                    ans[i][j]=max(ans[i][j],score[i][j]);
                }
            }
        }
    }
    cout << ans[0][n-1];
}
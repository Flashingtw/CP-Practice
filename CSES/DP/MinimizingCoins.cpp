#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> S(n),dp(x+1,1e7);
    dp[0]=0;
    for(int i=0;i<n;i++){
        cin>>S[i];
    }
    for(int i=1;i<=x;i++){
        for(int j:S){
            if(i-j<0) continue;
            dp[i]=min(dp[i],dp[i-j]+1);
        }
    }
    if(dp[x]==1e7) cout<<-1<<endl;
    else cout<<dp[x]<<endl;
    return 0;
}
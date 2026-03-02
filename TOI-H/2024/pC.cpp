#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,e;
    cin>>n>>k>>e;
    vector<int> step(k,0);
    vector<bool> hole(e+1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        hole[x]=1;
    }
    vector<vector<int>> dp(e+1); 
    for(int i=0;i<=e;i++){
        if(!hole[i]) dp[i]=step;
    }
    for(int i=0;i<k;i++) cin>>step[i];
    sort(step.begin(),step.end(),greater());
    vector<int> prev(e+1,-1);
    prev[0]=-2;
    for(int i=0;i<=e;i++){
        if(hole[i]||prev[i]==-1) continue;
        for(int j=0;j<k;j++){
            int next=i+step[j];
            if(next>e) continue;
            if(hole[next]) continue;
            dp[i][j]++;
            if(dp[i]>dp[next]){
                dp[next]=dp[i];
                prev[next]=i;
            }
            dp[i][j]--;
        }
    }
    if(prev[e]==-1) cout << -1;
    else{
        vector<int> ans;
        int cur=e;
        while(cur>0){
            ans.push_back(cur);
            cur=prev[cur];
        }
        cout << ans.size() << '\n';
        for(int i=ans.size()-1;i>=0;i--){
            cout << ans[i] << ' ';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct gr{
    int c;
    int p;
};
int main(){
    int n,k;
    cin>>n>>k;
    vector<gr> v[105];
    for(int i=0;i<n;i++){
        int c,p,id;
        cin>>c>>p>>id;
        v[id].push_back({c,p});
    }
    vector<int> dp(1005,0);
    dp[0]=0;
    for(int group=1;group<=100;group++){
        if(v[group].empty()) continue;
        vector<vector<int>> temp_dp(1005,vector<int>(3,0));
        for(int las=0;las<=k;las++) temp_dp[las][0]=dp[las];
        for(gr g:v[group]){
            int c= g.c;
            int p= g.p;
            for(int cost=k;cost>=c;cost--){
                if(temp_dp[cost-c][1]!=-INF){
                    temp_dp[cost][2] = max(temp_dp[cost][2],temp_dp[cost-c][1]+p);//選一個->選兩個
                }
                if(temp_dp[cost-c][0]!=-INF){
                    temp_dp[cost][1] = max(temp_dp[cost][1],temp_dp[cost-c][0]+p);//沒選->選一
                }
            }
        }
        for(int t=0;t<=k;t++){
            dp[t]= max({dp[t],temp_dp[t][1],temp_dp[t][2]});
        }
    }
    cout << dp[k];
}
